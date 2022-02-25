#pragma once

#include <ostream>
#include <cassert>

// Fixed size stack of type T and the limit of size max_size
template <typename T, int max_size>
class Stack
{
private:
	T m_arr[max_size - 1]; // Main container
	int m_index = -1; // -1 == no elements

public:
	Stack() {}
	~Stack() {}

	// -----------------------
	// Methods

	int elementsLeft() const
	{
		return m_index + 1;
	}

	bool isEmpty() const
	{
		return m_index == -1;
	}

	bool isFull() const
	{
		return elementsLeft() == max_size;
	}

	/* Add element to top of stack */
	Stack& add(T element)
	{
		assert(elementsLeft() != max_size && "Stack is full");
		m_arr[++m_index] = element;

		return *this;
	}

	/* Get the top element */
	T get()
	{
		assert(!isEmpty() && "Stack is empty");
		m_index--;
		return m_arr[m_index + 1];
	}

	/* Clear stack */
	Stack& empty()
	{
		m_index = -1;
		return *this;
	}

	// -----------------------
	// Operators

	friend std::ostream& operator<<(std::ostream& out, const Stack<T, max_size>& stack)
	{
		return (out << stack.elementsLeft());
	}
};
