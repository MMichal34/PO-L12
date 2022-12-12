#ifndef button_h
#define button_h

#include "texture.h"
template <class T>
class Button{
T * cla;
Texture * image;
void (T::*fun)();
int x;
int y;
int w;
int h;
public:
Button(bool isreset, T * instance, void (T::*ff)(), SDL_Renderer * ren );
~Button();
void handle(int mx,int my);

void remove_button();

Texture * get_img();

};

template <class T>
Button<T>::Button(bool isreset, T * instance, void (T::*ff)(), SDL_Renderer * ren ):fun(ff),cla(instance),w(50),h(50),x(9),y(isreset?1:3){
    image = new Texture;
    image->loadTexture("buttons.png",ren);
    image->set_src(0, isreset?0:50,50,50);
    image->set_pos(x,y,w,h);
}

template <class T>
void Button<T>::handle(int mx,int my){
    if(mx>x*50&&mx<=(x*50+w)&&my>y*50&&my<=(y*50+h)){
            (cla->*fun)();
    }
}

template <class T>
void Button<T>::remove_button(){
image->destroy();
delete image;
}

template <class T>
Texture * Button<T>::get_img(){return image;}

template <class T>
Button<T>::~Button(){remove_button();}
#endif
