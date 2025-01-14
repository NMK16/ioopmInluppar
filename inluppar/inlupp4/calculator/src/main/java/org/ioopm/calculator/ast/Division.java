package org.ioopm.calculator.ast;

import java.util.Objects;

public class Division extends Binary{
    public Division(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public SymbolicExpression eval(Environment vars){
        if(this.getLhs().eval(vars).isConstant() && this.getRhs().eval(vars).isConstant()){
            return new Constant(this.getLhs().eval(vars).getValue() / this.getRhs().eval(vars).getValue());
        }
        return new Division(this.getLhs().eval(vars), this.getRhs().eval(vars));
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
        return super.toString();
    }

    public boolean equals(Object other) {
        if (other instanceof Division) {
            return this.equals((Division) other);
        } else {
            return false;
        }
    }

    public boolean equals(Division other) {
        // access a private field of other!
        return this.getLhs().equals(other.getLhs()) && this.getRhs().equals(other.getRhs()) && Objects.equals(this.getName(), other.getName());
    }
}

