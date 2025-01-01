#pragma once

class FileManager
{
	enum FindType
	{
		FILESYS = 1,
		FINDFIRST = 2,
		WIN = 3
	};
public:
	
	static string GetFileName(string extension);

private:
	static void GetFileNamesWithFileSystem(const string& path,vector<string>& v);
	static void GetFileNamesWith_findfirst(const string& path, vector<string>& v);
	static void GetFileNamesWithWinAPI(const string& path, vector<string>& v);

};