package org.ioopm.calculator.ast;

public class Addition extends Binary{
    public Addition(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
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
    public boolean equals(Object other) {
        if (other instanceof Addition) {
            return this.equals((Addition) other);
        } else {
            return false;
        }
    }

    public boolean equals(Addition other) {
        // access a private field of other!
        return (this.getLhs().equals(other.getLhs()) || this.getLhs().equals(other.getRhs()) && (this.getRhs().equals(other.getRhs()) || this.getRhs().equals(other.getLhs())) && this.getName().equals(other.getName()));    }
}
