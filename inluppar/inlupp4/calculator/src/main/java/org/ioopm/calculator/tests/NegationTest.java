package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class NegationTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "-";
        String actualName = new Negation(new Constant(2)).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Negation testAdd = new Negation(new Constant(2));
        RuntimeException exception = assertThrows(RuntimeException.class, testAdd::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Negation testAdd = new Negation(new Constant(2));
        boolean isConstant = testAdd.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Negation testAdd = new Negation(new Constant(2));
        int expectedPriority = 200;
        int actualPriority = testAdd.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Negation testAdd = new Negation(new Constant(2));
        Boolean isCommand = testAdd.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Negation Negation = new Negation(new Constant(2));
        assertEquals("-(2)", Negation.toString());
    }

    @Test
    void testEquals() {
        Negation neg1 = new Negation(new Constant(3));
        Negation neg2 = new Negation(new Constant(3));
        Negation neg3 = new Negation(new Constant(2));
        assertTrue(neg1.equals(neg2));
        assertFalse(neg1.equals(neg3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Negation Negation = new Negation(new Constant(3));
        assertEquals(-3, Negation.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Negation nestedNegation = new Negation(new Negation(new Constant(1)));
        assertEquals(1, nestedNegation.eval(vars).getValue());
    }


    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}