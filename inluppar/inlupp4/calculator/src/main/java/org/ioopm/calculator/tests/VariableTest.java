package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class VariableTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        Variable testVariable = new Variable("X");
        RuntimeException exception = assertThrows(RuntimeException.class, testVariable::getName);
        assertEquals("getName() called on expression with no operator", exception.getMessage());
    }

    @Test
    void getValue() {
        Variable testVariable = new Variable("X");
        assertEquals("X", testVariable.toString());
    }

    @Test
    void isConstant() {
        Variable testVariable = new Variable("X");
        boolean isVariable = testVariable.isConstant();
        assertFalse(isVariable);
    }

    @Test
    void priority() {
        Variable testVariable = new Variable("X");
        int expectedPriority = 300;
        int actualPriority = testVariable.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Variable testVariable = new Variable("X");
        Boolean isCommand = testVariable.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Variable Variable = new Variable("Y");
        assertEquals("Y", Variable.toString());
    }

    @Test
    void testEquals() {
        Variable variable1 = new Variable("X");
        Variable variable2 = new Variable("X");
        Variable variable3 = new Variable("Y");
        assertTrue(variable1.equals(variable2));
        assertFalse(variable1.equals(variable3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Variable Variable = new Variable("X");
        assertEquals("X", Variable.eval(vars).toString());
    }



    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}