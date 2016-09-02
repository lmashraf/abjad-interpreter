#include "stdafx.h"
#include "LiteralToken.h"

#include <iostream>

//--------------------------------------------------------------------------------------------------

LiteralToken::LiteralToken( )
    : BaseToken( AbjadTypes::Tokens::t_literal )
{
}

//--------------------------------------------------------------------------------------------------

const char*
LiteralToken::ParseToken( const char* s )
{
    unsigned char InputChar;

    Literal.clear( );

    ++s;

    // Parse the rest of a Literal
    while (true)
    {
        InputChar = *s++;
        if (InputChar == 0)
        {
            std::cout << "\t Error: Missing literal quotes" << std::endl;
            return nullptr;
        }

        if (InputChar == '\"')
        {
            Literal += InputChar;
            continue;
        }

        return s;
    }
}

//--------------------------------------------------------------------------------------------------