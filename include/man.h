#ifndef man_h
#define man_h

#include "figure.h"
#include "king.h"
#include "texture.h"
#include "square.h"

class Man : public Figure{
public:
int mov(int nx, int ny,std::vector <Square*> & brd);
bool can_capture(std::vector <Square*> & brd);
Man(int xx, int yy, bool iswhite, int ii, SDL_Renderer * ren);
int handle(int mx, int my, std::vector <Square*> & brd, bool captured = false, int idd = 0);

Figure * promote(SDL_Renderer * ren);
~Man();
};
#endif // man_h

