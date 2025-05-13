#ifndef __LEXER_H__
#define __LEXER_H__

#include "../expression/expression.hpp"
#include <algorithm>
#include <sstream>

namespace lexer
{

    class Lexer
    {
    private:
        std::vector<expression::Expression*> tokens;
        std::vector<expression::Expression*> tokenize(const char *str);

        expression::Expression* next();

        expression::Expression* peek();

    public:
        Lexer(const char *expression_str)
        {
            this->tokens = tokenize(expression_str);
            std::reverse(this->tokens.begin(), this->tokens.end());
        };
        ~Lexer() = default;

        expression::Expression *parse_expression(int min_bp);
    };

} // namespace lexer

#endif // !__LEXER_H__