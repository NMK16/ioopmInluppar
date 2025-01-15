package org.ioopm.calculator.ast;

import java.util.Objects;

public class Variable extends Atom implements Comparable<Variable> {
    private String identifier;
    public Variable(String identifier){
        this.identifier = identifier;
    }
    
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    public String getIdentifier() {
        return identifier;
    }

    public String toString() {
        return this.identifier;
    }

    public boolean equals(Object other) {
        if (other instanceof Variable) {
            return this.equals((Variable) other);
        } else {
            return false;
        }
    }

    public boolean equals(Variable other) {
        // access a private field of other!
        return Objects.equals(this.identifier, other.identifier);
    }

    @Override
    public int hashCode(){
        return this.identifier.hashCode();
    }

    @Override
    public int compareTo(Variable other) {
        // Compare identifiers alphabetically
        return this.identifier.compareTo(other.identifier);
    }
}
