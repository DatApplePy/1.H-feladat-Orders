#ifndef ENOR_H
#define ENOR_H

#include <iostream>
#include <fstream>
#include <sstream>

struct Order
{
  int Table;
  std::string Meal_name;
  std::string Date;
  int Meal_qty;
  int Unit_prc;
  int Total_prc;

  friend std::istream& operator>>(std::istream& in, Order& obj)
  {
    in >> obj.Meal_name >> obj.Date >> obj.Table >> obj.Meal_qty >> obj.Unit_prc;
    return in;
  }
};

class Enor
{
private:
  std::ifstream _x;
  Order _dx;
  Order _curr;
  bool _end;

  void read(){_x >> _dx;}
public:
  enum ERROR {FILE_ERROR};

  Enor(const char* _inpath);
  ~Enor(){_x.close();}
  void first(){read(); next();}
  void next();
  bool end(){return _end;}
  Order current(){return _curr;}

};

#endif
