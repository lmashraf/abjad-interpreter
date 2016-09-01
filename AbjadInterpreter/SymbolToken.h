#pragma once

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------
/** Tokens that may contain a symbol **/
class SymbolToken : public BaseToken
{
public:
    SymbolToken( );

public:
    const char* ParseToken( const char* s ) override;

public:
    const char* GetSymbol( const char* s );

private:
    std::string Symbol;
};

//--------------------------------------------------------------------------------------------------
