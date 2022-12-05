#include <iostream>
#include <sstream>
using namespace std;
class Compute{
int points_total;
string first_part;
string second_part;
public:
Compute():points_total(0),first_part(""),second_part(""){};
void load(){
    string line;
    while (getline(cin, line))
{
   first_part = "";
   second_part = "";
   int leng = line.length();
   for (int i=0; i<=(leng/2)-1; i++){
       first_part+=line[i];
   }
   for (int i=leng/2; i<leng; i++){
       second_part+=line[i];
   }
   //cout<<first_part<<" "<<second_part<<endl;
   bool looking = true;
    for (auto &w : first_part){
        for(auto &p : second_part){
            if(w==p&&looking){looking = false;
            if(int(p)-96<0){
                points_total+=int(p)-96+58;
            }
            else{
                points_total+=int(p)-96;
            }
            }
        }
    }
    
}
}
void show(){
    cout<<"Sum of the priorities is "<<points_total; 
}    
};
int main()
{
    Compute comp;
    comp.load();
    comp.show();
    return 0;
}
