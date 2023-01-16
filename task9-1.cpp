#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class Sequence{
public:
    virtual string printedSeq() = 0;
};
class Characters : public Sequence{
    string text;
    public: 
    Characters(){};
    string printedSeq(){return "AbCdEfG";};
};
class LowerCased : public Sequence{
    string text;
    public:
    LowerCased(string t):text(t){};
    string printedSeq(){
        string t ="";
        for(int i=0; i<strlen(text.c_str());i++){
            t+=tolower(text[i]);
        }
        return t;}
};
class Substring: public Sequence{
    string text;
    public:
    Substring(string t):text(t){};
    string printedSeq(){
        string t ="";
        for(int i=0; i<strlen(text.c_str())/2;i++){
            t+=text[i];
        }
        return t;}
};
class Concatenation: public Sequence{
    string text;
    public:
    Concatenation(string t):text(t){};
    string printedSeq(){
        string t = text+text;
        
        return t;}
};
int main()
{
    Characters ch;
    LowerCased dek1(ch.printedSeq());
    Substring dek2(dek1.printedSeq());
    Concatenation dek3(dek2.printedSeq());
    cout<<ch.printedSeq()<<endl;
    cout<<dek1.printedSeq()<<endl;
    cout<<dek2.printedSeq()<<endl;
    cout<<dek3.printedSeq()<<endl;

    return 0;
}
