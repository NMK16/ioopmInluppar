package org.ioopm.calculator.ast;

public class Variable extends SymbolicExpression {
    private final String identifier;

    public Variable(String identifier) {
        super();
        if (identifier == null) {
            throw new IllegalArgumentException("Variable identifier cannot be null");
        }
        this.identifier = identifier;
    }

    public String getIdentifier() {
        return this.identifier;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof Variable) {
            return this.identifier.equals(((Variable) other).identifier);
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return this.identifier.hashCode();
    }

    @Override
    public String toString() {
        return this.identifier;
    }

    @Override
    public boolean isConstant() {
        return false;
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
}
