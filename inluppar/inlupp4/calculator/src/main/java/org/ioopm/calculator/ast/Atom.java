package org.ioopm.calculator.ast;

public abstract class Atom extends SymbolicExpression{
    private SymbolicExpression atom;

    public SymbolicExpression getAtom() {
        return this.atom;
    }


    public boolean equals(Object other) {
        if (other instanceof Atom) {
            return this.equals((Atom) other);
        } else {
            return false;
        }
    }

    public boolean equals(Atom other) {
        // access a private field of other!
        return (this.getAtom().equals(other.getAtom()) && this.getName().equals(other.getName()));
    }
}

