package org.ioopm.calculator.ast;

import java.util.Objects;

public class Subtraction extends Binary{
    public Subtraction(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
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
        return super.toString();
    }
    public boolean equals(Object other) {
        if (other instanceof Subtraction) {
            return this.equals((Subtraction) other);
        } else {
            return false;
        }
    }

    public boolean equals(Subtraction other) {
        // access a private field of other!
        return this.getLhs().equals(other.getLhs()) && this.getRhs().equals(other.getRhs()) && Objects.equals(this.getName(), other.getName());
    }
}
