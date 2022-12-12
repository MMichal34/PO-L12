#include "texture.h"
Texture::Texture():x(0),y(0),w(0),h(0),texture(nullptr),src({0,0,50,50}),poz({0,0,0,0}){}

void Texture::loadTexture( std::string path, SDL_Renderer* ren , bool transparent){
        SDL_Surface * loaded = IMG_Load(path.c_str());
        if(transparent){SDL_SetColorKey( loaded, SDL_TRUE, SDL_MapRGB( loaded->format, 0xFF, 0xFF, 0xFF ) );}
        texture = SDL_CreateTextureFromSurface(ren, loaded);
        SDL_FreeSurface(loaded);
}

SDL_Rect * Texture::get_rect(){poz = {x,y,w,h}; return &poz;}

SDL_Rect * Texture::get_src(){return &src;}

void Texture::set_src(int x, int y, int w, int h){src = {x,y,w,h};}

SDL_Texture * Texture::get_img(){return texture;}

void Texture::set_pos(int xx,int yy,int ww, int hh){x=xx*50;y=yy*50;w=ww;h=hh;}

void Texture::destroy(){SDL_DestroyTexture(texture);}

Texture::~Texture(){destroy();}
