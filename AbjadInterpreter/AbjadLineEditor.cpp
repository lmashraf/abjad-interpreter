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
			OpInsertLine(LineBuffer);
			break;

		case 'R' :
			OpRemoveLine();
			break;

		case 'S' :
			OpShowLine(LineBuffer);
			break;

		case 'C' :
			OpCurrentLine(LineBuffer);
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
{
	exit(0);
}

//---------------------------------------------------------------
// I		: Place the editor on Insert mode whence lines may be entered.
void AbjadLineEditor::OpInsertLine(char* LineBuffer)
{
	std::string LineToInsert;

	int LineNumber  = CurrentLine + 1;
	int StartNumber = LineNumber;

	while( true )
	{
		// Readies the new line to reading from stream.
		CurrentLine++;
		sprintf(LineBuffer, "%8d", LineNumber + 1);
		std::cout << LineBuffer;
		std::getline(std::cin, LineToInsert);

		// Once at the EOF, break from the loop.
		if( std::cin.eof() )
		{
			break;
		}

		// Insert the new line into our vector of lines.
		TableOfLines.insert(TableOfLines.begin() + CurrentLine, LineToInsert);

		// Next line.
		LineNumber++;
	}

	// Clear inputs stream and saves the current line back.
	std::cin.clear();
	CurrentLine = StartNumber;
}

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
{
	if ( (CurrentLine + 1) == (TableOfLines.size()) )
	{
		if( CurrentLine == 0 )
		{
			TableOfLines.erase(TableOfLines.begin() + CurrentLine);
			CurrentLine = -1;

			return;
		}
		
		std::cout << "At the end of file" << std::endl;
		return;
	}
}

//---------------------------------------------------------------
// S		: Show all lines.
// Sn		: Shown the next n lines
void AbjadLineEditor::OpShowLine(char* LineBuffer)
{
	std::string		ThisLine;
	int				LineNumber = 1;

	TableIterator = TableOfLines.begin();
	while( TableIterator != TableOfLines.end() )
	{
		ThisLine = *(TableIterator);

		if( TableIterator == TableOfLines.begin() + CurrentLine )
		{
			sprintf(LineBuffer, "%8d*", LineNumber++);
		}
		else
		{
			sprintf(LineBuffer, "%8d", LineNumber++);
		}

		std::cout << LineBuffer << ThisLine << std::endl;
		++TableIterator;
	}

	return;
}

//---------------------------------------------------------------
// C		: Display current line.
void AbjadLineEditor::OpCurrentLine(char* LineBuffer)
{
	sprintf(LineBuffer, "%8d", CurrentLine + 1);
	std::cout << LineBuffer << TableOfLines[CurrentLine] << std::endl;

	return;
}

//---------------------------------------------------------------
// T		: Display top line
void AbjadLineEditor::OpTopLine()
{
	CurrentLine = -1;
	return;
}

//---------------------------------------------------------------
// B		: Display bottom line
void AbjadLineEditor::OpBotLine()
{
	CurrentLine = TableOfLines.size();
	return;
}