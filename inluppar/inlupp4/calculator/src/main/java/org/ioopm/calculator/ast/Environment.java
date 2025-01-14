package org.ioopm.calculator.ast;

import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeSet;

public class Environment extends HashMap<Variable, SymbolicExpression> {
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Variables: ");

        TreeSet<Variable> sortedVars = new TreeSet<>(this.keySet());

        Iterator<Variable> iter = sortedVars.iterator();
        while (iter.hasNext()) {
            Variable v = iter.next();
            sb.append(v.getIdentifier());
            sb.append(" = ");
            sb.append(this.get(v));

            if (iter.hasNext()) {
                sb.append(", ");
            }
        }
        return sb.toString();
    }

}
