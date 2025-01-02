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
	vector<pair<regex, TokenType>> token_patterns; //우선 순위대로 토큰 타입 넣기

	token_patterns.push_back({ regex(R"(int|if|else|for|while|return)"), KEYWORD });  // 예약어
	token_patterns.push_back({ regex(R"([a-zA-Z_][a-zA-Z0-9_]*)"), IDENTIFIER });  // 식별자
	token_patterns.push_back({ regex(R"([0-9]+)"), NUMBER });  // 숫자
	token_patterns.push_back({ regex(R"([+\-*/=;])"), OPERATOR });  // 연산자

	int patternSize = token_patterns.size();

	vector<Token> tokens;

	smatch match;
	string line;
	while (true)
	{
		cout << "- 코드 입력: ";
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
				cout << "사용 가능한 토큰이 없습니다. " << *searchStart << endl;
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