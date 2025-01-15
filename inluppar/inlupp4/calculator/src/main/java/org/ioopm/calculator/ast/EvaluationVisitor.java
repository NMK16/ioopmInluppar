package org.ioopm.calculator.ast;

public class EvaluationVisitor implements Visitor {
    private Environment env = null;
    private ScopeHandler scopeHandler = null;

    public SymbolicExpression evaluate(SymbolicExpression topLevel, Environment env) {
        this.env = env;
        this.scopeHandler = new ScopeHandler();
        this.scopeHandler.pushEnvironment(env);
        return topLevel.accept(this);
    }

    // This method gets called from Addition.accept(Visitor v) -- you should
    // be able to see from the eval() methods how these should behave (i.e.,
    // compare this method with your Addition::eval() and Symbolic.addition)
    public SymbolicExpression visit(Addition n) {
        // Visit the left hand side and right hand side subexpressions
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs().accept(this);
        // When we come back here, the visitor has visited all subexpressions,
        // meaning left and right point to newly created trees reduced to
        // the extent possible (best case -- both are constants)

        // If subexpressions are fully evaluated, replace them in
        // the tree with a constant whose value is the sub of the
        // subexpressions, if not, simply construct a new addition
        // node from the new subexpressions
        if (left.isConstant() && right.isConstant()) {
            return new Constant(left.getValue() + right.getValue());
        } else {
            return new Addition(left, right);
        }
    }

    @Override
    public SymbolicExpression visit(Assignment n) {
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs();

        if(right == null){
            throw new IllegalAssignmentException("Error: cannot assign value to \"null\"");
        }
        if(left == null){
            this.scopeHandler.getEnvironmentStack().peek().remove((Variable) right);
            return left;
        }
        this.scopeHandler.getEnvironmentStack().peek().put((Variable) right, left);
        return left;
    }

    @Override
    public SymbolicExpression visit(Clear n) {
        return n.accept(this);
    }

    @Override
    public SymbolicExpression visit(Constant n) {
        return new Constant(n.getValue());
    }

    @Override
    public SymbolicExpression visit(Cos n) {
        SymbolicExpression operand = n.getOperand().accept(this);
        if(operand.isConstant()){
            return new Constant(Math.cos(operand.getValue()));
        }
        return new Cos(operand);
    }

    @Override
    public SymbolicExpression visit(Division n) {
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs().accept(this);

        if(left.isConstant() && right.isConstant()){
            return new Constant(left.getValue() / right.getValue());
        }
        return new Division(left, right);
    }

    @Override
    public SymbolicExpression visit(Exp n) {
        SymbolicExpression operand = n.getOperand().accept(this);

        if(operand.isConstant()){
            return new Constant(Math.exp(operand.getValue()));
        }
        return new Exp(operand);
    }

    @Override
    public SymbolicExpression visit(Log n) {
        SymbolicExpression operand = n.getOperand().accept(this);

        if(operand.isConstant()){
            return new Constant(Math.log10(operand.getValue()));
        }
        return new Log(operand);
    }

    @Override
    public SymbolicExpression visit(Multiplication n) {
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs().accept(this);

        if(left.isConstant() && right.isConstant()){
            return new Constant(left.getValue() * right.getValue());
        }
        return new Multiplication(left, right);
    }

    @Override
    public SymbolicExpression visit(Negation n) {
        SymbolicExpression operand = n.getOperand().accept(this);

        if(operand.isConstant()){
            return new Constant(-1*operand.getValue());
        }
        return new Negation(operand);
    }

    @Override
    public SymbolicExpression visit(Quit n) {
        return n.accept(this);
    }

    @Override
    public SymbolicExpression visit(Sin n) {
        SymbolicExpression operand = n.getOperand().accept(this);
        if(operand.isConstant()){
            return new Constant(Math.sin(operand.getValue()));
        }
        return new Sin(operand);
    }

    @Override
    public SymbolicExpression visit(Subtraction n) {
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs().accept(this);

        if(left.isConstant() && right.isConstant()){
            return new Constant(left.getValue() - right.getValue());
        }
        return new Subtraction(left, right);
    }

    @Override
    public SymbolicExpression visit(Variable n) {
        String identifier = n.getIdentifier();
        // Check if the identifier exists in the namedConstants map
        if (Constants.namedConstants.containsKey(identifier)) {
            return new Constant(Constants.namedConstants.get(identifier));
        }

        // Fallback: check the environment
        Variable variable = new Variable(identifier);
        if (this.scopeHandler.getEnvironmentStack().peek().containsKey(variable)) {
            return this.scopeHandler.getEnvironmentStack().peek().get(variable);
        }

        return variable;
    }


    @Override
    public SymbolicExpression visit(Vars n) {
        return n.accept(this);
    }

    @Override
    public SymbolicExpression visit(Scope n) {
        SymbolicExpression body = n.getBody();
        ScopeHandler scopeHandler = new ScopeHandler();

        scopeHandler.pushEnvironment(this.env);

        SymbolicExpression result = body.accept(this);
        scopeHandler.popEnvironment();
        return result;
    }

    @Override
    public SymbolicExpression visit(Conditional n) {
        SymbolicExpression left = n.getLhs().accept(this);
        SymbolicExpression right = n.getRhs().accept(this);
        String operator = n.getOperator();
        SymbolicExpression trueBranch = n.getTrueBranch();
        SymbolicExpression falseBranch = n.getFalseBranch();

        if (!left.isConstant() || !right.isConstant()) {
            throw new RuntimeException("Condition must compare constants");
        }

        double lhsValue = left.getValue();
        double rhsValue = right.getValue();
        boolean conditionResult;

        switch (operator) {
            case "<":
                conditionResult = lhsValue < rhsValue;
                break;
            case ">":
                conditionResult = lhsValue > rhsValue;
                break;
            case "<=":
                conditionResult = lhsValue <= rhsValue;
                break;
            case ">=":
                conditionResult = lhsValue >= rhsValue;
                break;
            case "==":
                conditionResult = lhsValue == rhsValue;
                break;
            default:
                throw new RuntimeException("Unsupported operator in condition: " + operator);
        }

        if (conditionResult) {
            return trueBranch.accept(this);
        } else {
            return falseBranch.accept(this);
        }    }

}