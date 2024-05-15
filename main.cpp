
#include <iostream>
#include <stack>
#include <string>

#include "Stack.h"

std::string myReversString(std::string text)
{
	Stack<char> revers;
	for (int i = 0; i < text.size(); i++)
		revers.push(text.at(i));
	text.clear();
	while (!revers.empty())
	{
		text.push_back(revers.top());
		revers.pop();
	}
	return text;
}

std::string reversPhrase(std::string text)
{
	text = ' ' + text;
	Stack<std::string> revers;
	for (int i = 0; i != -1; i = text.find(' ', i + 1))
	{
		int j = text.find(' ', i + 1) - (i + 1);
		std::string line = text.substr(i + 1, j);
		line += ' ';
		revers.push(line);
	}
	text.clear();
	while (!revers.empty())
	{
		text.append(revers.top());
		revers.pop();
	}
	return text;
}

int main()
{
	std::cout << reversPhrase("Hello world!");

	return 0;
}