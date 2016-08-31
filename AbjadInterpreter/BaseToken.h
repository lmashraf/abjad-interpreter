#pragma once

#include "Line.h"

#include "AbjadEnums.h"

//--------------------------------------------------------------------------------------------------

/** All tokens must derive from this token type. **/
class BaseToken
{
public:
    BaseToken( TypeOfToken token );

    TypeOfToken GetType( );
    virtual const char* ParseToken( const char* s ) = 0;

private:
    TypeOfToken TokenType;
};

//--------------------------------------------------------------------------------------------------
