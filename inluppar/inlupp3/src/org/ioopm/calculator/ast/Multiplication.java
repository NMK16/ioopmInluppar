package org.ioopm.calculator.ast;

public class Multiplication extends Binary{
    public Multiplication(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public double evaluate() {
        return (this.getLhs().evaluate() * this.getRhs().evaluate());
    }

    @Override
    public String toString() {
        return "(" + this.getLhs().evaluate() + " * " + this.getRhs().evaluate() + ")";
    }
}
