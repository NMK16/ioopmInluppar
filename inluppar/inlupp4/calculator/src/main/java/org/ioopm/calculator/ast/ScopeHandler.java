package org.ioopm.calculator.ast;

import java.util.Stack;

public class ScopeHandler extends Environment {
    private final Stack<Environment> environmentStack;

    public ScopeHandler() {
        this.environmentStack = new Stack<>();
    }

    public Stack<Environment> getEnvironmentStack(){
        return this.environmentStack;
    }

    @Override
    public SymbolicExpression get(Object var) {
        return this.environmentStack.peek().get(var);
    }

    @Override
    public SymbolicExpression put(Variable var, SymbolicExpression value) {
        Environment currentEnv = environmentStack.peek();
        currentEnv.put(var, value);
        return var;
    }

    public void pushEnvironment(Environment env) {
        environmentStack.push(env);
    }

    public void popEnvironment() {
        if (!environmentStack.isEmpty()) {
            environmentStack.pop();
        }
    }
}
