#include <iostream>

using namespace std;
class Animal
{
    protected:
  string species;
  int legs_number;
  bool marine_animal;
  bool can_fly;
public:
    Animal (string sp, int le, bool mar, bool can):species (sp),
    legs_number (le), marine_animal (mar), can_fly (can)
  {
  };
  virtual string name () = 0;
};

class Mammal:public Animal
{
  string genus;
  bool tail;
  bool opposable_thumbs;
  bool can_swim;
  public:
    Mammal (string sp, int le, bool mar, bool can, string ge, bool ta,
	    bool op, bool sw):Animal (sp, le, mar, can), genus (ge),
    tail (ta), opposable_thumbs (op), can_swim (sw)
  {
  };
  string name ()
  {
    return this->species;
  };
};

int main ()
{
  Mammal Guinea_pig ("Cavia porcellus", 4, false, false, "Cavia", false,
		     false, false);

  return 0;
}
