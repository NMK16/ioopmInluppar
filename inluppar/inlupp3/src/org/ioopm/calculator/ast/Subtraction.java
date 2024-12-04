package org.ioopm.calculator.ast;

public class Subtraction extends Binary{
    public Subtraction(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public double evaluate() {
        return (this.getLhs().evaluate() - this.getRhs().evaluate());
    }

    @Override
    public String toString() {
        return "(" + this.getLhs().evaluate() + " - " + this.getRhs().evaluate() + ")";
    }
}
