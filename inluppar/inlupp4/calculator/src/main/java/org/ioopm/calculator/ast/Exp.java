package org.ioopm.calculator.ast;

import java.util.Objects;

public class Exp extends Unary{
    public Exp(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public SymbolicExpression eval(Environment vars){
        if(this.getOperand().eval(vars).isConstant()){
            return new Constant(Math.exp(this.getOperand().eval(vars).getValue()));
        }
        return new Exp(this.getOperand().eval(vars));
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

    public boolean equals(Exp other) {
        // access a private field of other!
        return this.getOperand().equals(other.getOperand()) && Objects.equals(this.getName(), other.getName());
    }
}
