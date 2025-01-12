package org.ioopm.calculator.ast;

public abstract class Binary extends SymbolicExpression{
    private SymbolicExpression lhs;
    private SymbolicExpression rhs;

    public Binary(SymbolicExpression lhs, SymbolicExpression rhs) {
        this.lhs = lhs;
        this.rhs = rhs;
    }

    public SymbolicExpression getLhs() {
        return this.lhs;
    }

    public SymbolicExpression getRhs() {
        return this.rhs;
    }

    public String toString() {
        String left = this.getLhs().toString();
        String right = this.getRhs().toString();

        if(this.getLhs().isConstant() && this.getLhs().getValue() == (int)this.getLhs().getValue()){
            left = String.valueOf((int)this.getLhs().getValue());
        }
        if(this.getRhs().isConstant() && this.getRhs().getValue() == (int)this.getRhs().getValue()){
            right = String.valueOf((int)this.getRhs().getValue());
        }


        if (this.getLhs().getPriority() < this.getPriority()) {
            left = "(" + left + ")";
        }

        if (this.getRhs().getPriority() < this.getPriority()) {
            right = "(" + right + ")";
        }
        if(this.getName() == "+" || this.getName() == "*" || this.getName() == "="){
            return left + " " + this.getName() + " " + right;
        }
        return "(" + left + " " + this.getName() + " " + right + ")";
    }
}
