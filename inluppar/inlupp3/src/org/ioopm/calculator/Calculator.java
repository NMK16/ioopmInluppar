package org.ioopm.calculator;

import org.ioopm.calculator.ast.*;

public class Calculator {

        public static void main(String[] args) {
            Constant c1 = new Constant(5);
            Constant c2 = new Constant(2);
            Variable v = new Variable("x");
            Addition a = new Addition(c1, v);
            Multiplication m = new Multiplication(a, c2);
            testPrinting("(5 + x) * 2", m);


    }
    public static void testPrinting(String expected, SymbolicExpression e) {
        if (expected.equals("" + e)) {
            System.out.println("Passed: " + e);
        } else {
            System.out.println("Error: expected '" + expected + "' but got '" + e + "'");
        }
    }
}
