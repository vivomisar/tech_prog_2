#include "string_stack.h"
#include <fstream>
#include <iostream>

void task1()
{
}

void task2()
{
	StringStack sentences;
	std::string path;
	std::cout << " >>";
	std::cin >> path;
	std::ifstream file(path);
	if (!file.is_open())
	{
		throw "Не удалось открыть файл";
	}
	std::string sentence;
	for (int i = 0; i < 3; ++i)
	{
		if (!getline(file, sentence, '.'))
		{
			throw "Предложений меньше трёх";
		};
		sentence += '.';
		sentences.push(sentence);
	}
	for (int i = 0; i < 3; ++i)
	{
		std::cout << sentences.pop() << "\n";
	}
}

int main()
{
	char choice;
	while (true)
	{
		std::cout << "Выберите задание:\n"
		          << "1 – Стандартные потоки;\n"
		          << "2 – Файловые и строковые потоки;\n>>";
		std::cin >> choice;
		if (choice == '0')
		{
			break;
		}
		switch (choice)
		{
		case '1':
			break;
		case '2':
			try
			{
				task2();
			}
			catch (const char *err)
			{
				std::cerr << err << '\n';
			}
			break;
		default:
			std::cout << "Введите корректный номер\n";
			break;
		}
	}
	return 0;
}