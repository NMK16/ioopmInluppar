package org.ioopm.calculator.ast;

public class Negation extends Unary{
    public Negation(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public double evaluate() {
        return (this.getOperand().evaluate() * -1);
    }
    @Override
    public String toString() {
        return "-(" + this.getOperand().evaluate() + ")";
    }
}
