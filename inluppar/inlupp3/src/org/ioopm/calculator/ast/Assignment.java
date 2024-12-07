package org.ioopm.calculator.ast;

import java.util.HashMap;

public class Assignment extends Binary{
    public Assignment(SymbolicExpression lhs, SymbolicExpression rhs){
        super(lhs, rhs);
    }
    @Override
    public String getName() {
        return "=";
    }
    @Override
    public SymbolicExpression eval(Environment vars) {
        SymbolicExpression lhs = this.getLhs().eval(vars);
        SymbolicExpression rhs = this.getRhs().eval(vars);
        if(lhs.isConstant() && !rhs.isConstant()){
            vars.put((Variable)rhs, lhs);
            return lhs;
        }
        return new Assignment(lhs, rhs);
    }
}
