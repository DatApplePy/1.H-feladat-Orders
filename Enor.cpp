#include "Enor.h"

Enor::Enor(const char* _inpath)
{
  _x.open(_inpath);
  if(_x.fail()) throw FILE_ERROR;
}

void Enor::next()
{
  if(_end = _x.fail()) return;

  std::string temp_name;
  temp_name = _dx.Meal_name;
  _dx.Total_prc = 0;

  while(!_x.fail() && temp_name == _dx.Meal_name)
  {
    _dx.Total_prc = _dx.Total_prc + (_dx.Meal_qty * _dx.Unit_prc);
    _curr = _dx;
    read();
  }
}
