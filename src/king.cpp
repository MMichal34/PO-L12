#include "king.h"
int King::mov(int nx,int ny,std::vector <Square*> &brd){
    int returned = NULL;
    brd[8*y+x]->set_id(NULL);
    brd[8*ny+nx]->set_id(id);
    brd[8*ny+nx]->set_pc(white);
    image->set_pos(nx,ny,50,50);
    int xx = x;
    int yy = y;
    while(xx!=nx&&yy!=ny){
        xx += nx>x?1:-1;
        yy += ny>y?1:-1;
        if(brd[yy*8+xx]->get_id()!=NULL&&xx!=nx&&yy!=ny){
            returned = brd[yy*8+xx]->get_id();
            break;
        }
    }
    x = nx;
    y = ny;
    for(auto &squ : brd){
        squ->mark(false);
    }
    return returned;
}

bool King::can_capture(std::vector <Square*> & brd){
                int xx = x+1;
                int yy = y+1;
                while(xx<7&&yy<7){
                    if(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy+1)*8+xx+1]->get_id()==NULL){return true;}
                    else if((brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()==white)||(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy+1)*8+xx+1]->get_id()!=NULL)){break;}
                    xx+=1;
                    yy+=1;
                }
                xx = x+1;
                yy = y-1;
                while(xx<7&&yy>=1){
                    if(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy-1)*8+xx+1]->get_id()==NULL){return true;}
                    else if((brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()==white)||(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy-1)*8+xx+1]->get_id()!=NULL)){break;}
                    xx+=1;
                    yy-=1;
                }
                xx = x-1;
                yy = y+1;
                while(xx>=1&&yy<7){//x=5 y=0
                    if(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy+1)*8+xx-1]->get_id()==NULL){return true;}
                    else if((brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()==white)||(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy+1)*8+xx-1]->get_id()!=NULL)){break;}
                    xx-=1;
                    yy+=1;
                }
                xx = x-1;
                yy = y-1;
                while(xx>=1&&yy>=1){
                    if(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy-1)*8+xx-1]->get_id()==NULL){return true;}
                    else if((brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()==white)||(brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white&&brd[(yy-1)*8+xx-1]->get_id()!=NULL)){break;}
                    xx-=1;
                    yy-=1;
                }
                return false;
}

King::King(int xx, int yy, bool iswhite, int ii, SDL_Renderer * ren):Figure(xx,yy,50,50,ii,iswhite,ren){image = new Texture; image->loadTexture(iswhite? "whiteking.png" : "blackking.png",ren,true); image->set_pos(xx,yy,50,50);}

int King::handle(int mx, int my,std::vector <Square*> & brd,bool captured,int idd){
    if(mx>x*w&&mx<=(x+1)*w&&my>y*h&&my<=(y+1)*h){
        for (auto &r : brd){r->mark(false);}
        chosen = true;
            if(idd==id||idd==0){
                int xx = x+1;
                int yy = y+1;
                bool cancapture = false;
                while(xx<8&&yy<8){
                    if(!cancapture&&brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white){cancapture = true;}
                    else if(cancapture&&brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else if((cancapture&&brd[yy*8+xx]->get_id()!=NULL)||(brd[yy*8+xx]->get_id()!=NULL)&&brd[yy*8+xx]->get_pc()==white){break;}
                    xx+=1;
                    yy+=1;
                }
                xx = x+1;
                yy = y-1;
                cancapture = false;
                while(xx<8&&yy>=0){
                    if(!cancapture&&brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white){cancapture = true;}
                    else if(cancapture&&brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else if((cancapture&&brd[yy*8+xx]->get_id()!=NULL)||(brd[yy*8+xx]->get_id()!=NULL)&&brd[yy*8+xx]->get_pc()==white){break;}
                    xx+=1;
                    yy-=1;
                }
                xx = x-1;
                yy = y+1;
                cancapture = false;
                while(xx>=0&&yy<8){
                    if(!cancapture&&brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white){cancapture = true;}
                    else if(cancapture&&brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else if((cancapture&&brd[yy*8+xx]->get_id()!=NULL)||(brd[yy*8+xx]->get_id()!=NULL)&&brd[yy*8+xx]->get_pc()==white){break;}
                    xx-=1;
                    yy+=1;
                }
                xx = x-1;
                yy = y-1;
                cancapture = false;
                while(xx>=0&&yy>=0){
                    if(!cancapture&&brd[yy*8+xx]->get_id()!=NULL&&brd[yy*8+xx]->get_pc()!=white){cancapture = true;}
                    else if(cancapture&&brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else if((cancapture&&brd[yy*8+xx]->get_id()!=NULL)||(brd[yy*8+xx]->get_id()!=NULL)&&brd[yy*8+xx]->get_pc()==white){break;}
                    xx-=1;
                    yy-=1;
                }
            }
            if(!captured){
                int xx = x+1;
                int yy = y+1;
                while(xx<8&&yy<8){
                    if(brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else{break;}
                    xx+=1;
                    yy+=1;
                }
                xx = x+1;
                yy = y-1;
                while(xx<8&&yy>=0){
                    if(brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else{break;}
                    xx+=1;
                    yy-=1;
                }
                xx = x-1;
                yy = y+1;
                while(xx>=0&&yy<8){
                    if(brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else{break;}
                    xx-=1;
                    yy+=1;
                }
                xx = x-1;
                yy = y-1;
                while(xx>=0&&yy>=0){
                    if(brd[yy*8+xx]->get_id()==NULL){brd[yy*8+xx]->mark(true);}
                    else{break;}
                    xx-=1;
                    yy-=1;
                }

            }

            return id;

    }
    else{
        chosen = false;
        return -1;
    }
}

Figure * King::promote(SDL_Renderer * ren){
    return nullptr;
}

King::~King(){
image->destroy();
delete image;
}

