package org.ioopm.calculator.ast;

public class Variable extends Atom {
    private String identifier;
    public Variable(String identifier){
        this.identifier = identifier;
    }

    @Override
    public double evaluate() {
        throw new UnsupportedOperationException("Variable evaluation requires a context.");
    }

    @Override
    public String toString() {
        return this.identifier;
    }
}
