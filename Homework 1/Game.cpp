#include "Person.h"
#include "Game.h"

#include <iostream>

Game::Game(const std::string &p1, const std::string &p2, const int &input_rounds) : player1(new Person(p1, 'X')), player2(new Person(p2, 'O')), max_rounds(input_rounds), board({ "   ", "   ", "   " }), current_round(1)  //player 1 always starts on X, player 2 always starts on O, always starts on round 1, board starts "empty", no X's or O's
{

	current_player = player1; //always starts with player 1
	waiting_player = player2;
}

//Begins new round, states round number, states who has which marker, displays empty board
void Game::start_round() const
{
	std::cout << std::string(50, '\n'); //lots of new lines to clear screen to start round
	std::cout << "       Tic Tac Toe" << std::endl;
	std::cout << "       Round " << current_round << " of " << max_rounds << std::endl;
	std::cout << "     " << current_player->get_name() << " (" << current_player->get_marker() << ") - " << waiting_player->get_name() << " (" << waiting_player->get_marker() << ")" << std::endl;
	print_board();
}

//prints board with right shape and current markings
void Game::print_board() const {
	std::cout << "     1       2       3" << std::endl;
	std::cout << "         |       |" << std::endl;
	std::cout << "1    " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << std::endl;
	std::cout << "         |       |" << std::endl;
	std::cout << "  _______|_______|_______" << std::endl;
	std::cout << "         |       |" << std::endl;
	std::cout << "2    " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << std::endl;
	std::cout << "         |       |" << std::endl;
	std::cout << "  _______|_______|_______" << std::endl;
	std::cout << "         |       |" << std::endl;
	std::cout << "3    " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << std::endl;
	std::cout << "         |       |" << std::endl;
}

//looks for 3 in a row
bool Game::winner() const {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) //check horizontal
			return true;
	}

	for (int i = 0; i < 3; i++) {
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) //check vertical
			return true;
	}

	if (board[1][1] != ' ' && ((board[1][1] == board[2][2] && board[2][2] == board[0][0]) || (board[1][1] == board[2][0] && board[2][0] == board[0][2]))) //diagonal happens if middle matches topleft and bottom right, or bottom left and top right
		return true;

	return false; //if no line of 3 found, no winner yet
}

//checks if all spaces are filled
bool Game::tie() const
{
	return ((board[0].find(' ') == -1 && board[1].find(' ') == -1 && board[2].find(' ') == -1));
}

//checks if someone won with winner(), if not switches current_player and starts next round
//returns true if the last round has finished so the tournament should terminate, else false
bool Game::endphase() {
	bool won = winner();
	if (won || tie()) {
		if (won) {
			std::cout << current_player->get_name() << " won this round!" << std::endl; //winner will be whoever just went and made the board a "winning" one
			current_player->increase_score();
		}
		else std::cout << "It's a tie!" << std::endl;

		board = { "   ","   ","   " }; //reset board to blank

		current_round++;
		if (current_round > max_rounds)//played past numbers of games we wanted to play
		{
			declare_winner();
			return true; 
		}
		//switch markers of players
		player1->switch_marker();
		player2->switch_marker();

		//player 1 goes first on odd rounds
		if (current_round % 2 == 1)
		{
			current_player = player1;
			waiting_player = player2;
		}
		//player 2 goes first on even rounds
		else
		{
			current_player = player2;
			waiting_player = player1;
		}
		
		std::cout << "Press enter to start next round.";
		//Wait for player to press enter to continue
		std::cin.get();
		std::cin.get();
		start_round(); //start next round

	}
	else //this case happens if the game isn't won or tied yet
	{
		//switch players if round isn't over yet
		Person * temp = current_player;
		current_player = waiting_player;
		waiting_player = temp;
		temp = NULL;
	}
	return false;
}

//asks current player for position to mark
//makes sure input is valid, then calls print_board() to show updated board
void Game::update_board() {
	int xpos, ypos;

	bool valid = false;
	while (!valid) //making sure input is valid
	{
		std::cout << current_player->get_name() << " (" << current_player->get_marker() << ") Mark Location: ";
		std::cin >> xpos >> ypos;
		if (!std::cin.fail()) //make sure inputs were valid numbers
		{
			//decrement because std::strings and vectors are zero-indexed so actual position is one lower
			//we can only do this here because we made sure they were numbers in the first place
			xpos--;
			ypos--;
			if (xpos < 3 && ypos < 3 && xpos >= 0 && ypos >= 0) //make sure input in board
			{
				if (board[ypos][xpos] == ' ') //check if spot is already filled in
				{
					std::cout << std::endl;
					valid = true;
					break;
				}
				else std::cout << "That spot's already taken. Try again." << std::endl;
			}
			else std::cout << "That's outside the board. Try again." << std::endl;
		}
		else {
			std::cout << "Invalid input. Try again." << std::endl;
		}
		//if gets to this point, input failed to be valid, reset std::cin
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n'); //skip bad input
	}


	//marker placement

	board[ypos][xpos] = current_player->get_marker();
	std::cout << std::string(50, '\n'); //lots of new lines to look like board is updating
	print_board();
}

//declares and compares scores, declares tie or win
void Game::declare_winner() const {
	std::cout << player1->get_name() << " : " << player1->get_score() << std::endl;
	std::cout << player2->get_name() << " : " << player2->get_score() << std::endl;
	if (!(*player1 > *player2) && !(*player2 > *player1)) std::cout << "It's a tie!\n";  //ties occur if neither is winning over the other
	else if (*player1 > *player2) std::cout << player1->get_name() << " wins!\n";
	else std::cout << player2->get_name() << " wins!\n";
}