package org.ioopm.calculator.ast;

import java.util.ArrayList;
import java.util.List;

public class NamedConstantChecker implements Visitor {

    private List<String> illegalAssignments = new ArrayList<>();

    // Method to check for assignments to named constants
    public boolean check(SymbolicExpression expression) {
        illegalAssignments.clear();  // Clear previous errors
        expression.accept(this);  // Start the traversal from the root expression
        return illegalAssignments.isEmpty();
    }

    public List<String> getIllegalAssignments() {
        return this.illegalAssignments;
    }

    // Recursive visit method for Addition (example, repeat for other operations)
    @Override
    public SymbolicExpression visit(Addition a) {
        a.getLhs().accept(this);
        a.getRhs().accept(this);
        return null;
    }

    // Visit the Assignment and check for named constants
    @Override
    public SymbolicExpression visit(Assignment a) {
        SymbolicExpression left = a.getLhs().accept(this);
        SymbolicExpression right = a.getRhs();

        if (Constants.namedConstants.containsKey(right.toString())) {
            illegalAssignments.add(right + " = " + Constants.namedConstants.get(right.toString()));
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

