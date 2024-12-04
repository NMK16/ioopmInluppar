package org.ioopm.calculator.ast;

public abstract class Binary extends SymbolicExpression{
    private SymbolicExpression lhs = null;
    private SymbolicExpression rhs = null;

    public Binary(SymbolicExpression lhs, SymbolicExpression rhs) {
        this.lhs = lhs;
        this.rhs = rhs;
    }

    public SymbolicExpression getLhs() {
        return this.lhs;
    }

    public SymbolicExpression getRhs() {
        return this.rhs;
    }

    public abstract double evaluate();

}
