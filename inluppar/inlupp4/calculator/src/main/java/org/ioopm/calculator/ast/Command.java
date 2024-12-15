package org.ioopm.calculator.ast;

import java.util.HashMap;

public abstract class Command extends SymbolicExpression{
    @Override
    public SymbolicExpression eval(Environment vars) {
        throw new RuntimeException("Commands can't be evaluated");
    }

    @Override
    public boolean isCommand(){
        return true;
    }
}
