package org.ioopm.calculator.ast;

import java.util.ArrayList;
import java.util.List;

public class FunctionCall extends SymbolicExpression {
    private final String name;
    private final List<SymbolicExpression> arguments;

    public FunctionCall(String name, List<SymbolicExpression> arguments) {
        super();  // Call superclass constructor if needed
        this.name = name;
        this.arguments = new ArrayList<>(arguments);  // Make a defensive copy
    }

    public String getName() {
        return this.name;
    }

    public List<SymbolicExpression> getArguments() {
        return new ArrayList<>(this.arguments);  // Return defensive copy
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    @Override
    public boolean isConstant() {
        return false;
    }

    @Override
    public String toString() {
        return name + "(" + String.join(", ", arguments.stream()
                                              .map(Object::toString)
                                              .toList()) + ")";
    }
}