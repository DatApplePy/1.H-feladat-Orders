#include <iostream>
#include "Enor.h"

int main()
{
  try
  {
    Enor t("inp.txt");
    std::string Item;
    int Max;
    t.first();
    Item = t.current().Meal_name;
    Max = t.current().Total_prc;
    for(t.next(); !t.end(); t.next())
    {
      if(t.current().Total_prc > Max)
      {
        Item = t.current().Meal_name;
        Max = t.current().Total_prc;
      }
    }

    std::cout << Item << std::endl;
  }
  catch(Enor::ERROR error)
  {
    if(error == Enor::FILE_ERROR) std::cout << "File cannot be open!" << std::endl;
  }

  return 0;
}
