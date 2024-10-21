#include "string_stack.h"

StringStack::StringStack() : size(0), first(nullptr), last(nullptr)
{
}
StringStack::StringStack(StringStack &other)
{
	StringElement *ptr = other.last;
	do
	{
		push(ptr->data);
	} while (++ptr != other.first);
}

void StringStack::push(std::string str)
{
	if (!first)
	{
		last = first = new StringElement(str);
		return;
	}
	StringElement *tmp = first;
	first = new StringElement(str);
	first->next = tmp;
	size++;
}
std::string StringStack::pop()
{
	if (!first)
	{
		throw "Пустой стек";
	}
	std::string ret = first->data;
	StringElement *tmp = first->next;
	delete first;
	first = tmp;
	if (size == 1)
	{
		last = tmp;
	}
	return ret;
}