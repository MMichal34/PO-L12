#include "manager.h"
void Sprite_manager::set_manager(SDL_Renderer * render, SDL_Window * win, SDL_Surface * sc){renderer = render; window = win; screen = sc;}

void Sprite_manager::add_texture(Texture * element){
        to_render.push(element);
    }

void Sprite_manager::render_all(){
        SDL_RenderClear(renderer);
        while(!to_render.empty()){
            SDL_RenderCopy(renderer,to_render.front()->get_img(),to_render.front()->get_src(), to_render.front()->get_rect());
            to_render.pop();
        }
        SDL_RenderPresent(renderer);
    }

SDL_Renderer * Sprite_manager::get_renderer(){return renderer;}

Sprite_manager::~Sprite_manager(){to_render.empty();}
