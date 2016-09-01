#pragma once

#include <iostream>
#include <list>

#include "BaseToken.h"

//--------------------------------------------------------------------------------------------------

class Line
{
public:
    Line( );
    ~Line( );

public:
    std::string SourceLine;             // Source line as input by user.
    std::list< BaseToken* > TokenList;  // A list of tokens that are found in the source/read line
};

//--------------------------------------------------------------------------------------------------
