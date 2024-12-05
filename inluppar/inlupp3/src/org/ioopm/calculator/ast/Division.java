package org.ioopm.calculator.ast;

public class Division extends Binary{
    public Division(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public String getName() {
        return "/";
    }

    @Override
    public int getPriority(){
        return 100;
    }

    public String toString() {
        return this.getLhs().toString() + " " + this.getName() + " " + this.getRhs().toString();
    }
}
