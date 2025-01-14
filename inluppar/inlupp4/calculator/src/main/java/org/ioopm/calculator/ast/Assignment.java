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
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }
    @Override
    public SymbolicExpression eval(Environment vars) {
        if(this.getRhs() == null){
            throw new IllegalAssignmentException("Error: cannot assign value to \"null\"");
        }
        if(this.getLhs() == null){
            vars.remove((Variable)this.getRhs());
            return this.getLhs();
        }
        SymbolicExpression lhs = this.getLhs().eval(vars);
        SymbolicExpression rhs = this.getRhs();

        if (Constants.namedConstants.containsKey(rhs.toString())) {
            throw new IllegalAssignmentException("Error: cannot redefine named constant: " + rhs);
        }

        vars.put((Variable) rhs, lhs);
        return lhs;
    }

    public boolean equals(Object other) {
        if (other instanceof Assignment) {
            return this.equals((Assignment) other);
        } else {
            return false;
        }
    }

    public boolean equals(Assignment other) {
        // access a private field of other!
        return (this.getLhs().equals(other.getLhs()) && this.getRhs().equals(other.getRhs()) && this.getName().equals(other.getName()));
    }

}
