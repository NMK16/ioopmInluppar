package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class AdditionTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "+";
        String actualName = new Addition(null,null).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Addition testAdd = new Addition(null,null);
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Addition testAdd = new Addition(null,null);
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Addition testAdd = new Addition(null,null);
        int expectedPriority = 50;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Addition testAdd = new Addition(null,null);
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Addition addition = new Addition(new Constant(2), new Constant(3));
        assertEquals("2 + 3", addition.toString());
    }

    @Test
    void testEquals() {
        Addition add1 = new Addition(new Constant(2), new Constant(3));
        Addition add2 = new Addition(new Constant(2), new Constant(3));
        Addition add3 = new Addition(new Constant(3), new Constant(4));
        assertTrue(add1.equals(add2));
        assertFalse(add1.equals(add3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Addition addition = new Addition(new Constant(2), new Constant(3));
        assertEquals(5, addition.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Addition nestedAddition = new Addition(new Addition(new Constant(1), new Constant(2)), new Constant(3));
        assertEquals(6, nestedAddition.eval(vars).getValue());
    }

    @Test
    void treeTest() {
        Environment vars = new Environment();

        Addition addLeft = new Addition(new Constant(1), new Constant(2));
        Addition addRight = new Addition(new Constant(3), new Constant(4));
        Addition root = new Addition(addLeft, addRight);

        assertEquals(10, root.eval(vars).getValue());
        assertEquals("1 + 2 + 3 + 4", root.toString());
    }

    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}