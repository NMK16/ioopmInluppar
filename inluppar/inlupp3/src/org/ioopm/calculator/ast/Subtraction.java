package org.ioopm.calculator.ast;

public class Subtraction extends Binary{
    public Subtraction(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public String getName() {
        return "-";
    }

    @Override
    public int getPriority(){
        return 50;
    }

    public String toString() {
        return this.getLhs().toString() + " " + this.getName() + " " + this.getRhs().toString();
    }

}
