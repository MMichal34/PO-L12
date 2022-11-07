#include <iostream>

using namespace std;

class Player
{
  int birth_year;
  float ranking;
  string name;
  string title;
public:
    Player(){};
    Player (int year, float ran, string nam, string tit):birth_year (year),
    ranking (ran), name (nam), title (tit)
  {
  };
  void finish_game (float difference)
  {
    ranking += difference;
  };
};

class Clock
{
  int player1_time;
  int player2_time;
  int added_time;
  bool player1_turn;
public:
  Clock (int pl1 = 10, int pl2 = 10, int add = 0, bool trn = true):player1_time (pl1), player2_time (pl2), added_time (add), player1_turn(trn)
  {
  };
  void tick ()
  {
    if (player1_turn)
      {
	player1_time -= 1;
      }
    else
      {
	player2_time -= 1;
      }
  };
  void end_turn()
  {
    if (player1_turn)
      {
	player1_time += added_time;
      }
    else
      {
	player2_time += added_time;
      }
    player1_turn = !player1_turn;
  };
  bool flag ()
  {
    if (player1_time == 0 || player2_time == 0)
      {
	return true;
      }
    return false;
  };
};

class Chess_game
{
  Player players[2];
  Clock time;
  int year;
  string tournament;
public:
    Chess_game(){};
    Chess_game (int year1, float ran1, string nam1, string tit1, int year2,
		float ran2, string nam2, string tit2, int yr, string trt):year(yr), tournament(trt)
  {
    players[0] = Player (year1, ran1, nam1, tit1);
    players[1] = Player (year2, ran2, nam2, tit2);
  };
  void finish_match(int ranking_change){players[0].finish_game(ranking_change); players[1].finish_game(ranking_change*-1);}
};
int main ()
{
  Chess_game game(1990, 2773.0f, "Ian Nepomniachtchi","GM", 1992, 2799.0f, "Ding Liren", "GM", 2023, "World Championship");

  return 0;
}
