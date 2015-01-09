#pragma once

#ifndef __ABJAD_LINE_H__
#define __ABJAD_LINE_H__

#include <iostream>
#include <list>

#include "BaseToken.h"

class Line
{
	public:
		std::string				SourceLine;	// Source line as input by user.
		std::list<BaseToken*>	TokenList;	// A list of tokens that are found in the source/read line
};

#endif;