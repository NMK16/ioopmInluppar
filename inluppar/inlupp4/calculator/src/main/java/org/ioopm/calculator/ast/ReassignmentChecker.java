package org.ioopm.calculator.ast;

import java.util.ArrayList;
import java.util.List;

public class ReassignmentChecker implements Visitor {

    private List<SymbolicExpression> totalVariables = new ArrayList<>();
    private String identifier;
    // Method to check for assignments to named constants
    public boolean check(SymbolicExpression expression) {
        totalVariables.clear();
        expression.accept(this);
        List<SymbolicExpression> tempList = new ArrayList<>();
        for (SymbolicExpression variable : totalVariables) {
            if (!tempList.contains(variable)) {
                tempList.add(variable);
            } else {
                identifier = ((Variable) (variable)).getIdentifier();
                return false;
            }
        }
        return true;
    }

    public String getIdentifier() {
        return this.identifier;
    }

    // Recursive visit method for Addition (example, repeat for other operations)
    @Override
    public SymbolicExpression visit(Addition a) {
        a.getLhs().accept(this);  // Visit the left-hand side
        a.getRhs().accept(this);  // Visit the right-hand side
        return null;
    }

    // Visit the Assignment and check for named constants
    @Override
    public SymbolicExpression visit(Assignment a) {
        SymbolicExpression left = a.getLhs().accept(this);
        SymbolicExpression right = a.getRhs();

        if (right instanceof Variable) {
            totalVariables.add(right);
        }

        return left;
    }

    @Override
    public SymbolicExpression visit(Clear n) {
        n.accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Constant n) {
        return null;
    }

    @Override
    public SymbolicExpression visit(Cos n) {
        n.getOperand().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Division n) {
        n.getLhs().accept(this);
        n.getRhs().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Exp n) {
        n.getOperand().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Log n) {
        n.getOperand().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Multiplication n) {
        n.getLhs().accept(this);
        n.getRhs().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Negation n) {
        n.getOperand().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Quit n) {
        n.accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Sin n) {
        n.getOperand().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Subtraction n) {
        n.getLhs().accept(this);
        n.getRhs().accept(this);
        return null;
    }

    @Override
    public SymbolicExpression visit(Variable n) {
        return null;
    }

    @Override
    public SymbolicExpression visit(Vars n) {
        n.accept(this);
        return null;
    }

}
