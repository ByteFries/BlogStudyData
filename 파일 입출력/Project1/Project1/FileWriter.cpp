#define NOMINMAX
#include "framework.h"
#include "FileWriter.h"
#include "FileManager.h"

void FileWriter::WriteFile()
{
	int input;
	FileOpenMode mode;

	while (true)
	{
		cout << FILE_WRITER_WRITE_MODE_OPTION;
		cin >> input;

		switch (input)
		{
		case 1:
			mode = FileOpenMode::TRUNC;
			break;
		case 2:
			mode = FileOpenMode::APP;
			break;
		default:
			cout << ERROR_INVALID_INPUT << endl;
			continue;
		}
		break;
	}

	while (true)
	{
		cout << FILE_WRITER_FILE_TYPE_PROMPT;
		cin >> input;

		switch (input)
		{
		case 1:
			WriteTextFile(GetFileName(".txt"), mode);
			break;
		case 2:
			WriteBinFile(GetFileName(".bin"), mode);
			break;
		default:
			cout << ERROR_INVALID_INPUT << endl;
			continue;
		}
		break;
	}
}


string FileWriter::GetFileName(const string& extension)
{
    int input;
    string fileName = "";

    while (true)
    {
        cout << FILE_WRITER_FILE_SELECTION_OPTION;
        cin >> input;

        switch (input)
        {
        case 1:
            return FileManager::GetFileName(extension);
        case 2:
            cout << FILE_WRITER_NEW_FILE_NAME;
            cin >> fileName;

            if (!fileName.ends_with(extension))
            {
                fileName += extension;
            }

            return fileName;
        default:
            cout << ERROR_INVALID_INPUT << endl;
            break;
        }
    }
}

void FileWriter::WriteTextFile(const string& fileName, FileOpenMode mode)
{
    ofstream writeFile(fileName, static_cast<ios_base::openmode>(mode));

    if (!writeFile.is_open())
    {
        cout << ERROR_INVALID_FILENAME<< endl;
        return;
    }

    string line;
    while (true)
    {
        cout << FILE_WRITER_ENTER_LINE_PROMPT;
        getline(cin, line);

        if (line.empty())
        {
            continue;
        }

        writeFile << line << "\n";

        if (cin.eof())
        {
            cin.clear();
            cout << FILE_WRITER_EOC_INPUT_CONFIRM << endl;
            break;
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ERROR_INVALID_INPUT << endl;
        }
    }

    writeFile.close();
    cout << "\n";
}

void FileWriter::WriteBinFile(const string& fileName, FileOpenMode mode)
{
    ofstream writeFile(fileName, ios::binary | static_cast<ios_base::openmode>(mode));

    if (!writeFile.is_open())
    {
        cout << "\n" << ERROR_INVALID_FILENAME << endl;
        return;
    }

    string line;
    while (true)
    {
        cout << FILE_WRITER_ENTER_LINE_PROMPT;
        getline(cin, line);

        if (line.empty())
        {
            continue;
        }

        uint8_t encoding = 1;
        uint32_t len = static_cast<uint32_t>(line.size());

        writeFile.write(reinterpret_cast<char*>(&encoding), sizeof(encoding));
        writeFile.write(reinterpret_cast<char*>(&len), sizeof(len));
        writeFile.write(line.c_str(), line.size());

        if (cin.eof())
        {
            cin.clear();
            cout << FILE_WRITER_EOC_INPUT_CONFIRM << endl;
            break;
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ERROR_INVALID_INPUT << endl;
        }
    }

    writeFile.close();
    cout << "\n";
}