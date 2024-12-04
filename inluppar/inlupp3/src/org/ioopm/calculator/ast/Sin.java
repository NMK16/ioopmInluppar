package org.ioopm.calculator.ast;

public class Sin extends Unary{
    public Sin(SymbolicExpression operand) {
        super(operand);
    }

    public double evaluate() {
        return Math.sin(this.getOperand().evaluate());
    }
}
