#include "stdafx.h"
#include "AbjadLineEditor.h"

//---------------------------------------------------------------
AbjadLineEditor::AbjadLineEditor(void)
{
	CurrentLine = -1;
}

//---------------------------------------------------------------
AbjadLineEditor::~AbjadLineEditor(void)
{
}

//---------------------------------------------------------------
void AbjadLineEditor::ExecuteOperation(std::string OperationLine)
{
	int OperationCount = 0;

	char LineBuffer[32];
	unsigned int OperationLineLength;
	unsigned char OperationChar;

	// Read the operation from the operation line, if there is none quit.
	OperationLineLength = OperationLine.length();

	if( OperationLineLength == 0 ) 
	{
		return;
	}

	// Operation to uppercase character
	OperationChar = ( OperationLine[0] & 0xDF );

	// Retrieve the operations count if there is any
	if( OperationLineLength >= 1 )
	{
		int IndexChar = 1;

		while ( IndexChar < OperationLineLength )
		{
			unsigned char ThisChar = OperationLine[IndexChar++];

			if( ThisChar >= '0' && ThisChar <= '9')
			{
				OperationCount = (OperationCount * 10) + (ThisChar - '0');
			}
		}
	}

	// Set default operation count is equal to 1, if not introduced explicitly.
	if( OperationCount == 0 )
	{
		OperationCount = 1;
	}

	// If the operation to be executed is not inserting whilst we have a blank line table, we shall inform the user of this.
	if( CurrentLine == -1 && OperationChar != 'I')
	{
		std::cout<< "The file is empty!" << std::endl;
	}

	// Execute the operation depending on the letter entered.
	switch(OperationChar)
	{
		case 'Q' :
			OpExit();
			break;

		case 'U' :
			OpMoveUp();
			break;

		case 'D' :
			OpMoveDown();
			break;
			
		case 'I' :
			OpInsertLine();
			break;

		case 'R' :
			OpRemoveLine();
			break;

		case 'S' :
			OpShowLine();
			break;

		case 'C' :
			OpCurrentLine();
			break;

		case 'T':
			OpTopLine();
			break;

		case 'B':
			OpBotLine();
			break;
	}
}

//---------------------------------------------------------------
// Q		: Exit.	
void AbjadLineEditor::OpExit()
{}

//---------------------------------------------------------------
// U		: Move one line up.
// Un:		: Move n lines up.
void AbjadLineEditor::OpMoveUp()
{}

//---------------------------------------------------------------
// D		: Move one line down. 
// Dn:		: Move n lines down.
void AbjadLineEditor::OpMoveDown()
{}

//---------------------------------------------------------------
// R		: Remove current line.
// Rn		: Remove n lines from current line position.
void AbjadLineEditor::OpRemoveLine()
{}

//---------------------------------------------------------------
// S		: Show all lines.
// Sn		: Shown the next n lines
void AbjadLineEditor::OpShowLine()
{}

//---------------------------------------------------------------
// I		: Place the editor on Insert mode whence lines may be entered.
void AbjadLineEditor::OpInsertLine()
{}

//---------------------------------------------------------------
// C		: Display current line.
void AbjadLineEditor::OpCurrentLine()
{}

//---------------------------------------------------------------
// T		: Display top line
void AbjadLineEditor::OpTopLine()
{}

//---------------------------------------------------------------
// B		: Display bottom line
void AbjadLineEditor::OpBotLine()
{}