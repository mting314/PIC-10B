#ifndef GAME_H
#define GAME_H
#pragma once
#include <string>
#include <vector>

class Game {

public:
	Game(const std::string &p1, const std::string &p2, const int &input_rounds);
	void start_round() const;
	void print_board() const;
	bool winner() const;
	bool tie() const;
 	bool endphase();
	void update_board();
	void declare_winner() const;

private:
	std::vector <std::string> board;
	Person * player1;
	Person * player2;
	int max_rounds, current_round; //number of rounds to be played, and current round number
	Person *  current_player; //points to active player
	Person *  waiting_player; //player who is not placing a marker
};

#endif