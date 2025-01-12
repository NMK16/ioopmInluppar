package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class MultiplicationTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "*";
        String actualName = new Multiplication(null,null).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Multiplication testMultiply = new Multiplication(null,null);
        RuntimeException exception = assertThrows(RuntimeException.class, testMultiply::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Multiplication testMultiply = new Multiplication(null,null);
        boolean isConstant = testMultiply.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Multiplication testMultiply = new Multiplication(null,null);
        int expectedPriority = 100;
        int actualPriority = testMultiply.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Multiplication testMultiply = new Multiplication(null,null);
        Boolean isCommand = testMultiply.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Multiplication Multiplication = new Multiplication(new Constant(3), new Constant(2));
        assertEquals("3 * 2", Multiplication.toString());
    }

    @Test
    void testEquals() {
        Multiplication multiply1 = new Multiplication(new Constant(2), new Constant(3));
        Multiplication multiply2 = new Multiplication(new Constant(2), new Constant(3));
        Multiplication multiply3 = new Multiplication(new Constant(3), new Constant(4));
        assertTrue(multiply1.equals(multiply2));
        assertFalse(multiply1.equals(multiply3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Multiplication Multiplication = new Multiplication(new Constant(6), new Constant(2));
        assertEquals(12, Multiplication.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Multiplication nestedMultiplication = new Multiplication(new Multiplication(new Constant(4), new Constant(2)), new Constant(1));
        assertEquals(8, nestedMultiplication.eval(vars).getValue());
    }

    @Test
    void treeTest() {
        Environment vars = new Environment();

        Multiplication multiplyLeft = new Multiplication(new Constant(1), new Constant(5));
        Multiplication multiplyRight = new Multiplication(new Constant(2), new Constant(5));
        Multiplication root = new Multiplication(multiplyLeft, multiplyRight);

        assertEquals(50, root.eval(vars).getValue());
        assertEquals("1 * 5 * 2 * 5", root.toString());
    }

    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}