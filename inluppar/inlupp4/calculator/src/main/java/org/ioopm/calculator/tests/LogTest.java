package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class LogTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "log";
        String actualName = new Log(new Constant(0)).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Log testAdd = new Log(new Constant(0));
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Log testAdd = new Log(new Constant(0));
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Log testAdd = new Log(new Constant(100));
        int expectedPriority = 200;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Log testAdd = new Log(new Constant(100));
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Log Log = new Log(new Constant(100));
        assertEquals("log(100)", Log.toString());
    }

    @Test
    void testEquals() {
        Log Log1 = new Log(new Constant(100));
        Log Log2 = new Log(new Constant(100));
        Log Log3 = new Log(new Constant(10));
        assertTrue(Log1.equals(Log2));
        assertFalse(Log1.equals(Log3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Log LogTest = new Log(new Constant(100));
        assertEquals(Math.log(100), LogTest.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Log nestedLog = new Log(new Log(new Constant(1000)));
        assertEquals(Math.log(Math.log(1000)), nestedLog.eval(vars).getValue());
    }


    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}