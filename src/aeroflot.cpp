#include "aeroflot.h"
#include <iostream>

Aeroflot::Aeroflot() : dstPoint(), planeType(), number()
{
	std::cout << "Конструктор (без параметров): Aeroflot\n";
}

Aeroflot::Aeroflot(std::string dstPoint, std::string planeType, std::string number)
    : number(number), dstPoint(dstPoint), planeType(planeType)
{
	std::cout << "Конструктор (с параметрами): Aeroflot\n";
}

Aeroflot::Aeroflot(Aeroflot &other) : number(other.number), dstPoint(other.dstPoint), planeType(other.planeType)
{
	std::cout << "Конструктор (копирования): Aeroflot\n";
}

void Aeroflot::setNumber(std::string number)
{
	this->number = number;
}

void Aeroflot::setPlaneType(std::string planeType)
{
	this->planeType = planeType;
}

void Aeroflot::setDst(std::string dstPoint)
{
	this->dstPoint = dstPoint;
}

std::string Aeroflot::getDst()
{
	return dstPoint;
}

std::string Aeroflot::getPlaneType()
{
	return planeType;
}
std::string Aeroflot::getNumber()
{
	return number;
}

std::istream &operator>>(std::istream &is, Aeroflot &af)
{
	std::cout << "Введите номер рейса: ";
	is >> af.number;
	std::cout << "Введите тип самолёта: ";
	is >> af.planeType;
	std::cout << "Введите пункт назначения: ";
	is >> af.dstPoint;
	return is;
}

std::ostream &operator<<(std::ostream &os, Aeroflot &af)
{
	os << "Номер рейса: " << af.number << "; Тип самолёта: " << af.planeType << "; Пункт назначения: " << af.dstPoint;
	return os;
}

bool Aeroflot::operator<(Aeroflot &other)
{
	return dstPoint < other.dstPoint;
}
bool Aeroflot::operator>(Aeroflot &other)
{
	return dstPoint > other.dstPoint;
}
bool Aeroflot::operator==(Aeroflot &other)
{
	return dstPoint == other.dstPoint;
}
bool Aeroflot::operator<=(Aeroflot &other)
{
	return dstPoint <= other.dstPoint;
}
bool Aeroflot::operator>=(Aeroflot &other)
{
	return dstPoint >= other.dstPoint;
}

Aeroflot::~Aeroflot()
{
	std::cout << "Деструктор: Aeroflot\n";
}