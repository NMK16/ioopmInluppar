package org.ioopm.calculator.ast;

public class Log extends Unary{
    public Log(SymbolicExpression operand){
        super(operand);
    }

    @Override
    public String getName() {
        return "log";
    }
}
