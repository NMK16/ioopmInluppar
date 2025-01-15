package org.ioopm.calculator.ast;

import java.util.Objects;

public class Log extends Unary{
    public Log(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public String getName() {
        return "log";
    }
    
    public boolean equals(Object other) {
        if (other instanceof Log) {
            return this.equals((Log) other);
        } else {
            return false;
        }
    }

    public boolean equals(Log other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }
}
