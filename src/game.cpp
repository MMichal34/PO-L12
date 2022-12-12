#include "game.h"

bool Game::is_over(){
 return ((!white.empty())&&(!black.empty()));
}


void Game::close(){
    quitt = true;
}

void Game::restart(){
    int i = 0;
    for(auto &piece : white){
        piece->remove_piece(board,false);
    }
    for(auto &piece : black){
        piece->remove_piece(board,false);
    }
    while(!white.empty()){
        delete white[0];
        white.erase(white.begin());
    }
    while(!black.empty()){
        delete white[0];
        black.erase(black.begin());
    }
    white.empty();
    black.empty();
    white_turn = true;
    for(auto &sqr : board){
        sqr->set_id(NULL);
        sqr->set_pc(false);
    }
    next_id = 1;
    for(int y = 0; y<3;y++){
        for(int x = 0; x<8; x++){
            if((x+y)%2!=0){
                    Figure * newblack = new Man(x,y,false,next_id,manager.get_renderer());
                    black.push_back(newblack);
                    board[y*8+x]->set_id(next_id);
                    board[y*8+x]->set_pc(false);
                    next_id+=1;
            }
        }
    }
    for(int y = 5; y<8;y++){
        for(int x = 0; x<8; x++){
            if((x+y)%2!=0){
                    Figure * newwhite = new Man(x,y,true,next_id,manager.get_renderer());
                    white.push_back(newwhite);
                    board[y*8+x]->set_id(next_id);
                    board[y*8+x]->set_pc(true);
                    next_id+=1;
            }
        }
    }
}

Game::Game(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface * screen = SDL_GetWindowSurface(window);
    white_turn = true;
    can_catch = false;
    catch_id = 0;
    next_id = 1;
    marked = 0;
    manager.set_manager(renderer, window, screen);
    Button<Game> * reset = new Button<Game>(true, this, restart, renderer);
    buttons.push_back(reset);
    Button<Game> * exit = new Button<Game>(false, this, close, renderer);
    buttons.push_back(exit);
    overlay = new Texture;
    overlay->loadTexture("overlay.png",renderer);
    overlay->set_pos(0,0,400,400);
    for(int y = 0; y <8; y++){
        for(int x = 0; x<8; x++){
            Square * newsq = new Square(x,y,(x+y)%2==0,renderer);
            board.push_back(newsq);
        }
    }
    for(int y = 0; y<3;y++){
        for(int x = 0; x<8; x++){
            if((x+y)%2!=0){
                    Figure * newblack = new Man(x,y,false,next_id,renderer);
                    black.push_back(newblack);
                    board[y*8+x]->set_id(next_id);
                    board[y*8+x]->set_pc(false);
                    next_id+=1;
            }
        }
    }
    for(int y = 5; y<8;y++){
        for(int x = 0; x<8; x++){
            if((x+y)%2!=0){
                    Figure * newwhite = new Man(x,y,true,next_id,renderer);
                    white.push_back(newwhite);
                    board[y*8+x]->set_id(next_id);
                    board[y*8+x]->set_pc(true);
                    next_id+=1;
            }
        }
    }
}

void Game::manage_sprites(){
    for (auto &piece : board){
        manager.add_texture(piece->get_img());
    }
    for (auto &piece : white){
        manager.add_texture(piece->get_img());
    }
    for (auto &piece : black){
        manager.add_texture(piece->get_img());
    }
    for (auto &piece : buttons){
        manager.add_texture(piece->get_img());
    }
    if(!is_over()){
        manager.add_texture(overlay);
    }
    manager.render_all();

}

void Game::quit(){
IMG_Quit();
SDL_Quit();
}

void Game::handle_event(){
SDL_Event eve;
while(SDL_PollEvent(&eve)!=0){
    if(eve.type==SDL_QUIT){quit();}
    else if(eve.type==SDL_MOUSEBUTTONDOWN){
        int x,y;
        SDL_GetMouseState(&x,&y);
        for(auto &key : buttons){
            key->handle(x,y);
        }
        if(white_turn){
            bool catchable = false;
            for(auto &piece : white){
                    if(piece->can_capture(board)){catchable = true;}
            }

            for(auto &piece : white){
                int z = piece->handle(x, y, board, catchable,0);
                if(z!=-1){
                    marked = z;
                }
            }

        }
        else{
            bool catchable = false;
            for(auto &piece : black){
                    if(piece->can_capture(board)){catchable = true;}
            }
            for(auto &piece : black){
                int z = piece->handle(x, y, board,catchable,catch_id);
                if(z!=-1){
                    marked = z;
                }
            }
        }
        for(auto &squ : board){
            if(squ->handle(x,y)){
                int piece_index = 0;
                if(white_turn){
                    for(auto &piece : white){
                        if(marked==piece->get_id()){
                            int capture = piece->mov(squ->get_x(),squ->get_y(),board);
                            if(capture != NULL){
                                int todel;
                                int index = 0;
                                for(auto &captured : black){
                                    if(captured->get_id()==capture){
                                        captured->remove_piece(board,false);
                                        todel = index;
                                        break;
                                    }
                                    index+=1;

                                }
                                delete black[todel];
                                black.erase(black.begin()+todel);

                            }
                            if(piece->can_capture(board)&&capture!=NULL){
                                    catch_id = marked;
                            }
                            else{
                                Figure * newpiece = piece->promote(manager.get_renderer());
                                if(newpiece!=nullptr){
                                    piece->remove_piece(board,true);
                                    delete white[piece_index];
                                    white.erase(white.begin()+piece_index);
                                    white.push_back(newpiece);
                                }
                                catch_id = 0;
                                white_turn = !white_turn;
                                break;
                            }
                        }
                        piece_index+=1;
                    }
                }
                else{
                    for(auto &piece : black){
                        if(marked==piece->get_id()){
                            int capture = piece->mov(squ->get_x(),squ->get_y(),board);
                            if(capture != NULL){
                                int todel;
                                int index = 0;
                                for(auto &captured : white){
                                    if(captured->get_id()==capture){
                                        captured->remove_piece(board,false);
                                        todel = index;
                                        break;
                                    }
                                    index+=1;
                                }
                                delete white[todel];
                                white.erase(white.begin()+todel);

                            }
                            if(piece->can_capture(board)&&capture!=NULL){
                                    catch_id = marked;
                            }
                            else{
                                Figure * newpiece = piece->promote(manager.get_renderer());
                                if(newpiece!=nullptr){
                                    piece->remove_piece(board,true);
                                    delete black[piece_index];
                                    black.erase(black.begin()+piece_index);
                                    black.push_back(newpiece);
                                }
                                catch_id = 0;
                                white_turn = !white_turn;
                                break;
                            }
                        }
                        piece_index+=1;
                    }

                }
            }
        }
    }
    }
}

void Game::loop(){
    while(!quitt){
        handle_event();
        if(!is_over()){
            if(white.empty()){overlay->set_src(0,400,400,400);}
            else if(black.empty()){overlay->set_src(0,0,400,400);}
        }
        manage_sprites();
    }
}

Game::~Game(){
    overlay->destroy();
    delete overlay;
    for(auto &piece : white){
        piece->remove_piece(board,false);
    }
    for(auto &piece : black){
        piece->remove_piece(board,false);
    }
    for(auto &piece : buttons){
        piece->remove_button();
    }
    while(!white.empty()){
        delete white[0];
        white.erase(white.begin());
    }
    while(!black.empty()){
        delete black[0];
        black.erase(black.begin());
    }
    while(!board.empty()){
        delete board[0];
        board.erase(board.begin());
    }
    while(!buttons.empty()){
        delete buttons[0];
        buttons.erase(buttons.begin());
    }
}
