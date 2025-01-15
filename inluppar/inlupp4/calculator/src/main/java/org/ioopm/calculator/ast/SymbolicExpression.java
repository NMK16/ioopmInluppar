package org.ioopm.calculator.ast;

public abstract class SymbolicExpression {
    public boolean isConstant(){
        return false;
    }
    public SymbolicExpression accept(Visitor v) {
        throw new RuntimeException("accept called on Expression");
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
