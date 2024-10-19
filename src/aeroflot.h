#ifndef AEROFLOT_H
#define AEROFLOT_H
#include <string>
class Aeroflot
{
  private:
	std::string dst_point;
	std::string plane_type;
	int number;

  public:
	Aeroflot();
	Aeroflot(std::string, std::string, int);
	Aeroflot(Aeroflot &other);
	~Aeroflot();
};
#endif