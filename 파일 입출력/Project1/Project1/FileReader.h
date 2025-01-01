#pragma once
#include "framework.h"

class FileReader
{
	enum ReadMode
	{
		TEXT = 1,
		BINARY = 2
	};
public:

	void ReadFile();

private:
	void ReadBinFile(string fileName);
	void ReadTextFile(string fileName);
};

