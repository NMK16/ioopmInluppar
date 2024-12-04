package org.ioopm.calculator.ast;

public class Cos extends Unary{
    public Cos(SymbolicExpression operand) {
        super(operand);
    }

    public double evaluate() {
        return Math.cos(this.getOperand().evaluate());
    }

    @Override
    public String toString() {
        return "";
    }
}
