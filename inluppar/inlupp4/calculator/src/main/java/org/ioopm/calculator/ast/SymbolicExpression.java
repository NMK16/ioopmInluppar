package org.ioopm.calculator.ast;

import java.util.HashMap;

public abstract class SymbolicExpression {
    public abstract SymbolicExpression eval(Environment vars);

    public boolean isConstant(){
        return false;
    }

    public String getName(){
        throw new RuntimeException("getName() called on expression with no operator");
    }

    public int getPriority(){
        return 300;
    }

    public double getValue(){
        throw new RuntimeException("getValue() called on non-constant");
    }

    public boolean isCommand(){
        return false;
    }
}
