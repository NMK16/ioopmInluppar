package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class AssignmentTest {

    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    @Test
    void getName() {
        String expectedName = "=";
        String actualName = new Assignment(null,null).getName();
        assertEquals(expectedName, actualName);
    }

    @Test
    void getValue() {
        Assignment testAssignment = new Assignment(null,null);
        RuntimeException exception = assertThrows(RuntimeException.class, testAssignment::getValue);
        assertEquals("getValue() called on non-constant", exception.getMessage());
    }

    @Test
    void isConstant() {
        Assignment testAssignment = new Assignment(null,null);
        boolean isConstant = testAssignment.isConstant();
        assertFalse(isConstant);
    }

    @Test
    void priority() {
        Assignment testAssignment = new Assignment(null,null);
        int expectedPriority = 300;
        int actualPriority = testAssignment.getPriority();
        assertEquals(expectedPriority, actualPriority);
    }

    @Test
    void isCommand() {
        Assignment testAssignment = new Assignment(null,null);
        boolean isCommand = testAssignment.isCommand();
        assertFalse(isCommand);
    }

    @Test
    void testToString() {
        Assignment Assignment = new Assignment(new Constant(2), new Variable("x"));
        assertEquals("2 = x", Assignment.toString());
    }

    @Test
    void testEquals() {
        Assignment assign1 = new Assignment(new Constant(2), new Variable("x"));
        Assignment assign2 = new Assignment(new Constant(2), new Variable("x"));
        Assignment assign3 = new Assignment(new Constant(3), new Variable("y"));
        assertTrue(assign1.equals(assign2));
        assertFalse(assign1.equals(assign3));
    }

    @Test
    void testEval() {
        Environment vars = new Environment();
        Assignment Assignment = new Assignment(new Constant(2), new Variable("x"));
        assertEquals(2, Assignment.eval(vars).getValue());
    }

    @Test
    void testEvalWithNestedExpressions() {
        Environment vars = new Environment();
        Assignment nestedAssignment = new Assignment(new Assignment(new Constant(1), new Variable("x")), new Variable("y"));
        assertEquals(1, nestedAssignment.eval(vars).getValue());
    }

    @Test
    void treeTest() {
        Environment vars = new Environment();

        Constant const1 = new Constant(5);
        Variable varX = new Variable("x");
        Variable varY = new Variable("y");

        Assignment assign1 = new Assignment(const1, varX);

        Assignment root = new Assignment(assign1, varY);

        SymbolicExpression result = root.eval(vars);

        assertEquals(5, result.getValue());
        assertEquals(5, vars.get(varX).getValue());
        assertEquals(5, vars.get(varY).getValue());
        assertEquals("5 = x = y", root.toString());
    }

    @Test
    void testEmptyAssign() {
        Environment vars = new Environment();

        Constant const1 = new Constant(5);
        Variable varX = new Variable("x");
        Variable varY = new Variable("y");

        Assignment assign1 = new Assignment(const1, null);
        Assignment assign2 = new Assignment(null, varY);
        Assignment assign3 = new Assignment(const1, varY);

        RuntimeException exception = assertThrows(RuntimeException.class, () -> assign1.eval(vars));
        SymbolicExpression result2 = assign2.eval(vars);
        SymbolicExpression result3 = assign3.eval(vars);

        assertEquals("Error: cannot assign value to \"null\"", exception.getMessage());
        assertNull(result2);
        assertEquals(5, result3.getValue());
    }

    @AfterEach
    void tearDown() {
    }

    @AfterAll
    static void tearDownAll() {
    }

}