package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class DivisionTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "/";
        String actualName = new Division(null,null).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Division testDiv = new Division(null,null);
        RuntimeException exception = assertThrows(RuntimeException.class, testDiv::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Division testDiv = new Division(null,null);
        boolean isConstant = testDiv.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Division testDiv = new Division(null,null);
        int expectedPriority = 100;
        int actualPriority = testDiv.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Division testDiv = new Division(null,null);
        Boolean isCommand = testDiv.isCommand();
        assertEquals(false, isCommand);
    }

    @Test
    void testToString() {
        Division Division = new Division(new Constant(3), new Constant(2));
        assertEquals("(3 / 2)", Division.toString());
    }

    @Test
    void testEquals() {
        Division div1 = new Division(new Constant(2), new Constant(3));
        Division div2 = new Division(new Constant(2), new Constant(3));
        Division div3 = new Division(new Constant(3), new Constant(4));
        assertTrue(div1.equals(div2));
        assertFalse(div1.equals(div3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Division Division = new Division(new Constant(6), new Constant(2));
        assertEquals(3, Division.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Division nestedDivision = new Division(new Division(new Constant(4), new Constant(2)), new Constant(1));
        assertEquals(2, nestedDivision.eval(vars).getValue());
    }

    @Test
    void treeTest() {
        Environment vars = new Environment();

        Division divLeft = new Division(new Constant(10), new Constant(5));
        Division divRight = new Division(new Constant(4), new Constant(2));
        Division root = new Division(divLeft, divRight);

        assertEquals(1, root.eval(vars).getValue());
        assertEquals("((10 / 5) / (4 / 2))", root.toString());
    }

    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}