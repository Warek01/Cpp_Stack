#pragma once

#include <ostream>
#include <cassert>

// Fixed size stack of type T and the limit of size max_size
template <typename T, int max_size>
class Stack
{
private:
	// Main container
	T m_arr[max_size - 1];
	// -1 == no elements
	int m_index = -1;

public:
	// -----------------------
	// Constructors
	Stack() {}

	// -----------------------
	// Destructors
	~Stack() {}

	// -----------------------
	// Methods

	int elementsLeft()
	{
		return m_index + 1;
	}

	bool hasElements()
	{
		return m_index >= 0;
	}
	
	/* Add element to top of stack */
	Stack& add(T element)
	{
		assert(elementsLeft() != max_size && "Stack is full");

		m_index++;
		m_arr[m_index] = element;

		return *this;
	}

	/* Get the top element */
	T get()
	{
		if (!hasElements()) return NULL;

		T data = m_arr[m_index];

		m_arr[m_index] = NULL;
		m_index--;

		return data;
	}

	/* Clear stack */
	Stack& empty()
	{
		while (m_index > -1)
		{
			m_arr[m_index] = NULL;
			m_index--;
		}

		return *this;
	}
};
