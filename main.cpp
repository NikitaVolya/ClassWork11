
#include <iostream>
#include <stack>
#include <string>

std::string myReverseString(std::string text)
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

int main()
{
	std::cout << myReverseString("Hello world!");

	return 0;
}