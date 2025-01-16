package org.ioopm.calculator;
import java.io.IOException;
import java.util.Scanner;

import org.ioopm.calculator.ast.*;
import org.ioopm.calculator.parser.CalculatorParser;
import org.ioopm.calculator.parser.IllegalExpressionException;
import org.ioopm.calculator.parser.SyntaxErrorException;

public class Calculator {

    public static void main(String[] args) throws IOException {
        int expressionsCounter = 0;
        int errors = 0;
        int fullyEvaluated = 0;
        final CalculatorParser Parser = new CalculatorParser();
        final Environment vars = new Environment();
        Scanner sc = new Scanner(System.in);
        final NamedConstantChecker namedConstantChecker = new NamedConstantChecker();
        final ReassignmentChecker reAssignmentChecker = new ReassignmentChecker();
        final EvaluationVisitor evaluator = new EvaluationVisitor();

        label:
        while (true){
            System.out.println("Enter expression to evaluate: ");
            String input = sc.nextLine();

            try{
                SymbolicExpression parsed = Parser.parse(input, vars);

                if(parsed.isCommand()){
                    switch (parsed) {
                        case Quit ignored:
                            System.out.println("Expressions Entered: " + (expressionsCounter + errors));
                            System.out.println("Expressions Successfully Evaluated: " + expressionsCounter);
                            System.out.println("Expressions Fully Evaluated: " + fullyEvaluated);
                            break label;
                        case Vars ignored:
                            System.out.println(vars);
                            break;
                        case Clear ignored:
                            vars.clear();
                            break;
                        default:
                            break;
                    }
                }
                else{
                    if (!namedConstantChecker.check(parsed)) {
                        System.out.println("\nError, assignments to named constants:");
                        for (String illegalAssignment : namedConstantChecker.getIllegalAssignments()) {
                            System.out.println(illegalAssignment);
                        }
                        System.out.println();
                        errors++;
                        continue;
                    }
                    if(!reAssignmentChecker.check(parsed)){
                        System.out.println("\nError, the variable " + reAssignmentChecker.getIdentifier() + " is reassigned.\n");
                        errors++;
                        continue;
                    }
                    SymbolicExpression correct = new Addition(new Scope(new Assignment(new Constant(1), new Variable("x"))), new Scope(new Variable("x")));
                    final SymbolicExpression evaluationResult = evaluator.evaluate(parsed, vars);
                    System.out.println("Answer: " + evaluationResult);

                    if(parsed.isConstant()){
                        fullyEvaluated++;
                    }
                    expressionsCounter++;
                }
            }
            catch(IllegalAssignmentException | SyntaxErrorException | IllegalExpressionException e){
                System.out.println(e.getMessage());
                errors++;
            }
        }

    }
}
