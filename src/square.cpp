#include "square.h"
Square::Square(int xx, int yy, bool iswhite, SDL_Renderer * ren):x(xx),y(yy),square_color(iswhite),w(50),h(50),marked(false),piece_ID(NULL){
        image = new Texture;
        image->loadTexture(iswhite ? "white.png" : "black.png",ren);
        image->set_pos(xx,yy,50,50);
    }
Texture * Square::get_img(){return image;}
int Square::get_id(){return piece_ID;}
void Square::set_id(int id){piece_ID = id;}
void Square::set_pc(bool c){piece_color  = c;}
int Square::get_pc(){return piece_color;}
int Square::get_x(){return x;}
int Square::get_y(){return y;}
void Square::mark(bool mrk){marked = mrk;if(mrk){image->set_src(50,0,50,50);}else{image->set_src(0,0,50,50);}}
bool Square::handle(int mx,int my){if((mx>x*w&&mx<=(x+1)*w&&my>y*h&&my<=(y+1)*h)&&marked){return true;} else{return false;}}
void Square::destroy(){image->destroy(); delete image;}
Square::~Square(){destroy();}
