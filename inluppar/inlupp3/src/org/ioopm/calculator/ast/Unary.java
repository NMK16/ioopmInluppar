package org.ioopm.calculator.ast;

public abstract class Unary extends SymbolicExpression{
    private SymbolicExpression operand;
    public Unary(SymbolicExpression operand){
        this.operand = operand;
    }

    public SymbolicExpression getOperand(){
        return this.operand;
    }

    public String toString() {
        // Note how the call to toString() is not necessary
        return this.getName() + " " + this.operand.toString();
    }

    @Override
    public int getPriority() {
        return 200; // Highest priority for unary operators
    }


}
