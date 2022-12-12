#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <queue>
#include "texture.h"
#include "button.h"
#include "square.h"
#include "game.h"
#include "figure.h"
#include "king.h"
#include "man.h"
#include "manager.h"

int main(int argc, char **argv)
{
Game match;
match.loop();

match.quit();
return 0;
}
