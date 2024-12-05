package org.ioopm.calculator.ast;

public class Constant extends Atom{
    private double value;
    public Constant(double value){
        this.value = value;
    }

    @Override
    public boolean isConstant() {
        return true; // Constant objects are always constants
    }

    @Override
    public double getValue(){
        return this.value;
    }

    public String toString() {
        return String.valueOf(this.value);
    }
}
