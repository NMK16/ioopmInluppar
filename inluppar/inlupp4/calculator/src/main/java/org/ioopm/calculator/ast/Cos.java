package org.ioopm.calculator.ast;

import java.util.Objects;

public class Cos extends Unary{
    public Cos(SymbolicExpression operand) {
        super(operand);
    }

    @Override
    public SymbolicExpression eval(Environment vars){
        if(this.getOperand().eval(vars).isConstant()){
            return new Constant(Math.cos(this.getOperand().eval(vars).getValue()));
        }
        return new Cos(this.getOperand().eval(vars));
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
        return this.getOperand() == other.getOperand() && Objects.equals(this.getName(), other.getName());
    }
}
