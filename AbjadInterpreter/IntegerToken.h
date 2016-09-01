#pragma once

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------
/** Tokens that represent integers **/
class IntegerToken : public BaseToken
{
public:
    IntegerToken( );

public:
    const char* ParseToken( const char* s ) override;

private:
    std::string Integer;
};

//--------------------------------------------------------------------------------------------------
