package org.ioopm.calculator;
import java.util.HashMap;

import org.ioopm.calculator.ast.*;

public class Calculator {

        public static void main(String[] args) {
//            Constant c1 = new Constant(5);
//            Constant c2 = new Constant(2);
//            Variable v = new Variable("x");
//            Addition a = new Addition(c1, v);
//            Multiplication m = new Multiplication(a, c2);
//            testPrinting("(5 + x) * 2", m);
            Environment vars = new Environment();
            Multiplication m = new Multiplication(new Addition(new Constant(5), new Variable("pi")), new Constant(2));
            testPrinting("(5 + pi) * 2", m);
            Assignment assignment = new Assignment(new Constant(2), new Variable("x"));
            assignment.eval(vars);
            testEvaluating(new Constant((5+Math.PI)*2), m.eval(vars), vars);


    }
    public static void testPrinting(String expected, SymbolicExpression e) {
        if (expected.equals("" + e)) {
            System.out.println("Passed: " + e);
        } else {
            System.out.println("Error: expected '" + expected + "' but got '" + e + "'");
        }
    }

    public static void testEvaluating(SymbolicExpression expected, SymbolicExpression e, Environment vars) {
        SymbolicExpression r = e.eval(vars);
        if (r.equals(expected)) {
            System.out.println("Passed: " + e);
        } else {
            System.out.println("Error: expected '" + expected + "' but got '" + e + "'");
        }
    }
}
