package org.ioopm.calculator.ast;

import java.util.Objects;

public class Sin extends Unary{
    public Sin(SymbolicExpression operand) {
        super(operand);
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public String getName() {
        return "sin";
    }
    public boolean equals(Object other) {
        if (other instanceof Sin) {
            return this.equals((Sin) other);
        } else {
            return false;
        }
    }

    public boolean equals(Sin other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }
}
