#pragma once

#include "Line.h"

#include "AbjadEnums.h"

//--------------------------------------------------------------------------------------------------

/** All tokens must derive from this token type. **/
class BaseToken
{
private:
    TypeOfToken TokenType;

public:
    BaseToken( TypeOfToken token );

public:
    TypeOfToken GetType( );
    virtual const char* ParseToken( const char* s ) = 0;
};

//--------------------------------------------------------------------------------------------------
