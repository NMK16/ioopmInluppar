package org.ioopm.calculator.ast;

public abstract class Atom extends SymbolicExpression{
    private SymbolicExpression atom;

    public SymbolicExpression getAtom() {
        return this.atom;
    }
}