#include "keeper.h"
#include "aeroflot.h"
#include <cstdlib>
#include <iostream>
Keeper::Keeper() : size(0), capacity(0), data(nullptr)
{
	std::cout << "Конструктор: Keeper (без параметров)\n";
}

Keeper::Keeper(Keeper &other)
{
	std::cout << "Конструктор: Keeper (копирования)\n";
}

void Keeper::sort()
{
	quickSort(0, size - 1);
}

int Keeper::partition(int low, int high)
{
	Aeroflot pivot = data[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (data[j] < pivot)
		{
			i++;
			std::swap(data[i], data[j]);
		}
	}
	std::swap(data[i + 1], data[high]);
	return i + 1;
}

void Keeper::quickSort(int low, int high)
{
	if (low < high)
	{
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

Aeroflot &Keeper::operator[](int index)
{
	return data[index];
}

void Keeper::save(std::ostream &os)
{
	for (int i = 0; i < size; ++i)
	{
		os << data[i] << '\n';
	}
}

void Keeper::setSize(int size)
{
	if (size < 0)
		throw "Некорректный размер массива";
	if (this->size == size)
		return;
	Aeroflot *tmp;
	if (this->size > 0)
	{
		tmp = new Aeroflot[this->size];
		for (int i = 0; i < this->size; ++i)
		{
			tmp[i] = data[i];
		}

		delete[] data;
		data = nullptr;
	}
	if (size == 0)
		return;
	data = new Aeroflot[size];
	for (int i = 0; i < this->size; ++i)
	{
		data[i] = tmp[i];
	}
	this->size = this->capacity = size;
}

void Keeper::add(Aeroflot entity)
{
	if (capacity == size)
		setSize(size + 1);
	data[size - 1] = entity;
	sort();
}

void Keeper::normalize(int index)
{
	for (int i = index; i < size - 1; ++i)
	{
		data[i] = data[i + 1];
	}
}

void Keeper::remove(int index)
{
	if (index < 0 || index > size)
		throw "Некорректный индекс";
	normalize(index);
	setSize(size - 1);
}

void Keeper::search(std::string planeType)
{
	bool contains = false;
	for (int i = 0; i < size; ++i)
	{
		if (data[i].getPlaneType() == planeType)
		{
			contains = true;
			std::cout << data[i] << "\n";
		}
	}
	if (!contains)
	{
		throw "Таких самолётов нет";
	}
}

Keeper::~Keeper()
{
	setSize(0);
	std::cout << "Деструктор: Keeper\n";
}