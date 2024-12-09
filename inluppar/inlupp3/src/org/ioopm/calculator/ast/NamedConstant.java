package org.ioopm.calculator.ast;

public class NamedConstant extends Constant{
    public String name;
    public double value;
    public NamedConstant(String name, double value){
        super(value);
        this.name = name;
    }

    @Override
    public String toString(){
        return this.name;
    }

}
