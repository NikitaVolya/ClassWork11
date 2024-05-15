
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
		reverse.pop();
	}
	return text;
}

std::string reversPhrase(std::string text)
{
	std::stack<std::string> reverse;
	for (int i = 0;; i++)
	{
		int j = text.find(' ', i);
		std::string line = text.substr(i, j - i);
		reverse.push(line);

		i = text.find(' ', i);
		if (i == -1) break;
	}
	text.clear();
	while (!reverse.empty())
	{
		text.append(reverse.top());
		if (reverse.size() != 1)
			text += ' ';
		reverse.pop();
	}
	return text;
}

int main()
{
	std::cout << reversPhrase("English texts for beginners to practice reading and comprehension online and for free. Practicing your comprehension of written English  will both improve your vocabulary and understanding");

	return 0;
}