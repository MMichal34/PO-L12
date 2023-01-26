class Food{
  int amount;
  string name;
public:
    Food(int a, string n):amount(a),name(n){};
    void eat(int am){amount -= am; if(amount<0){amount =0;}};
};

class Plate{
    int age;
    string material;
    Food * content;
public:
    Plate(int a, string m,int fa, string fn):(0),age(a),material(m){Food newfood = Food(fa,fn); content = &newfood;};
    Food * prepare(int a,string n){Food newfood = Food(fa,fn); content = &newfood; return content;}
    void clean_plate(content = nullptr;)
    void birthday(){age+=1;}
    void bite(int am;){content->eat(am);}
};


int main()
{
    Plate plat(12,"Glass",1000,"Meat");
    return 0;
}