package org.ioopm.calculator.ast;

import java.util.Objects;

public class Cos extends Unary{
    public Cos(SymbolicExpression operand) {
        super(operand);
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public String getName() {
        return "cos";
    }

    public boolean equals(Object other) {
        if (other instanceof Cos) {
            return this.equals((Cos) other);
        } else {
            return false;
        }
    }

    public boolean equals(Cos other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }
}
