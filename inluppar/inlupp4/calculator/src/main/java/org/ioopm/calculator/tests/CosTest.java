package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class CosTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "cos";
        String actualName = new Cos(new Constant(0)).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Cos testAdd = new Cos(new Constant(0));
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Cos testAdd = new Cos(new Constant(0));
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Cos testAdd = new Cos(new Constant(Math.PI/2));
        int expectedPriority = 200;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Cos testAdd = new Cos(new Constant(Math.PI/2));
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Cos Cos = new Cos(new Constant(Math.PI/2));
        assertEquals("cos(1.5707963267948966)", Cos.toString());
    }

    @Test
    void testEquals() {
        Cos cos1 = new Cos(new Constant(Math.PI/2));
        Cos cos2 = new Cos(new Constant(Math.PI/2));
        Cos cos3 = new Cos(new Constant(Math.PI));
        assertTrue(cos1.equals(cos2));
        assertFalse(cos1.equals(cos3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Cos cosTest = new Cos(new Constant(Math.PI));
        assertEquals(Math.cos(Math.PI), cosTest.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Cos nestedCos = new Cos(new Cos(new Constant(Math.PI/2)));
        assertEquals(Math.cos(Math.cos(Math.PI/2)), nestedCos.eval(vars).getValue());
    }


    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}