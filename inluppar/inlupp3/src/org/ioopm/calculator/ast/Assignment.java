package org.ioopm.calculator.ast;

public class Assignment extends Binary{
    public Assignment(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }
    @Override
    public double evaluate() {
        if (!(this.getLhs() instanceof Variable)) {
            throw new IllegalArgumentException("Left-hand side of an assignment must be a variable.");
        }

        double value = this.getRhs().evaluate();

        return value;
    }

    public String toString() {
        return this.getLhs().toString() + " = " + this.getRhs().evaluate();
    }
}
