#include "lexer.hpp"

namespace lexer
{
    expression::Expression Lexer::parse_expression(int min_bp)
    {
        expression::Expression lhs = this->next();
        if (lhs.get_type() == expression::Operator)
            exit(-1);

        for (;;)
        {

            expression::Expression op = this->peek();

            if (op.get_type() == expression::Atom)
                exit(-1);

            int *infix_bp = op.get_infix_bp();
            if (infix_bp == NULL)
                exit(-1);

            int lhs_bp, rhs_bp = infix_bp[0], infix_bp[1];
            
            if(lhs_bp < min_bp) {
                break;
            }

            this->next();
            expression::Expression rhs = parse_expression(rhs_bp);

            lhs = expression::Expression(op.get_value(), lhs.get_value(), rhs.get_value());

        }

        return lhs;
    }

    std::vector<expression::Expression> Lexer::tokenize(const char *str)
    {

        std::stringstream ss(str);
        std::vector<expression::Expression> result = std::vector<expression::Expression>();

        char c;
        while (ss >> c)
        {
            if (c != ' ')
            {
                result.push_back(expression::Expression(c));
            }
        };

        // Push Eof
        result.push_back(expression::Expression());
        return result;
    }

    expression::Expression Lexer::next()
    {
        expression::Expression tk = this->tokens.back();
        this->tokens.pop_back();
        return tk;
    }

    expression::Expression Lexer::peek()
    {
        return this->tokens.back();
    }

} // namespace lexer
