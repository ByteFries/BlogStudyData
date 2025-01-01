#pragma once
class FileWriter
{
    enum class WriteMode
    {
        TEXT = 1,
        BINARY = 2
    };

    enum class FileAction
    {
        OLDFILE = 1,
        NEWFILE = 2
    };

    enum class FileOpenMode
    {
        TRUNC = ios::trunc,
        APP = ios::app
    };

public:
	void WriteFile();

private:
    string GetFileName(const string& extension);
    void WriteTextFile(const string& fileName, FileOpenMode mode);
    void WriteBinFile(const string& fileName, FileOpenMode mode);
};

