#include "figure.h"
Figure::Figure(int xx,int yy,int ww,int hh,int idd,bool isw, SDL_Renderer * ren):x(xx),y(yy),w(ww),h(hh),id(idd),white(isw),chosen(false),image(nullptr){}
Texture * Figure::get_img(){return image;}
bool Figure::is_chosen(){return chosen;}
int Figure::get_id(){return id;}
void Figure::remove_piece(std::vector <Square*> & brd,bool prom){
    image->destroy();
    delete image;
    if(!prom){brd[8*y+x]->set_id(NULL);}
    }
SDL_Rect Figure::getpos(){SDL_Rect u = {x,y,w,h}; return u;}
Figure::~Figure(){image->destroy();delete image;};
