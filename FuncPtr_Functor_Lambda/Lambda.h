#pragma once
#include "framework.h"

class LambdaCounter
{
public:
	LambdaCounter() {}

	void AddOne()
	{
		[=]() {count++;}(); //¾Ï¹¬ÀûÀ¸·Î this°¡ Ä¸ÃÄ
	}

	int count = 0;
};

void Lambda();

template<typename T>
void TemplateFill(vector<int>& v, T func)
{
	int num = 0;

	while (func())
	{
		v.push_back(num++);
	}
}
