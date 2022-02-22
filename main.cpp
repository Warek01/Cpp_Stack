#include <iostream>

#include "Stack.h"

int main()
{
	Stack<int, 10> stack;

	stack.add(10).add(9);

	stack.empty();
	stack.add(1);

	std::cout << stack.elementsLeft() << " " << stack.get() << "\n" << stack.get() << "\n" << stack.get() << "\n" << stack.get();

	return 0;
}