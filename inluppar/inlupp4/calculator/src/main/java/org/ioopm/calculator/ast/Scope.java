package org.ioopm.calculator.ast;

public class Scope extends SymbolicExpression {
    private SymbolicExpression body;

    public Scope(SymbolicExpression body) {
        this.body = body;
    }

    public SymbolicExpression getBody() {
        return this.body;
    }

    @Override
    public SymbolicExpression eval(Environment vars) {
        ScopeHandler scopeHandler = (ScopeHandler) vars;

        scopeHandler.pushEnvironment();
        SymbolicExpression result = body.eval(scopeHandler);
        scopeHandler.popEnvironment();

        return result;
    }

    @Override
    public SymbolicExpression accept(Visitor v) {
        return v.visit(this);
    }

    @Override
    public String toString() {
        return "{" + body.toString() + "}";
    }
}

