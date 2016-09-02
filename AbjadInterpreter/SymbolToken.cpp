#include "stdafx.h"
#include "SymbolToken.h"

//--------------------------------------------------------------------------------------------------

SymbolToken::SymbolToken( )
    : BaseToken( AbjadTypes::Tokens::t_symbol )
{
}

//--------------------------------------------------------------------------------------------------

const char*
SymbolToken::ParseToken( const char* s )
{
    Symbol = *s++;

    // Parse the rest of a Symbol (dollar, percent)
    while ( true )
    {
        unsigned char InputChar = *s++;

        if ( isalpha( InputChar ) || isdigit( InputChar ) )
        {
            Symbol += InputChar;
            continue;
        }

        if ( InputChar == '$' || InputChar == '%' )
        {
            Symbol += InputChar;
            return ++s;
        }

        return s;
    }
}

//--------------------------------------------------------------------------------------------------

const char*
SymbolToken::GetSymbol( const char* s )
{
    return Symbol.c_str( );
}

//--------------------------------------------------------------------------------------------------
