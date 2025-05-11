#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

class token
{
public:
    enum TokenType
    {
        Op,
        Atom
    };

private:
    char _value;
    TokenType _type;
    int precedence[2];

public:
    token(char value)
    {
        this->_value = value;
        if (isalnum(value))
        {
            this->_type = Atom;
        }
        else
        {
            this->_type = Op;
        }
    };
    ~token();
};

#endif // !__TOKEN_H__