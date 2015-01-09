
#ifndef __ABJAD_SYMBOLTOKEN_H__
#define __ABJAD_SYMBOLTOKEN_H__

#include "BaseToken.h"

// Tokens that may contain a symbol
class SymbolToken : public BaseToken
{
	public:
		SymbolToken(void);
		~SymbolToken(void);
};

#endif