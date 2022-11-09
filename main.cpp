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

enum RPSRoundScore
{
	LOSE = -1, DRAW, WIN
};

void PrintLine()
{
	cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}

void EnterMessage()
{
	cout << "|| 1 - Rock || 2 - Paper || 3 - Scissors || 0 - Exit ||" << endl
		<< "Please enter your selection: ";
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

string Str_Choice(int selection)
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

int CompareMoves(int playerSelection, int botSelection)
{
	int result = playerSelection - botSelection;
	
	switch (result)
	{
	case 0:
		return DRAW; // RvR, PvP, SvS

	case 1: // PvR, SvP
	case -2: // RvS
		return WIN;

	case -1: // RvP, PvS
	case 2: // SvR
		return LOSE;

	default:
		cout << endl << "Congratulations! You somehow broke the game! I guess you win this round. :)" << endl;
		return WIN;
	}
}

void GameOver(int gameResult, int playerScore, int botScore, bool &gameOver)
{
	PrintLine();
	cout << "|| FINAL SCORE || PLAYER: " << playerScore << " || BOT: " << botScore << " ||" << endl;
	PrintLine();
	cout << endl;

	if (gameResult == WIN)
	{
		PrintLine();
		cout << "CONGRATULATIONS! YOU WIN!" << endl;
		PrintLine();
		cout << endl;
	}
	else
	{
		PrintLine();
		cout << "BOT IS THE WINNER. YOU LOSE." << endl;
		PrintLine();
		cout << endl;
	}

	gameOver = true;
}



void main()
{
	srand(time(0)); // New random seed when game runs.
	
	bool gameOver = false; // Controls game loop.

	string str_input; // Used for cin.

	int playerSelection = -1;
	int botSelection = 0;
	string str_playerChoice;
	string str_botChoice;

	int playerScore = 0;
	int botScore = 0;

	cout << "Welcome to Rock, Paper, Scissors. Let's play!" << endl << endl;

	while (!gameOver)
	{
		EnterMessage();
		cin >> str_input;

		while (!CheckInput(str_input, playerSelection))
		{
			cout << endl << "Invalid input. Please enter one of the selections listed." << endl;
			EnterMessage();
			str_input.clear();
			cin >> str_input;
		}

		if (playerSelection != END)
		{
			botSelection = (rand() % 3) + 1; // Random number between 1 and 3.
			str_playerChoice = Str_Choice(playerSelection);
			str_botChoice = Str_Choice(botSelection);

			cout << endl << "|| Player choice: " << str_playerChoice << " ||" << endl
				<< "|| Bot Choice : " << str_botChoice << " ||" << endl << endl;

			int roundResult = (CompareMoves(playerSelection, botSelection));

			switch (roundResult)
			{
			case DRAW:
				cout << str_playerChoice << " ties with " << str_botChoice << ". Shoot again!" << endl << endl;
				break;

			case WIN:
				cout  << str_playerChoice << " beats " << str_botChoice << ". PLAYER wins the round!" << endl << endl;
				playerScore++;
				break;

			case LOSE:
				cout << str_playerChoice << " loses to " << str_botChoice << ". BOT wins the round!" << endl << endl;
				botScore++;
				break;

			default:
				cout << "Please stop breaking my game..." << endl << endl;
				break;
			}

			if (playerScore == 2)
			{
				GameOver(WIN, playerScore, botScore, gameOver);
			}
			else if (botScore == 2)
			{
				GameOver(LOSE, playerScore, botScore, gameOver);
			}
			else
			{
				PrintLine();
				cout << "|| CURRENT SCORE || PLAYER: " << playerScore << " || BOT: " << botScore << " ||" << endl;
				PrintLine();
				cout << endl;
			}

		}
		else
		{
			cout << "GAME EXIT" << endl;
			gameOver = true;
		}
	}
}