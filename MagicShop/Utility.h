#pragma once

class Utility
{
	static bool mGoodRead;

public:
	static void WriteCentered(const std::string& msg, int rowOffset = 0);
	static void WaitForEnterKey(bool msg = true);
	static int ReadInt();
	static bool IsReadGood();
};