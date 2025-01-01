#include "framework.h"
#include "FileManager.h"
#include <io.h>
#include <filesystem>

namespace fs = std::filesystem;

string FileManager::GetFileName(string extension)
{
	vector<string> fileNames;

	int input;
	string path = "./*" + extension;

	while (true)
	{
		cout << FILE_MANAGER_READ_GET_FILE_OPTION;
		cin >> input;

		switch (input)
		{
		case FILESYS:
			GetFileNamesWithFileSystem(extension, fileNames);
			break;
		case FINDFIRST:
			GetFileNamesWith_findfirst(path, fileNames);
			break;
		case WIN:
			GetFileNamesWithWinAPI(path, fileNames);
			break;
		default:
			cout << ERROR_INVALID_INPUT << endl;
			break;
		}
		break;
	}

	int fileCount = fileNames.size();

	while (true)
	{
		cout << FILE_MANAGER_FILE_NAMES;

		if (fileCount == 0)
		{
			cout << FILE_MANAGER_NO_FILES;
			break;
		}

		for (int i = 0; i < fileCount; i++)
		{
			cout << i + 1 << ". " << fileNames[i] << "\n";
		}

		cout << FILE_MANAGER_FILE_SELECT_PROMPT;
		cin >> input;

		if (input > fileCount)
		{
			cout << ERROR_INVALID_INPUT << endl;
		}
		else
		{
			break;
		}
	}
	cout << "\n";

	return fileNames[input - 1];
}

void FileManager::GetFileNamesWithFileSystem(const string& extension, vector<string>& fileNames) // C++ 17 이상
{
	string dir = "./";  //filesystem은 확장자명으로 필터링하지 못함

	for (const auto iter : fs::directory_iterator(dir))
	{
		if (iter.path().extension() == extension) //.확장자 로 비교해야함
		{
			fileNames.push_back(iter.path().filename().string());
		}
	}
}

void FileManager::GetFileNamesWith_findfirst(const string& path, vector<string>& fileNames) // Windows 전용, 표준 라이브러리 아님
{
	struct _finddata_t fd;
	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) != -1L)
	{
		do
		{
			fileNames.push_back(fd.name);
		} while (_findnext(handle, &fd) == 0);

		_findclose(handle);
	}
}

void FileManager::GetFileNamesWithWinAPI(const string& path, vector<string>& fileNames) // Windows 전용, 빠르고 고급 제어가 가능
{
	WIN32_FIND_DATAA findFileData;
	HANDLE hFind = FindFirstFileA(path.c_str(), &findFileData);
	
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			fileNames.push_back(findFileData.cFileName);
		} while (FindNextFileA(hFind, &findFileData) != 0);
	
		FindClose(hFind);
	}
}
