package org.ioopm.calculator.tests;

import static org.junit.jupiter.api.Assertions.*;

import org.ioopm.calculator.ast.*;
import org.ioopm.calculator.parser.CalculatorParser;
import org.ioopm.calculator.parser.SyntaxErrorException;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;

public class ParserTest {


    @BeforeAll
    static void initAll() {
    }

    @BeforeEach
    void init() {
    }

    private final CalculatorParser parser = new CalculatorParser();
    private final Environment vars = new Environment();

    @Test
    public void testConstantParsing() throws IOException {
        SymbolicExpression original = new Constant(42);
        String expression = original.toString();
        SymbolicExpression parsed = parser.parse(expression, vars);

        assertEquals(original, parsed, "Parsing a constant should return an equivalent AST");
    }

    @Test
    public void testUnaryNegationParsing() throws IOException {
        SymbolicExpression original = new Negation(new Constant(42));
        String expression = original.toString();
        SymbolicExpression parsed = parser.parse(expression, vars);

        assertEquals(original, parsed, "Parsing a unary negation should return an equivalent AST");
    }

    @Test
    public void testBinaryAdditionParsing() throws IOException {
        SymbolicExpression original = new Addition(new Constant(42), new Constant(7));
        String expression = original.toString();
        SymbolicExpression parsed = parser.parse(expression, vars);

        assertEquals(original, parsed, "Parsing an addition should return an equivalent AST");
    }

    @Test
    public void testNestedExpressionsParsing() throws IOException {
        SymbolicExpression original = new Addition(
                new Negation(new Constant(42)),
                new Multiplication(new Constant(7), new Constant(5))
        );
        String expression = original.toString();
        SymbolicExpression parsed = parser.parse(expression, vars);

        assertEquals(original, parsed, "Parsing nested expressions should return an equivalent AST");
    }

    @Test
    public void testInvalidSyntaxThrowsException() {
        String invalidExpression = "42 + * 7";
        assertThrows(SyntaxErrorException.class, () -> parser.parse(invalidExpression, vars),
                "Invalid syntax should throw SyntaxErrorException");
    }

    @Test
    public void testUnbalancedParenthesesThrowsException() {
        String invalidExpression = "(42 + 7";
        assertThrows(SyntaxErrorException.class, () -> parser.parse(invalidExpression, vars),
                "Unbalanced parentheses should throw SyntaxErrorException");
    }

    @Test
    public void testInvalidVariableAssignmentThrowsException() {
        String invalidExpression = "x = 42";
        assertThrows(SyntaxErrorException.class, () -> parser.parse(invalidExpression, vars),
                "Invalid assignment syntax should throw SyntaxErrorException");
    }
}