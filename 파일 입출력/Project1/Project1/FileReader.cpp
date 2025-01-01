#include "FileReader.h"
#include "FileManager.h"

void FileReader::ReadFile()
{
	int input;

	while (true)
	{
		cout << FILE_READER_MODE_OPTION;
		cin >> input;

		switch (input)
		{
		case TEXT:
			ReadTextFile(FileManager::GetFileName(".txt"));
			break;
		case BINARY:
			ReadBinFile(FileManager::GetFileName(".bin"));
			break;
		default:
			cout << ERROR_INVALID_INPUT << "\n";
			continue;
		}
		break;
	}
}

void FileReader::ReadBinFile(string fileName)
{
	ifstream readFile(fileName, ios::binary);

	if (!readFile.is_open())
	{
		cout << ERROR_INVALID_FILENAME << endl;
		return;
	}
	
	uint8_t encoding;
	uint32_t len;

	while (readFile.read((char*)(&encoding), sizeof(encoding)))//read 함수는 binary 일 때 사용하며, 구분자 개념없이 모든 데이터를 그대로 읽음
	{
		readFile.read((char*)(&len), sizeof(len));

		char* buffer = new char[len + 1]; //null-terminator 포함
		readFile.read(buffer, len);

		buffer[len] = '\0'; //null-terminator 설정
		cout << buffer << "\n";

		delete[] buffer;

		if (readFile.eof())
		{
			break;
		}
	}

	cout << "\n\n";

	readFile.close();
}

void FileReader::ReadTextFile(string fileName)
{
	ifstream readFile(fileName);

	if (!readFile.is_open())
	{
		cout << ERROR_INVALID_FILENAME << endl;
		return;
	}

	cout << FILE_READER_START_READ;
	string line;

	while (getline(readFile, line)) //줄 바꿈 문자를 구분자로 사용하며, 줄바꿈 문자를 버리고 나머지를 가져옴
	{
		cout << line << "\n";
	}

	cout << "\n";

	readFile.close();
}
