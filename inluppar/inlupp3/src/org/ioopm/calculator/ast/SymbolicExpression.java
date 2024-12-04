package org.ioopm.calculator.ast;

public abstract class SymbolicExpression {
    public abstract double evaluate();
    @Override
    public abstract String toString();
}
