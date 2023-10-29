#include <string>
#include <iostream>
#include "Utility.h"
#include "Console.h"

bool Utility::mGoodRead = false;

void Utility::WriteCentered(const std::string& msg, int rowOffset)
{
    int colOffset = (Console::GetWindowWidth() / 2) - (static_cast<int>(msg.size()) / 2);
    rowOffset = (Console::GetWindowHeight() / 2) + rowOffset;

    if (colOffset < 0)
        colOffset = 0;
    else if (colOffset >= Console::GetWindowWidth())
        colOffset = Console::GetWindowWidth() - 1;

    if (rowOffset < 0)
        rowOffset = 0;
    else if (rowOffset >= Console::GetWindowHeight())
        rowOffset = Console::GetWindowHeight() - 1;

	Console::SetCursorPosition(colOffset, rowOffset);
	Console::Write(msg);
}

void Utility::WaitForEnterKey(bool msg)
{
	if(msg)
	{
		WriteCentered("Press enter to Continue", Console::GetWindowHeight() / 2);
	}

	std::cin.ignore();
}

int Utility::ReadInt()
{
	std::string raw = "";
	int result = 0;

	try
	{
		std::cin >> raw;
		result = std::stoi(raw);
		mGoodRead = true;
	}
	catch(...)
	{
		mGoodRead = false;
	}

	return result;
}

bool Utility::IsReadGood()
{
	return mGoodRead;
};