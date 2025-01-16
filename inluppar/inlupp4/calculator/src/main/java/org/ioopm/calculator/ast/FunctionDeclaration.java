package org.ioopm.calculator.ast;

import java.util.ArrayList;
import java.util.List;

public class FunctionDeclaration extends SymbolicExpression {
    private final String name;
    private final List<String> parameters;
    private final SymbolicExpression body;

    public FunctionDeclaration(String name, List<String> parameters, SymbolicExpression body) {
        super();  // Call superclass constructor if needed
        this.name = name;
        this.parameters = new ArrayList<>(parameters);  // Make a defensive copy
        this.body = body;
    }

    public String getName() {
        return this.name;
    }

    public List<String> getParameters() {
        return new ArrayList<>(this.parameters);  // Return defensive copy
    }

    public SymbolicExpression getBody() {
        return this.body;
    }

    @Override
    public boolean isConstant() {
        return false;
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    @Override
    public String toString() {
        return "function " + name + "(" + String.join(", ", parameters) + ") " + body + " end";
    }
}