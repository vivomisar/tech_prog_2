#include "keeper.h"
#include "string_stack.h"
#include <fstream>
#include <iostream>

void task1()
{
	std::string edit;
	Keeper keeper;
	char choice;
	int index;

	while (true)
	{

		choice = 0;
		std::cout << "1 – Добавить элемент;\n"
		          << "2 – Удалить элемент;\n"
		          << "3 – Вывести все элементы;\n"
		          << "4 – Вывести элемент;\n"
		          << "5 – Изменить элемент;\n"
		          << "6 – Искать по самолёту;\n"
		          << "0 – Выход из программы.\n>> ";
		std::cin >> choice;
		if (choice == '0')
		{
			break;
		}
		switch (choice)
		{
		case '1': /* Добавить элемент */
		{
			Aeroflot tmp;
			std::cin >> tmp;
			keeper.add(tmp);
			break;
		}
		case '2': /* Удалить элемент */
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			try
			{
				keeper.remove(index);
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			break;
		case '3': /* Вывести все элементы*/
			keeper.save(std::cout);
			break;
		case '4': /* Вывести элемент */
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			try
			{
				std::cout << keeper[index] << '\n';
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			break;
		case '5': /* Изменить элемент */
		{
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			std::cout << "1 – Название пункта назначения;\n"
			          << "2 – Номер рейса;\n"
			          << "3 – Тип самолёта;\n"
			          << "0 – Отмена;\n";
			std::cin >> choice;
			std::cin.ignore();
			switch (choice)
			{
			case '1':
				std::cout << "Введите название пункта назначения >> ";
				std::cin >> edit;
				keeper[index].setDst(edit);
				break;
			case '2':
				std::cout << "Введите номер рейса >> ";
				std::cin >> edit;
				keeper[index].setNumber(edit);
				break;
			case '3':
				std::cout << "Введите тип самолёта >> ";
				std::cin >> edit;
				keeper[index].setPlaneType(edit);
				break;
			case '0':
				break;
			default:
				throw "Неверный выбор";
				break;
			}
			break;
		}
		case '6': /* Искать по самолёту */
			std::cout << "Введите тип самолёта >> ";
			std::cin >> edit;
			try
			{
				keeper.search(edit);
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			break;

		default:
			std::cerr << "Неверный параметр\n";
			break;
		}
	}
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
		          << "2 – Файловые и строковые потоки;\n"
		          << "0 – Выход;\n>>";
		std::cin >> choice;
		if (choice == '0')
		{
			break;
		}
		switch (choice)
		{
		case '1':
			task1();
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