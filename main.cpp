#include <iostream>

#include "Stack.h"

struct Test
{
	int num;
	char c;
};

int main()
{
	Stack<Test, 10> stack;

	stack.add(Test{1, 2}).add(Test{2, 3}).add(Test{4, 5});

	std::cout << stack.get().c << " " << stack;

	return 0;
}