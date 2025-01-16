package org.ioopm.calculator.ast;

public interface Visitor {
    SymbolicExpression visit(Addition n);
    SymbolicExpression visit(Assignment n);
    SymbolicExpression visit(Clear n);
    SymbolicExpression visit(Constant n);
    SymbolicExpression visit(Cos n);
    SymbolicExpression visit(Division n);
    SymbolicExpression visit(Exp n);
    SymbolicExpression visit(Log n);
    SymbolicExpression visit(Multiplication n);
    SymbolicExpression visit(Negation n);
    SymbolicExpression visit(Quit n);
    SymbolicExpression visit(Sin n);
    SymbolicExpression visit(Subtraction n);
    SymbolicExpression visit(Variable n);
    SymbolicExpression visit(Vars n);
    SymbolicExpression visit(Scope scope);
    SymbolicExpression visit(Conditional conditional);
    SymbolicExpression visit(FunctionCall n);
    SymbolicExpression visit(FunctionDeclaration n);


}
