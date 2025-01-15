package org.ioopm.calculator.ast;

import java.util.Deque;
import java.util.LinkedList;

public class ScopeHandler extends Environment {
    private final Deque<Environment> environmentStack;

    public ScopeHandler() {
        this.environmentStack = new LinkedList<>();
        this.environmentStack.push(new Environment());
    }

    @Override
    public SymbolicExpression get(Object var) {
        for (Environment env : environmentStack) {
            SymbolicExpression value = env.get(var);
            if (value != null) {
                return value;
            }
        }
        return null;
    }


    @Override
    public SymbolicExpression put(Variable var, SymbolicExpression value) {
        Environment currentEnv = environmentStack.peek();
        currentEnv.put(var, value);
        return var;
    }

    public void pushEnvironment() {
        environmentStack.push(new Environment());
    }

    public void popEnvironment() {
        if (environmentStack.size() > 1) {
            environmentStack.pop();
        }
    }
}
