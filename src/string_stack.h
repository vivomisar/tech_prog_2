#ifndef STRING_STACK_H
#define STRING_STACK_H
#include <string>

struct StringElement
{
	std::string data;
	StringElement *next;
	StringElement()
	{
	}
	StringElement(std::string data) : data(data), next(nullptr)
	{
	}
	StringElement(StringElement &other) : data(other.data), next(nullptr)
	{
	}
};

class StringStack
{
  private:
	StringElement *first;
	StringElement *last;
	int size;

  public:
	StringStack();
	StringStack(StringStack &other);
	void push(std::string);
	std::string pop();
	~StringStack();
};
#endif