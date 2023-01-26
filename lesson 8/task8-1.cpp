#include <iostream>
#include <vector>

using namespace std;

class Shiritori{
vector<string> words;
bool game_over;
public:
bool play(string word){
    bool tru= false;
    string last;
    if(!words.empty()){last = words.back();}
    if(words.empty()||(last[last.length()-1]==word[0])){
       tru = true;
       for (auto &b : words){
        if( b==word){tru = false;}
       }
       }
    if(tru){words.push_back(word);}
        else{game_over=true;}
    return tru;
}
string restart(){
words.clear();
game_over=false;
return "Game restarted";
}
void print_words(){
for(auto &b : words){
    cout<<b<<endl;
}
}
};
int main(){
    string a;

    Shiritori game;
    while(true){
    do{
        cin>>a;
    }while(game.play(a));
    game.print_words();
    game.restart();
    }
return 0;
}
