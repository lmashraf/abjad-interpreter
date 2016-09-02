#pragma once

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------
/** Token that represent literals **/
class LiteralToken : public BaseToken
{
public:
    LiteralToken( );

public:
    const char* ParseToken( const char* s ) override;

private:
    std::string Literal;
};

//--------------------------------------------------------------------------------------------------