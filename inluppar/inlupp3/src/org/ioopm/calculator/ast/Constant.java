package org.ioopm.calculator.ast;

public class Constant extends Atom{
    private double value;
    public Constant(double value){
        this.value = value;
    }

    @Override
    public double evaluate() {
        return this.value;
    }

    @Override
    public String toString() {
        return this.value+"";
    }
}
