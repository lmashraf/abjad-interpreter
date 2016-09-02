#include "stdafx.h"
#include "PunctuationToken.h"

//--------------------------------------------------------------------------------------------------

PunctuationToken::PunctuationToken( )
    : BaseToken( AbjadTypes::Tokens::t_punctuation )
{
}

//--------------------------------------------------------------------------------------------------
/** Parse the rest of a punctuation sequence
 * This consists of ending up with either one, two or three characters in a punctuation string.
 * The sequence .. is accepted as a punctuation token, but it should be rejected by the compiler.
 **/
const char*
PunctuationToken::ParseToken( const char* s )
{
    unsigned char InputChar = *s++;

    Punctuation = InputChar;

    switch ( InputChar )
    {
    case '<':  // Looking for either <, <> or <=
        InputChar = *( ++s );
        if ( InputChar == '>' || InputChar == '=' )
        {
            // Considering both <> or <= tokens
            InputChar = *s++;
            Punctuation += InputChar;
            break;
        }
        break;

    case '>':  // Looking for either > or >=
        InputChar = *( ++s );
        if ( InputChar == '=' )
        {
            // Considering >= token
            InputChar = *s++;
            Punctuation += InputChar;
        }
        break;
    }

    return ++s;
}

//--------------------------------------------------------------------------------------------------