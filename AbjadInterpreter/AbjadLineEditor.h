#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Line.h"
#include "LineParser.h"

//--------------------------------------------------------------------------------------------------
/** Abjad Line Editor gives the ability to move up and down lines, insert and delete lines and
* load/save files from and into the disc.
* And eventually runs the interpreter's source code.
*
* U		: Move one line up.
* D		: Move one line down.
* Un:		: Move n lines up.
* Dn:		: Move n lines down.
*
* R		: Remove current line.
* Rn		: Remove n lines from current line position.
*
* S		: Show all lines.
* Sn		: Shown the next n lines
*
* C		: Display current line.
* T		: Display top line
* B		: Display bottom line
*
* I		: Place the editor on Insert mode whence lines may be entered.
* O		: Place current line on Overwrite mode.
*
* LFILE	: Loads a file from the disc.
* SFILE	: Saves a file to the disc.
*
* X		: Execute source code.
*
* Q		: Exit.
*/
class AbjadLineEditor
{
public:
    AbjadLineEditor( );

public:
    void ExecuteOperation( std::string OperationLine );

private:
    void OpExit( );

    void OpMoveUp( );
    void OpMoveDown( );

    void OpRemoveLine( );
    void OpInsertLine( char* LineBuffer );

    void OpShowLine( char* LineBuffer );
    void OpCurrentLine( char* LineBuffer );

    void OpTopLine( );
    void OpBotLine( );

private:
    long CurrentLine;

    std::vector< Line* > TableOfLines;
    std::vector< Line* >::iterator TableIterator;

    LineParser* BasicParser;
};

//--------------------------------------------------------------------------------------------------