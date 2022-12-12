#ifndef figure_h
#define figure_h

#include <vector>
#include "texture.h"
#include "square.h"

class Figure{
protected:
int x;
int y;
int w;
int h;
int id;
bool white;
bool chosen;
Texture * image;
public:
virtual int mov(int,int,std::vector <Square*> &)=0;
virtual bool can_capture(std::vector <Square*> &)=0;
Figure(int xx,int yy,int ww,int hh,int idd,bool isw, SDL_Renderer * ren);
Texture * get_img();
bool is_chosen();
int get_id();
void remove_piece(std::vector <Square*> & brd,bool prom);
SDL_Rect getpos();
virtual int handle(int, int, std::vector <Square*> &,bool, int) = 0;
virtual Figure * promote(SDL_Renderer * ) = 0;
~Figure();
};
#endif // figure_h
