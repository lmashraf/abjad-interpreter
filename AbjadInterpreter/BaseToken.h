#pragma once

#include "AbjadTokenTypes.h"

#include <string>

//--------------------------------------------------------------------------------------------------
/** All tokens must derive from this token type. **/
class BaseToken
{
public:
    BaseToken( AbjadTypes::Tokens token );

public:
    AbjadTypes::Tokens GetType( );
    virtual const char* ParseToken( const char* s ) = 0;

private:
    AbjadTypes::Tokens TokenType;
};

//--------------------------------------------------------------------------------------------------
