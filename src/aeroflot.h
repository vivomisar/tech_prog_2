#ifndef AEROFLOT_H
#define AEROFLOT_H
#include <string>
class Aeroflot
{
  private:
	std::string dstPoint;
	std::string planeType;
	std::string number;

  public:
	Aeroflot();
	Aeroflot(std::string, std::string, std::string);
	Aeroflot(const Aeroflot &other);

	void setDst(std::string);
	void setPlaneType(std::string);
	void setNumber(std::string);

	std::string getDst();
	std::string getPlaneType();
	std::string getNumber();

	friend std::istream &operator>>(std::istream &, Aeroflot &);
	friend std::ostream &operator<<(std::ostream &, Aeroflot &);

	bool operator<(const Aeroflot &) const;
	bool operator>(const Aeroflot &) const;
	bool operator==(const Aeroflot &) const;
	bool operator<=(const Aeroflot &) const;
	bool operator>=(const Aeroflot &) const;

	~Aeroflot();
};
#endif