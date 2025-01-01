#pragma once

#include "framework.h"

#include "FileWriter.h"
#include "FileReader.h"

class Program
{
	enum CommandType
	{
		READ = 1,
		WRITE = 2,
		EXIT = 3
	};
public:
	Program();
	~Program();

	void Run();
	
private:
	FileWriter* writer;
	FileReader* reader;
};