package org.ioopm.calculator.ast;

public abstract class Unary extends SymbolicExpression{
    private SymbolicExpression operand;
    public Unary(SymbolicExpression operand){
        this.operand = operand;
    }

    public SymbolicExpression getOperand(){
        return this.operand;
    }
    public abstract double evaluate();
}
