#include <iostream>
#include <regex>
#include <string>

using namespace std;

void RegularExpression()
{
	string text = "int x = 10 + 5;";

	regex token_pattern(R"(int|x|[0-9]+|[+\-*/=;])");

	sregex_iterator iter(text.begin(), text.end(), token_pattern);
	std::sregex_iterator end;

	while (iter != end)
	{
		cout << "Token: " << iter->str() << endl;
		++iter;
	}
}

enum TokenType
{
	KEYWORD,
	IDENTIFIER,
	NUMBER,
	OPERATOR
};

struct Token
{
	TokenType type;
	string value;
};

void Tok()
{
	vector<pair<regex, TokenType>> token_patterns; //�켱 ������� ��ū Ÿ�� �ֱ�

	token_patterns.push_back({ regex(R"(int|if|else|for|while|return)"), KEYWORD });  // �����
	token_patterns.push_back({ regex(R"([a-zA-Z_][a-zA-Z0-9_]*)"), IDENTIFIER });  // �ĺ���
	token_patterns.push_back({ regex(R"([0-9]+)"), NUMBER });  // ����
	token_patterns.push_back({ regex(R"([+\-*/=;])"), OPERATOR });  // ������

	int patternSize = token_patterns.size();

	vector<Token> tokens;

	smatch match;
	string line;
	while (true)
	{
		cout << "- �ڵ� �Է�: ";
		getline(cin, line);

		if (cin.eof())
		{
			break;
		}

		if (line.empty())
		{
			continue;
		}

		string::const_iterator searchStart(line.begin());


		while (searchStart != line.end())
		{
			bool matched = false;
			for (const auto& p : token_patterns)
			{
				regex pattern = p.first;
				TokenType type = p.second;
				if (regex_search(searchStart, line.cend(), match, pattern) && match.prefix().first == searchStart)
				{
					Token token;
					token.type = type;
					token.value = match.str();

					tokens.push_back(token);

					searchStart = match.suffix().first;

					matched = true;
				}
			}
			if (matched == false)
			{
				cout << "��� ������ ��ū�� �����ϴ�. " << *searchStart << endl;
			}
		}
	}
	cin.clear();

	for (auto token : tokens)
	{
		cout << "Type: " << token.type << ", Value: " << token.value << "\n";
	}
}

int main()
{
	Tok();
}