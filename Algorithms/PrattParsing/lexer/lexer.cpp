#include "lexer.hpp"

namespace lexer
{
    expression::Expression *Lexer::parse_expression(int min_bp)
    {

        // std::cout << "parse_expression\n";
        expression::Expression *lhs = this->next();

        if (lhs->get_type() == expression::Operator)
        {
            // std::cout << "First element can't be an operator\n";
            exit(-1);
        }

        for (;;)
        {
            expression::Expression *op = this->peek();

            if (op == nullptr)
            {
                std::cout << "op is nullptr" << std::endl;
                break;
            }

            if (op->get_type() == expression::Eof)
            {
                // std::cout << "Eof" << std::endl;
                break;
            }

            if (op->get_type() == expression::Atom)
            {
                // std::cout << lhs->get_value() << "\n";
                // std::cout << op->get_value() << "\n";
                // std::cout << "Second element can't be an Atom\n";
                exit(-1);
            }

            std::tuple<int, int> infix_bp = op->get_infix_bp();

            int lhs_bp = std::get<0>(infix_bp);
            int rhs_bp = std::get<1>(infix_bp);

            if (lhs_bp < min_bp)
            {
                break;
            }

            this->next();
            expression::Expression *rhs = parse_expression(rhs_bp);

            lhs = new expression::Expression(op->get_token(), lhs, rhs);
        }
        expression::Token token = lhs->get_token();

        expression::BinaryExpression expr = lhs->get_expression();
        // std::cout << expr.lhs << expr.op << expr.rhs << std::endl;

        return lhs;
    }

    std::vector<expression::Expression *> Lexer::tokenize(const char *str)
    {

        std::stringstream ss(str);
        std::vector<expression::Expression *> result = std::vector<expression::Expression *>();

        char c;
        while (ss >> c)
        {
            if (!isspace(c) && !isblank(c))
            {
                result.push_back(new expression::Expression(c));
            }
        };

        // Push Eof
        result.push_back(new expression::Expression());

        return result;
    }

    expression::Expression *Lexer::next()
    {
        expression::Expression *tk = this->tokens.back();
        this->tokens.pop_back();
        return tk;
    }

    expression::Expression *Lexer::peek()
    {
        return this->tokens.back();
    }

} // namespace lexer
