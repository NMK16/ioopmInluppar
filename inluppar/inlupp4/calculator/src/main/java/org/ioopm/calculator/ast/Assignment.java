package org.ioopm.calculator.ast;

public class Assignment extends Binary{
    public Assignment(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }
    @Override
    public String getName() {
        return "=";
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    public boolean equals(Object other) {
        if (other instanceof Assignment) {
            return this.equals((Assignment) other);
        } else {
            return false;
        }
    }

    public boolean equals(Assignment other) {
        // access a private field of other!
        return (this.getLhs().equals(other.getLhs()) && this.getRhs().equals(other.getRhs()) && this.getName().equals(other.getName()));
    }

}
