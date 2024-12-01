#ifndef KEEPER_H
#define KEEPER_H
#include "aeroflot.h"
class Keeper
{
  private:
	Aeroflot *data;
	int size;
	int capacity;
	void setSize(int size);
	void normalize(int index);
	void sort();

  public:
	Keeper();
	Keeper(Keeper &other);
	Aeroflot &operator[](int index);
	void add(const Aeroflot &entity);
	void remove(int index);
	void search(std::string);
	~Keeper();
};
#endif