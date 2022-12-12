#include "man.h"

int Man::mov(int nx, int ny,std::vector <Square*> & brd){
    int returned = NULL;
    brd[8*y+x]->set_id(NULL);
    brd[8*ny+nx]->set_id(id);
    brd[8*ny+nx]->set_pc(white);
    image->set_pos(nx,ny,50,50);
    bool capture = (nx-x)*(nx-x)>1;
    if(capture){returned = brd[((ny-y)/2+y)*8+(nx-x)/2+x]->get_id();}
    x = nx;
    y = ny;
    for(auto &squ : brd){
        squ->mark(false);
    }
    return returned;
}

bool Man::can_capture(std::vector <Square*> & brd){
    if((x-1>=0&&y-1>=0&&x-2>=0&&y-2>=0)&&brd[(y-1)*8+x-1]->get_id()!=NULL&&(brd[(y-1)*8+x-1]->get_pc()!=white)&&brd[(y-2)*8+x-2]->get_id()==NULL){
                return true;}
    if((x-1>=0&&y+1<8&&x-2>=0&&y+2<8)&&brd[(y+1)*8+x-1]->get_id()!=NULL&&(brd[(y+1)*8+x-1]->get_pc()!=white)&&brd[(y+2)*8+x-2]->get_id()==NULL){
                return true;}
    if((x+1<8&&y-1>=0&&x+2<8&&y-2>=0)&&brd[(y-1)*8+x+1]->get_id()!=NULL&&(brd[(y-1)*8+x+1]->get_pc()!=white)&&brd[(y-2)*8+x+2]->get_id()==NULL){
                return true;}
    if((x+1<8&&y+1<8&&x+2<8&&y+2<8)&&brd[(y+1)*8+x+1]->get_id()!=NULL&&(brd[(y+1)*8+x+1]->get_pc()!=white)&&brd[(y+2)*8+x+2]->get_id()==NULL){
                return true;}
    return false;
}

Man::Man(int xx, int yy, bool iswhite, int ii, SDL_Renderer * ren):Figure(xx,yy,50,50,ii,iswhite,ren){image = new Texture; image->loadTexture(iswhite ? "whiteman.png" : "blackman.png",ren,true); image->set_pos(xx,yy,50,50);}

int Man::handle(int mx, int my, std::vector <Square*> & brd, bool captured, int idd){
    if(mx>x*w&&mx<=(x+1)*w&&my>y*h&&my<=(y+1)*h){
        for (auto &r : brd){r->mark(false);}
        chosen = true;
            if((idd==id||idd==0)&&(x-1>=0&&y-1>=0&&x-2>=0&&y-2>=0)&&brd[(y-1)*8+x-1]->get_id()!=NULL&&(brd[(y-1)*8+x-1]->get_pc()!=white)&&brd[(y-2)*8+x-2]->get_id()==NULL){
                brd[(y-2)*8+x-2]->mark(true);}
            if((idd==id||idd==0)&&(x-1>=0&&y+1<8&&x-2>=0&&y+2<8)&&brd[(y+1)*8+x-1]->get_id()!=NULL&&(brd[(y+1)*8+x-1]->get_pc()!=white)&&brd[(y+2)*8+x-2]->get_id()==NULL){
                brd[(y+2)*8+x-2]->mark(true);}
            if((idd==id||idd==0)&&(x+1<8&&y-1>=0&&x+2<8&&y-2>=0)&&brd[(y-1)*8+x+1]->get_id()!=NULL&&(brd[(y-1)*8+x+1]->get_pc()!=white)&&brd[(y-2)*8+x+2]->get_id()==NULL){
                brd[(y-2)*8+x+2]->mark(true);}
            if((idd==id||idd==0)&&(x+1<8&&y+1<8&&x+2<8&&y+2<8)&&brd[(y+1)*8+x+1]->get_id()!=NULL&&(brd[(y+1)*8+x+1]->get_pc()!=white)&&brd[(y+2)*8+x+2]->get_id()==NULL){
                brd[(y+2)*8+x+2]->mark(true);}
            if(!captured&&white&&((x-1>=0&&y-1>=0)&&brd[(y-1)*8+x-1]->get_id()==NULL)){
                brd[(y-1)*8+x-1]->mark(true);}
            if(!captured&&white&&((x+1<8&&y-1>=0)&&brd[(y-1)*8+x+1]->get_id()==NULL)){
                brd[(y-1)*8+x+1]->mark(true);}
            if(!captured&&!white&&((x-1>=0&&y+1<8)&&brd[(y+1)*8+x-1]->get_id()==NULL)){
                brd[(y+1)*8+x-1]->mark(true);}
            if(!captured&&!white&&((x+1<8&&y+1<8)&&brd[(y+1)*8+x+1]->get_id()==NULL)){
                brd[(y+1)*8+x+1]->mark(true);}
            return id;
    }
    else{
        chosen = false;
        return -1;
    }

}

Figure * Man::promote(SDL_Renderer * ren){
    if((white&&y==0)||(!white&&y==7)){
    Figure * promoted = new King(x,y,white,id, ren);
    return promoted;
    }
    else{
        return nullptr;
    }
}

Man::~Man(){
image->destroy();
delete image;
}
