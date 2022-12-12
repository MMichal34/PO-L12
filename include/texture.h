#ifndef texture_h
#define texture_h

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Texture{
    int x;
    int y;
    int w;
    int h;
    SDL_Texture * texture;
    SDL_Rect poz;
    SDL_Rect src;
public:
    Texture();
    void loadTexture( std::string path, SDL_Renderer* ren , bool transparent = false);
    SDL_Rect * get_rect();
    SDL_Rect * get_src();
    void set_src(int x, int y, int w, int h);
    SDL_Texture * get_img();
    ~Texture();
    void set_pos(int xx,int yy,int ww, int hh);
    void destroy();
};

#endif // texture_h
