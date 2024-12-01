#include "keeper.h"
#include "aeroflot.h"
#include <algorithm>
#include <iostream>

void Keeper::sort()
{
	std::sort(data, data + size - 1);
}

Aeroflot &Keeper::operator[](int index)
{
	return data[index];
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

void Keeper::add(const Aeroflot &entity)
{
	if (capacity == size)
		setSize(size + 1);
	data[size - 1] = entity;
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