/* 
 * Abjad ine Editor gives the ability to move up and down lines,
 * insert and delete lines and load/save files from and into the disc.
 * 
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

#ifndef __ABJAD_LINE_EDITOR_H__
#define __ABJAD_LINE_EDITOR_H__

#include <string>
#include <vector>
#include <iostream>

class AbjadLineEditor
{
private:
	long									CurrentLine;
	std::vector<std::string>				LineTable;
	std::vector<std::string>::iterator		LineIterator;

public:
	AbjadLineEditor(void);
	~AbjadLineEditor(void);

public:
	void ExecuteOperation(std::string OperationLine);

private:
	void OpExit();
	void OpMoveUp();
	void OpMoveDown();
	void OpRemoveLine();
	void OpShowLine();
	void OpInsertLine();
	void OpCurrentLine();
	void OpTopLine();
	void OpBotLine();
};

#endif

