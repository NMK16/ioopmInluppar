package org.ioopm.calculator.ast;

public class Conditional extends SymbolicExpression {
    private SymbolicExpression lhs;
    private SymbolicExpression rhs;
    private String operator;
    private SymbolicExpression trueBranch;
    private SymbolicExpression falseBranch;

    public Conditional(SymbolicExpression lhs, String operator, SymbolicExpression rhs,
                       SymbolicExpression trueBranch, SymbolicExpression falseBranch) {
        this.lhs = lhs;
        this.operator = operator;
        this.rhs = rhs;
        this.trueBranch = trueBranch;
        this.falseBranch = falseBranch;
    }

    public SymbolicExpression getLhs() {
        return lhs;
    }

    public SymbolicExpression getRhs() {
        return rhs;
    }

    public String getOperator() {
        return operator;
    }

    public SymbolicExpression getTrueBranch() {
        return trueBranch;
    }

    public SymbolicExpression getFalseBranch() {
        return falseBranch;
    }

    @Override
    public SymbolicExpression eval(Environment vars) {
        SymbolicExpression lhsEval = lhs.eval(vars);
        SymbolicExpression rhsEval = rhs.eval(vars);

        if (!lhsEval.isConstant() || !rhsEval.isConstant()) {
            throw new RuntimeException("Condition must compare constants");
        }

        double lhsValue = lhsEval.getValue();
        double rhsValue = rhsEval.getValue();
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
            return trueBranch.eval(vars);
        } else {
            return falseBranch.eval(vars);
        }
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    @Override
    public String toString() {
        return "if (" + lhs + " " + operator + " " + rhs + ") { " + trueBranch + " } else { " + falseBranch + " }";
    }
}