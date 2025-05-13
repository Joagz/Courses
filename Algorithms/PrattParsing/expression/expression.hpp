#ifndef __EXRESSION_H__
#define __EXRESSION_H__

#include <tuple>
#include <iostream>

namespace expression
{
    class Expression; 

    enum ExpressionType
    {
        Single,
        Binary
    };

    enum TokenType
    {
        Operator,
        Atom,
        Eof
    };

    typedef struct
    {
        char value;
        TokenType type;
        int lhs_precedence;
        int rhs_precedence;
    } Token;

    typedef struct
    {
        Token op;
        Expression* lhs;
        Expression* rhs;
    } BinaryExpression;

    class Expression
    {
    private:
        ExpressionType type;

        union
        {
            BinaryExpression expression;
            Token token;
        };

    public:
        Expression(/* args */)
        {
            this->type = Single;
            this->token.lhs_precedence = 0;
            this->token.rhs_precedence = 0;
            this->token.type = Eof;
            this->token.value = '\0';
        };

        Expression(Token op, Expression* lhs, Expression* rhs)
        {
            this->type = ExpressionType::Binary;
            BinaryExpression b;
            b.lhs = lhs;
            b.rhs = rhs;
            b.op = op;
            this->expression = b;
        }
        Expression(char value)
        {
            this->type = ExpressionType::Single;
            this->token.value = value;
            if (isdigit(value) || isalpha(value))
            {
                this->token.type = Atom;
            }
            else
            {
                this->token.type = Operator;
                switch (value)
                {
                case '-':
                    this->token.lhs_precedence = 1;
                    this->token.rhs_precedence = 2;
                    break;

                case '+':
                    this->token.lhs_precedence = 1;
                    this->token.rhs_precedence = 2;
                    break;

                case '*':
                    this->token.lhs_precedence = 3;
                    this->token.rhs_precedence = 4;
                    break;

                case '/':
                    this->token.lhs_precedence = 3;
                    this->token.rhs_precedence = 4;
                    break;

                default:
                    std::cout << "Invalid operator" << std::endl;
                    exit(-1);
                    break;
                }
            }
        };
        ~Expression() = default;

        std::tuple<int, int> get_infix_bp();
        char get_value();

        Token get_token()
        {
            return this->token;
        }

        BinaryExpression get_expression() {
            return this->expression;
        }

        TokenType get_type();
    };

}

#endif // !__EXRESSION_H__