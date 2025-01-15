package org.ioopm.calculator.ast;

import java.util.Objects;

public class Multiplication extends Binary{
    public Multiplication(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    public String toString() {
        return super.toString();
    }

    @Override
    public String getName() {
        return "*";
    }

    @Override
    public int getPriority(){
        return 100;
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    public boolean equals(Object other) {
        if (other instanceof Multiplication) {
            return this.equals((Multiplication) other);
        } else {
            return false;
        }
    }

    public boolean equals(Multiplication other) {
        // access a private field of other!
        return (this.getLhs().equals(other.getLhs()) || this.getLhs().equals(other.getRhs())) && (this.getRhs().equals(other.getRhs()) || this.getRhs().equals(other.getLhs())) && Objects.equals(this.getName(), other.getName());
    }
}
