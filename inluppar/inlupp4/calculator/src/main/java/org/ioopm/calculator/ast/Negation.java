package org.ioopm.calculator.ast;

import java.util.Objects;

public class Negation extends Unary{
    public Negation(SymbolicExpression operand){
        super(operand);
    }
    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public SymbolicExpression eval(Environment vars){
        if(this.getOperand().eval(vars).isConstant()){
            return new Constant(-1*this.getOperand().eval(vars).getValue());
        }
        return new Negation(this.getOperand().eval(vars));
    }

    @Override
    public String getName() {
        return "-";
    }

    public boolean equals(Object other) {
        if (other instanceof Negation) {
            return this.equals((Negation) other);
        } else {
            return false;
        }
    }

    public boolean equals(Negation other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }

}
