#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum RPSSelection
{
	END = 0, ROCK, PAPER, SCISSORS
};

void EnterMessage()
{
	cout << endl << "Please enter your selection:" << endl
		<< "|| 1 - Rock || 2 - Paper || 3 - Scissors || 0 - Exit ||" << endl << endl;
}

bool CheckInput(string &input, int &selection)
{
	if (isdigit(input[0]) && input[1] == NULL)
	{
		switch (stoi(input))
		{
		case ROCK:
			selection = ROCK;
			return true;
			break;

		case PAPER:
			selection = PAPER;
			return true;
			break;

		case SCISSORS:
			selection = SCISSORS;
			return true;
			break;

		case END:
			selection = END;
			return true;
			break;

		default:
			return false;
			break;
		}
	}
	else
	{
		return false;
	}
}

string Choice_Str(int selection)
{
	switch (selection)
	{
	case ROCK:
		return "ROCK";
		break;

	case PAPER:
		return "PAPER";
		break;

	case SCISSORS:
		return "SCISSORS";
		break;

	default:
		return "";
		break;
	}
}

void main()
{
	srand(time(0)); // New random seed when game runs.

	string input; // Used for cin.

	int playerSelection = -1;
	string playerChoice;

	int botSelection = 0;
	string botChoice;	

	cout << "Welcome to Rock, Paper, Scissors. Let's play!" << endl;
	EnterMessage();

	cin >> input;

	while (!CheckInput(input, playerSelection))
	{
		cout << endl << "Invalid input. Please enter one of the selections listed." << endl;
		EnterMessage();
		input.clear();
		cin >> input;
	}

	if (playerSelection != END)
	{
		botSelection = (rand() % 3) + 1; // Random number between 1 and 3.
		playerChoice = Choice_Str(playerSelection);
		botChoice = Choice_Str(botSelection);

		cout << endl << "|| Player choice: " << playerChoice << " ||" << endl
			<< "|| Bot Choice : " << botChoice << " ||" << endl;
	}
	else
	{
		cout << "GAME EXIT" << endl;
	}

	// TO DO
	// "|| ROCK beats SCISSORS. - Player wins round X! ||
	// "|| CURRENT SCORE || PLAYER - Y || BOT - Z ||"
	// "|| ROUND X ||"
}