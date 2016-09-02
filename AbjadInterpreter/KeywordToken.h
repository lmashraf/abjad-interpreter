#pragma once

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------
/** Tokens that represent keywords **/
class KeywordToken : public BaseToken
{
public:
    KeywordToken( );

public:
    const char* ParseToken( const char* s ) override;

private:
    static char* Keywords[];
    AbjadTypes::Keywords Keyword;

    static const unsigned int KeywordCount;
};

//--------------------------------------------------------------------------------------------------
