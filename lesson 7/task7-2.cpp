#include <iostream>
#include <sstream>
using namespace std;
class Compute{
int points_total;
public:
Compute():points_total(0){};
void load(){
    string line;
    while (getline(cin, line))
{
   if (line[0]=='A'&&line[2]=='X'){points_total+=4;}
   if (line[0]=='A'&&line[2]=='Y'){points_total+=8;}
   if (line[0]=='A'&&line[2]=='Z'){points_total+=3;}
   if (line[0]=='B'&&line[2]=='X'){points_total+=1;}
   if (line[0]=='B'&&line[2]=='Y'){points_total+=5;}
   if (line[0]=='B'&&line[2]=='Z'){points_total+=9;}
   if (line[0]=='C'&&line[2]=='X'){points_total+=7;}
   if (line[0]=='C'&&line[2]=='Y'){points_total+=2;}
   if (line[0]=='C'&&line[2]=='Z'){points_total+=6;}
}
}
void show(){
    cout<<points_total<<" points"; 
}    
};
int main()
{
    Compute comp;
    comp.load();
    comp.show();
    return 0;
}