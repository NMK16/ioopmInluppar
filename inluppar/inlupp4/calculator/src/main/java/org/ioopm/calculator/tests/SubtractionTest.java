package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class SubtractionTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "-";
        String actualName = new Subtraction(null,null).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Subtraction testSub = new Subtraction(null,null);
        RuntimeException exception = assertThrows(RuntimeException.class, testSub::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Subtraction testSub = new Subtraction(null,null);
        boolean isConstant = testSub.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Subtraction testSub = new Subtraction(null,null);
        int expectedPriority = 50;
        int actualPriority = testSub.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Subtraction testSub = new Subtraction(null,null);
        Boolean isCommand = testSub.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Subtraction Subtraction = new Subtraction(new Constant(3), new Constant(2));
        assertEquals("(3 - 2)", Subtraction.toString());
    }

    @Test
    void testEquals() {
        Subtraction sub1 = new Subtraction(new Constant(2), new Constant(3));
        Subtraction sub2 = new Subtraction(new Constant(2), new Constant(3));
        Subtraction sub3 = new Subtraction(new Constant(3), new Constant(4));
        assertTrue(sub1.equals(sub2));
        assertFalse(sub1.equals(sub3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Subtraction Subtraction = new Subtraction(new Constant(3), new Constant(2));
        assertEquals(1, Subtraction.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Subtraction nestedSubtraction = new Subtraction(new Subtraction(new Constant(3), new Constant(2)), new Constant(1));
        assertEquals(0, nestedSubtraction.eval(vars).getValue());
    }

    @Test
    void treeTest() {
        Environment vars = new Environment();

        Subtraction subLeft = new Subtraction(new Constant(10), new Constant(4));
        Subtraction subRight = new Subtraction(new Constant(3), new Constant(2));
        Subtraction root = new Subtraction(subLeft, subRight);

        assertEquals(5, root.eval(vars).getValue());
        assertEquals("((10 - 4) - (3 - 2))", root.toString());
    }

    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}