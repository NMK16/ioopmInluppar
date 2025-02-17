package org.ioopm.calculator.ast;

import java.util.ArrayList;
import java.util.List;

public class EvaluationVisitor implements Visitor {
    private Environment env = null;
    private ScopeHandler scopeHandler = new ScopeHandler();

    public SymbolicExpression evaluate(SymbolicExpression topLevel, Environment env) {
        this.env = env;
        scopeHandler.pushEnvironment(env);
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
        // subexpressions, if not, simply    construct a new addition
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

        if (right == null) {
            throw new IllegalAssignmentException("Error: cannot assign value to \"null\"");
        }
        if (left == null) {
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
        
        // Check named constants first
        if (Constants.namedConstants.containsKey(identifier)) {
            return new Constant(Constants.namedConstants.get(identifier));
        }

        // Check current environment
        Environment currentEnv = this.scopeHandler.getEnvironmentStack().peek();
        if (currentEnv.containsKey(n)) {
            return currentEnv.get(n);
        }

        // If not found, return the variable itself
        return n;
    }



    @Override
    public SymbolicExpression visit(Vars n) {
        return n.accept(this);
    }

    @Override
    public SymbolicExpression visit(Scope n) {
        // Create a new environment for this scope, inheriting from the current one
        Environment newEnv = new Environment();
        newEnv.putAll(this.scopeHandler.getEnvironmentStack().peek());  // Copy current environment

        // Push the new environment
        this.scopeHandler.pushEnvironment(newEnv);

        // Evaluate the body in the new scope
        SymbolicExpression result = n.getBody().accept(this);

        // Pop the environment before returning
        this.scopeHandler.popEnvironment();

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

        @Override
        public SymbolicExpression visit(FunctionCall n) {
            String functionName = n.getName();
            Variable functionVar = new Variable(functionName);
            Environment currentEnv = this.scopeHandler.getEnvironmentStack().peek();

            // Check if function exists
            if (!currentEnv.containsKey(functionVar)) {
                throw new RuntimeException("Function '" + functionName + "' is not defined");
            }

            SymbolicExpression functionExpr = currentEnv.get(functionVar);
            if (!(functionExpr instanceof FunctionDeclaration)) {
                throw new RuntimeException("'" + functionName + "' is not a callable function");
            }

            FunctionDeclaration function = (FunctionDeclaration) functionExpr;
            List<String> parameters = function.getParameters();
            List<SymbolicExpression> arguments = n.getArguments();

            // Check argument count
            if (parameters.size() != arguments.size()) {
                throw new RuntimeException("Function '" + functionName + "' expects " + 
                    parameters.size() + " arguments, but got " + arguments.size());
            }

            // Create new scope for function execution
            Environment functionEnv = new Environment();
            
            // First bind the arguments to parameters
            for (int i = 0; i < parameters.size(); i++) {
                SymbolicExpression argValue = arguments.get(i).accept(this);  // Evaluate argument first
                Variable paramVar = new Variable(parameters.get(i));  // Create Variable object from parameter name
                functionEnv.put(paramVar, argValue);  // Now putting Variable object, not String
            }

            // Then copy the rest of the environment
            for (Variable var : currentEnv.keySet()) {
                if (!functionEnv.containsKey(var)) {
                    functionEnv.put(var, currentEnv.get(var));
                }
            }

            // Push function scope
            this.scopeHandler.pushEnvironment(functionEnv);
            
            try {
                // Evaluate body in function scope
                return function.getBody().accept(this);
            } finally {
                // Pop function scope
                this.scopeHandler.popEnvironment();
            }
        }
        

        @Override
    public SymbolicExpression visit(FunctionDeclaration n) {
        Variable functionName = new Variable(n.getName());
        this.scopeHandler.getEnvironmentStack().peek().put(functionName, n);
        return n;
    }

}