#include "Program.h"

Program::Program()
{
	//std::locale::global(std::locale("en_US.UTF-16"));
	writer = new FileWriter();
	reader = new FileReader();
	locale currentLocale = std::locale();
	cout << "현재 로캘: " << currentLocale.name() << std::endl;
	//locale::global(std::locale("ko_KR.UTF-8"));
	//currentLocale = std::locale();
	//cout << "ko_KR.UTF-8로 변경 후 wcout 사용" << endl;
}

Program::~Program()
{
	delete writer;
	delete reader;
}

void Program::Run()
{
	while (true)
	{
		cout << PROGRAM_START;
		cout << MENU_OPTION;

		int input;
		cin >> input;

		switch (input)
		{
		case READ:
			reader->ReadFile();
			break;
		case WRITE:
			writer->WriteFile();
			break;
		case EXIT:
			cout << PROGRAM_EXIT << endl;
			return;
		default:
			cout << ERROR_INVALID_INPUT << endl;
			break;
		}
	}
}
