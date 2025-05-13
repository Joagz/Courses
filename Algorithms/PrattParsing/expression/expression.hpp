#ifndef __EXRESSION_H__
#define __EXRESSION_H__

#include <iostream>

namespace expression
{

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

    class Expression
    {
    private:
        typedef struct
        {
            char op;
            char lhs;
            char rhs;
        } BinaryExpression;

        typedef struct
        {
            char value;
            TokenType type;
            int precedence[2];
        } Token;

        ExpressionType type;

        union
        {
            BinaryExpression expression;
            Token token;
        };

    public:
        Expression(/* args */) {
            this->type=Single;
            this->token.precedence[0] = 0;
            this->token.precedence[1] = 0;
            this->token.type=Eof;
            this->token.value='\0';
        };

        Expression(char op, char lhs, char rhs)
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

            if (isalnum(value))
            {
                this->token.type = Atom;
            }
            else
            {
                this->token.type = Operator;
                switch (value)
                {
                case '-':
                    this->token.precedence[0] = 1;
                    this->token.precedence[1] = 2;
                    break;

                case '+':
                    this->token.precedence[0] = 1;
                    this->token.precedence[1] = 2;
                    break;

                case '*':
                    this->token.precedence[0] = 3;
                    this->token.precedence[1] = 4;
                    break;

                case '/':
                    this->token.precedence[0] = 3;
                    this->token.precedence[1] = 4;
                    break;

                default:
                    std::cout << "Invalid operator" << std::endl;
                    exit(-1);
                    break;
                }
            }

            this->token.type = TokenType::Atom;
        };
        ~Expression() = default;

        int *get_infix_bp();
        char get_value();
        TokenType get_type();
    };

}

#endif // !__EXRESSION_H__