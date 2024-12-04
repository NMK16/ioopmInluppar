package org.ioopm.calculator.ast;

public class Exp extends Unary{
    public Exp(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public double evaluate() {
        return Math.exp(this.getOperand().evaluate());
    }
}
