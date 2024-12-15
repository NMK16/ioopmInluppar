package org.ioopm.calculator.ast;

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
        SymbolicExpression rhs = this.getRhs();
        if (Constants.namedConstants.containsKey(rhs.toString())) {
            throw new IllegalAssignmentException("Error: cannot redefine named constant: " + rhs);
        }
        vars.put((Variable) rhs, lhs);
        return lhs;
    }
}
