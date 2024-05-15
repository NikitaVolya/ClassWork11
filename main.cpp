
#include <iostream>
#include <stack>
#include <string>

std::string myReversString(std::string text)
{
	std::stack<char> reverse;
	for (int i = 0; i < text.size(); i++)
		reverse.push(text.at(i));
	text.clear();
	while (!reverse.empty())
	{
		text.push_back(reverse.top());
		if (reverse.size() != 1)
			text += ' ';
		reverse.pop();
	}
	return text;
}

std::string reversPhrase(std::string text)
{
	text = ' ' + text;
	std::stack<std::string> reverse;
	for (int i = 0; i != -1; i = text.find(' ', i + 1))
	{
		int j = text.find(' ', i + 1);
		std::string line = text.substr(i + 1, j - i - 1);
		line += ' ';
		reverse.push(line);
	}
	text.clear();
	while (!reverse.empty())
	{
		text.append(reverse.top());
		reverse.pop();
	}
	return text;
}

int main()
{
	std::cout << reversPhrase("English texts for beginners to practice reading and comprehension online and for free. Practicing your comprehension of written English  will both improve your vocabulary and understanding");

	return 0;
}