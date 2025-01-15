package org.ioopm.calculator.ast;

import java.util.Objects;

public class Exp extends Unary{
    public Exp(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public String getName() {
        return "exp";
    }

    public boolean equals(Object other) {
        if (other instanceof Exp) {
            return this.equals((Exp) other);
        } else {
            return false;
        }
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    public boolean equals(Exp other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }
}
