
#ifndef __ABJAD_BASETOKEN_H__
#define __ABJAD_BASETOKEN_H__

#include "Line.h"

#include "AbjadEnums.h"

// All tokens must derive from this token type.
class BaseToken
{
	private:
		TypeOfToken		TokenType;

	public:
		BaseToken(TypeOfToken token);

	public:
		TypeOfToken GetType(void);
		virtual const char* ParseToken(const char* s) = 0;
};

#endif
