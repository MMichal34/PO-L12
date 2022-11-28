#include <iostream>

using namespace std;

class Numbers{
    float a;
    float b;
public:
    Numbers(float c,float d):a(c),b(d){};
    void setnumbers(float c,float d){a=c;b=d;};
    float max(){return a>b ? a : b;};
    float min(){return a<b ? a : b;};
    float avg(){return (a+b)/2;};
    
};

int main()
{
    Numbers num(3.0f,4.0f);
    cout<<num.max()<<"\n";
    cout<<num.min()<<"\n";
    cout<<num.avg()<<"\n";
    return 0;
}
