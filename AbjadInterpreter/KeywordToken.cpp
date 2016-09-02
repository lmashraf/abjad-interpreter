#include "stdafx.h"
#include "KeywordToken.h"

//--------------------------------------------------------------------------------------------------

char* KeywordToken::Keywords[]
    = {"LET",    "FOR",     "TO",    "STEP",      "NEXT",      "DIM",   "IF",
       "THEN",   "ELSE",    "ENDIF", "READ",      "DATA",      "END",   "FUNCTION",
       "RETURN", "PROGRAM", "INPUT", "PRINT",     "INT",       "LEFT$", "RIGHT$",
       "MID$",   "CHR",     "ASC",   "PROCEDURE", "RANDOMIZE", "REM",   "RND"};

//--------------------------------------------------------------------------------------------------

const unsigned int KeywordToken::KeywordCount = sizeof(Keywords) / sizeof(char*);

//--------------------------------------------------------------------------------------------------

KeywordToken::KeywordToken( )
    : BaseToken( AbjadTypes::Tokens::t_keyword )
{
}

//--------------------------------------------------------------------------------------------------

const char*
KeywordToken::ParseToken( const char* s )
{
    // Compare the parameter s for the keyword on the list
    for (int KeywordIndex = 0; KeywordIndex < KeywordCount; ++KeywordIndex)
    {
        // Parse the keyword
        if ( strcmp( s, Keywords[ KeywordIndex ] ) == 0 )
        {
            Keyword = static_cast< AbjadTypes::Keywords >( KeywordIndex );
            return nullptr;
        }
    }

    return s;
}

//--------------------------------------------------------------------------------------------------