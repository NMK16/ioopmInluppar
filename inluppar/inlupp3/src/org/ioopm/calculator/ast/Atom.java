package org.ioopm.calculator.ast;

public abstract class Atom extends SymbolicExpression{
    public abstract double evaluate();
    public abstract String toString();
}
