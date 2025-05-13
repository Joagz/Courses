#include <iostream>
#include "lexer/lexer.hpp"

void print_infix(expression::Expression* expr) {
    if (expr == nullptr) return;

    if (expr->get_type() == expression::Atom) {
        std::cout << expr->get_value();
        return;
    }

    std::cout << "(";
    print_infix(expr->get_expression().lhs);
    std::cout << " " << expr->get_token().value << " ";
    print_infix(expr->get_expression().rhs);
    std::cout << ")";
}


int main(int argc, char const *argv[])
{
    std::cout << "Pratt Parsing Algorithm" << std::endl;

    lexer::Lexer lx = lexer::Lexer("1*2 + 3");
    expression::Expression* expr = lx.parse_expression(0);

    print_infix(expr);
    std::cout << "\n";

    return 0;
}

