package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class ConstantTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        Constant testConst = new Constant(2);
        RuntimeException exception = assertThrows(RuntimeException.class, testConst::getName);
        assertEquals("getName() called on expression with no operator", exception.getMessage());
    }

    @Test
    void getValue() {
        Constant testConst = new Constant(2);
        assertEquals(2, testConst.getValue());
    }

    @Test
    void isConstant() {
        Constant testConst = new Constant(2);
        boolean isConstant = testConst.isConstant();
        assertTrue(isConstant);
    }

    @Test
    void priority() {
        Constant testConst = new Constant(2);
        int expectedPriority = 300;
        int actualPriority = testConst.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Constant testConst = new Constant(2);
        Boolean isCommand = testConst.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Constant Constant = new Constant(3);
        assertEquals("3.0", Constant.toString());
    }

    @Test
    void testEquals() {
        Constant const1 = new Constant(2);
        Constant const2 = new Constant(2);
        Constant const3 = new Constant(3);
        assertTrue(const1.equals(const2));
        assertFalse(const1.equals(const3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Constant Constant = new Constant(2);
        assertEquals(2, Constant.eval(vars).getValue());
    }



    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}