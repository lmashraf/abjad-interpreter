#pragma once

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------
/** Tokens which represent punctuations or separators **/
class PunctuationToken : public BaseToken
{
public:
    PunctuationToken( );

public:
    const char* ParseToken( const char* s ) override;

private:
    std::string Punctuation;
};

//--------------------------------------------------------------------------------------------------
