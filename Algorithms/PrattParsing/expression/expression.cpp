#include "expression.hpp"

namespace expression
{
    int *Expression::get_infix_bp()
    {
        if (this->type == ExpressionType::Single)
        {
            return nullptr;
        }

        return this->token.precedence;
    }

    TokenType Expression::get_type()
    {
        if (this->type != ExpressionType::Single)
        {
            return Eof;
        }
        return this->token.type;
    };

    char Expression::get_value() {
        return this->token.value;
    }
} // namespace expression
