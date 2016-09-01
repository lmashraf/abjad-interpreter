#pragma once

#include "BaseToken.h"

#include <string>

//--------------------------------------------------------------------------------------------------
/** Tokens that may contain a symbol **/
class SymbolToken : public BaseToken
{
public:
    SymbolToken( );
    ~SymbolToken( );

public:
    const char* ParseToken(const char* s);
    const char* GetSymbol(const char* s);

private:
    std::string Symbol;
};

//--------------------------------------------------------------------------------------------------
