package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class ExpTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "exp";
        String actualName = new Exp(new Constant(0)).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Exp testAdd = new Exp(new Constant(0));
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Exp testAdd = new Exp(new Constant(0));
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Exp testAdd = new Exp(new Constant(2));
        int expectedPriority = 200;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Exp testAdd = new Exp(new Constant(2));
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Exp Exp = new Exp(new Constant(2));
        assertEquals("exp(2)", Exp.toString());
    }

    @Test
    void testEquals() {
        Exp Exp1 = new Exp(new Constant(2));
        Exp Exp2 = new Exp(new Constant(2));
        Exp Exp3 = new Exp(new Constant(3));
        assertTrue(Exp1.equals(Exp2));
        assertFalse(Exp1.equals(Exp3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Exp ExpTest = new Exp(new Constant(3));
        assertEquals(Math.exp(3), ExpTest.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Exp nestedExp = new Exp(new Exp(new Constant(2)));
        assertEquals(Math.exp(Math.exp(2)), nestedExp.eval(vars).getValue());
    }


    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}