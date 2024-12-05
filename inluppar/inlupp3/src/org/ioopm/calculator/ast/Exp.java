package org.ioopm.calculator.ast;

public class Exp extends Unary{
    public Exp(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public String getName() {
        return "exp";
    }
}
