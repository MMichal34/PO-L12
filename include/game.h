#ifndef game_h
#define game_h

#include <vector>
#include "texture.h"
#include "button.h"
#include "square.h"
#include "figure.h"
#include "king.h"
#include "man.h"
#include "manager.h"

class Game{

std::vector <Figure*> white;
std::vector <Figure*> black;
std::vector <Square*> board;
std::vector <Button<Game>*> buttons;
Sprite_manager manager;
Texture * overlay;
bool white_turn;
bool can_catch;
int catch_id;
int next_id;
int marked;
bool quitt = false;

bool is_over();

public:

void close();

void restart();

Game();

~Game();

void manage_sprites();

void quit();

void handle_event();

void loop();

};
#endif // game_h
