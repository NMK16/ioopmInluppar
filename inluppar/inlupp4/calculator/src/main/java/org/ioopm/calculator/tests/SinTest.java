package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class SinTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "sin";
        String actualName = new Sin(new Constant(0)).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Sin testAdd = new Sin(new Constant(0));
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Sin testAdd = new Sin(new Constant(0));
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Sin testAdd = new Sin(new Constant(Math.PI/2));
        int expectedPriority = 200;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Sin testAdd = new Sin(new Constant(Math.PI/2));
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Sin sinTest = new Sin(new Constant(Math.PI/2));
        assertEquals("sin(1.5707963267948966)", sinTest.toString());
    }

    @Test
    void testEquals() {
        Sin sin1 = new Sin(new Constant(Math.PI/2));
        Sin sin2 = new Sin(new Constant(Math.PI/2));
        Sin sin3 = new Sin(new Constant(Math.PI));
        assertTrue(sin1.equals(sin2));
        assertFalse(sin1.equals(sin3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Sin SinTest = new Sin(new Constant(Math.PI));
        assertEquals(Math.sin(Math.PI), SinTest.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Sin nestedSin = new Sin(new Sin(new Constant(Math.PI/2)));
        assertEquals(Math.sin(Math.sin(Math.PI/2)), nestedSin.eval(vars).getValue());
    }


    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}