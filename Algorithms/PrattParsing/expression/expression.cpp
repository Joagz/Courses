#include "expression.hpp"

namespace expression
{

    std::tuple<int, int> Expression::get_infix_bp()
    {
        Token tok;

        if (this->type == ExpressionType::Single)
        {
            tok = this->token;
        }
        else
        {
            tok = this->expression.op;
        }

        return {tok.lhs_precedence, tok.rhs_precedence};
    }

    TokenType Expression::get_type()
    {
        if (this->type == ExpressionType::Single)
        {
            return this->token.type;
        }
        else
        {
            return this->expression.op.type; // Binary always has an operator
        }
    }

    char Expression::get_value()
    {
        return this->token.value;
    }
} // namespace expression
