#include <iostream>
using namespace std;
class Komputer
{
    int id;
    string model;
public:
    void zadanie(int i)
    {
        cout<<"Student "<<i<<" wykonal zadanie"<<endl;
    }
};

class Student
{
    string imie;
    string nazwisko;
    int wiek;
    int id;
    int ocena;
public:
    Student(string im,string n,int w,int i,int o): imie(im), nazwisko(n), wiek(w), id(i), ocena(o) {}
    void praca(Komputer * komp)
    {
        komp->zadanie(id);
    };

    void set_ocena(int oc)
    {
        ocena = oc;
        cout<<"Student "<<id<<" dostal "<<oc<<endl;
    };
};

class Wykladowca
{
    string imie;
    string nawisko;
    int wiek;
public:
    int ocen()
    {
        return 5;
    };

};
int main()
{
    Student st("A","B",20,123456,1);
    Komputer km;
    Wykladowca wk;
    return 0;
}
