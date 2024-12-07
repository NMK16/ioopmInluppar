package org.ioopm.calculator.ast;

import java.util.HashMap;

public class Multiplication extends Binary{
    public Multiplication(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }

    @Override
    public SymbolicExpression eval(Environment vars){
        if(this.getLhs().eval(vars).isConstant() && this.getRhs().eval(vars).isConstant()){
            return new Constant(this.getLhs().eval(vars).getValue() * this.getRhs().eval(vars).getValue());
        }
        return new Multiplication(this.getLhs().eval(vars), this.getRhs().eval(vars));
    }

    public String toString() {
        return super.toString();
    }

    @Override
    public String getName() {
        return "*";
    }

    @Override
    public int getPriority(){
        return 100;
    }

    public boolean equals(Object other) {
        if (other instanceof Multiplication) {
            return this.equals((Multiplication) other);
        } else {
            return false;
        }
    }

    public boolean equals(Multiplication other) {
        // access a private field of other!
        return (this.getLhs() == other.getLhs() || this.getLhs() == other.getRhs()) && (this.getRhs() == other.getRhs() || this.getRhs() == other.getLhs()) && this.getName() == other.getName();
    }
}
