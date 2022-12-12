#ifndef square_h
#define square_h

#include "texture.h"

class Square{
int x;
int y;
int w;
int h;
int piece_ID;
bool piece_color;
bool square_color;
Texture * image;
bool marked;
public:
    Square(int xx, int yy, bool iswhite, SDL_Renderer * ren);
    Texture * get_img();
    int get_id();
    void set_id(int id);
    void set_pc(bool c);
    int get_pc();
    int get_x();
    int get_y();
    void mark(bool mrk);
    bool handle(int mx,int my);
    void destroy();
    ~Square();
};
#endif // square_h
