package org.ioopm.calculator;

import org.ioopm.calculator.ast.*;

public class Calculator {
        public static void main(String[] args) {
            // Create an assignment: x = 5 + 3
            SymbolicExpression left = new Variable("x");
            SymbolicExpression right = new Addition(new Constant(5), new Constant(3));
            SymbolicExpression assignment = new Assignment(left, right);
            String assignment2 = new Assignment(left, right).toString();

            // Evaluate the assignment
            double result = assignment.evaluate();

            System.out.println(assignment2); // Outputs: x = (5.0 + 3.0)
            System.out.println("Result: " + result); // Outputs: Result: 8.0

    }
}
