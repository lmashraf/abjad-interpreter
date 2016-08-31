// AbjadInterpreter.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include "AbjadLineEditor.h"

//--------------------------------------------------------------------------------------------------

int
_tmain( int argc, _TCHAR* argv[] )
{
    std::string OperationLine;
    AbjadLineEditor AbjadEditor;

    std::cout << "Abjad Line Editor - version 0.5 Aleph\n" << std::endl;

    while ( true )
    {
        // Output the command prompt
        std::cout << "[Abjad]: ";
        std::getline( std::cin, OperationLine );

        AbjadEditor.ExecuteOperation( OperationLine );
    }

    return 0;
}

//--------------------------------------------------------------------------------------------------