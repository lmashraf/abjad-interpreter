#include "stdafx.h"
#include "IntegerToken.h"

//--------------------------------------------------------------------------------------------------

IntegerToken::IntegerToken( )
    : BaseToken( AbjadTypes::Tokens::t_integer )
{
}

//--------------------------------------------------------------------------------------------------
const char*
IntegerToken::ParseToken( const char* s )
{
    unsigned char InputChar;

    Integer = *s++;

    // Parse the rest of an Integer
    while ( true )
    {
        InputChar = *s++;

        if ( isdigit( InputChar ) )
        {
            Integer += InputChar;
            continue;
        }

        return s;
    }
}

//--------------------------------------------------------------------------------------------------