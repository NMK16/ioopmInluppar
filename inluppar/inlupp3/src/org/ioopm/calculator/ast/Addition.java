package org.ioopm.calculator.ast;

public class Addition extends Binary{
    public Addition(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    public String toString() {
        return super.toString();
    }

    @Override
    public String getName() {
        return "+";
    }

    @Override
    public int getPriority(){
        return 50;
    }
}
