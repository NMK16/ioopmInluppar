package org.ioopm.calculator.ast;

import java.util.Objects;

public abstract class Unary extends SymbolicExpression{
    private SymbolicExpression operand;
    public Unary(SymbolicExpression operand){
        this.operand = operand;
    }

    public SymbolicExpression getOperand(){
        return this.operand;
    }

    public String toString() {
        String operandString = this.getOperand().toString();
        if(this.getOperand().isConstant() && this.getOperand().getValue() == (int)this.getOperand().getValue()){
            operandString = String.valueOf((int)this.getOperand().getValue());
        }
        return this.getName() + "(" + operandString + ")";
    }

    @Override
    public int getPriority() {
        return 200;
    }

    public boolean equals(Object other) {
        if (other instanceof Unary) {
            return this.equals((Unary) other);
        } else {
            return false;
        }
    }

    public boolean equals(Unary other) {
        // access a private field of other!
        return this.operand == other.operand && Objects.equals(this.getName(), other.getName());
    }

}
