package org.ioopm.calculator.ast;

import java.util.List;

public class Sequence extends SymbolicExpression {
    private List<SymbolicExpression> expressions;

    public Sequence(List<SymbolicExpression> expressions) {
        this.expressions = expressions;
    }

    // Getter for expressions
    // Accept method for visitor
}
