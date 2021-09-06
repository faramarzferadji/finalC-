#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game
{
private:
	
	string player_name;
	int num_games;
	int* scores;
	int highestScore;
	void calculateHighest();
public:
	Game(string name, int games);
	void display();
	~Game();

};


Game::Game(string name, int games)
{
	player_name = name;
	num_games = games;

	scores = new int[num_games];

	
	if (scores == NULL)
	{
		cout << "Insufficient memory";
		exit(1);
	}
	
	for (int i = 0;i < num_games;i++)
	{
		scores[i] = rand() % 101;
	}

	calculateHighest();
}


void Game::calculateHighest()
{
	highestScore = 0;
	for (int i = 0;i < num_games;i++)
		if (scores[i] > highestScore)
			highestScore = scores[i];
}


void Game::display()
{
	cout << player_name << " = " << highestScore;
}


Game::~Game()
{
	if (scores != NULL)
		delete scores;
}

int main() {

	srand(time(NULL)); 
	Game** players; 

	int num_players, num_games;
	string name;
	
	cout << "Number of players : ";
	cin >> num_players;

	
	players = new Game * [num_players];
	cout << endl;
	
	if (players != NULL)
	{
		
		for (int i = 0;i < num_players;i++)
		{
			cout << "Enter player name #" << (i + 1) << " and number of games => ";
			cin >> name >> num_games;
			players[i] = new Game(name, num_games);
		}

	
		cout << endl << "Highest scores : " << endl;
		for (int i = 0;i < num_players;i++)
		{
			players[i]->display();
			cout << endl;
		}
	}

	
	for (int i = 0;i < num_players;i++)
		delete players[i];
	delete players;

	return 0;
}