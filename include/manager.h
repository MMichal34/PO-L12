#ifndef manager_h
#define manager_h
#include <queue>
#include "texture.h"
class Sprite_manager{
std::queue <Texture*> to_render;
SDL_Window * window;
SDL_Surface * screen;
SDL_Renderer * renderer;

public:
    void set_manager(SDL_Renderer * render, SDL_Window * win, SDL_Surface * sc);
    void add_texture(Texture * element);
    void render_all();
    SDL_Renderer * get_renderer();
    ~Sprite_manager();
};

#endif // manager_h
