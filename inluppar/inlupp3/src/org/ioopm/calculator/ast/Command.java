package org.ioopm.calculator.ast;

public abstract class Command extends SymbolicExpression{
    @Override
    public double evaluate() {
        throw new UnsupportedOperationException("Commands cannot be evaluated numerically.");
    }

    @Override
    public abstract String toString();
}
