#include <iostream>
#include <sstream>
using namespace std;
class Compute{
int current_data;
int current_elf;
int max_elf;
int max_data;
public:
Compute():current_elf(1),current_data(0),max_data(0),max_elf(0){};
void load(){
    int energy;
    string line;
    while (getline(cin, line))
{
    if (line.empty()){
    if (current_data>max_data){
        max_data = current_data;
        max_elf = current_elf;
    }
    current_elf+=1;
    current_data = 0;
    }
    else{
    energy = atoi(line.c_str());
    current_data+=energy;
    }
}
if (current_data>max_data){
        max_data = current_data;
        max_elf = current_elf;
    }
}
void show(){
    cout<<"Elf nr "<<max_elf<<" with "<<max_data<<" energy"; 
}    
};
int main()
{
    Compute comp;
    comp.load();
    comp.show();
    return 0;
}