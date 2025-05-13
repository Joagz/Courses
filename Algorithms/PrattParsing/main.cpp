#include <iostream>
#include "token/token.hpp"

auto test_1 = [](){
    std::vector<token::Token> tokens = token::tokenize("a + b*c + d");

    for(auto t : tokens)
    {
        std::cout << t.type();
    }

    std::cout << std::endl;

};

int main(int argc, char const *argv[])
{
    std::cout << "Pratt Parsing Algorithm" << std::endl;


    test_1();

    // read expression from here

    return 0;
}

