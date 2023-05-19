//Stephen Yuhas
//Lab 9 - Structures
//5-10-22

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;


const int SIZE = 20;	//const for size of c-strings
const int PLAYERS = 4;	//const for size of soccer players struct array
const int TEAMS = 3;	//const for size of soccer teams struct array
const int ZERO = 0;		//const for zero for validation
const char TESTSTRING[SIZE] = "NONE";	//const for test validation string


struct SoccerPlayer		//struct definition for soccer players
{
	char pName[SIZE] = "NONE";	//c-string for each player name
	int goals = 0;				//int variable for amount of goals for each player
};

struct SoccerTeam		//struct definition for soccer teams
{
	char tName[SIZE] = "NONE";	//c-string for name of each team
	int games = 0;				//int variable for number of games played
	int wins = 0;				//int variable for number of games won
	SoccerPlayer player[PLAYERS];	//array of struct 'SoccerPlayer' nested in the team struct
};

void welcome();		//proto for welcome display function
void showStats(SoccerTeam[], bool);	//proto for function to show stats
void getTeamInfo(SoccerTeam[]);	//proto for function to input team info


int main()
{
	bool forceStats = true;		//(EXTRA CREDIT) bool variable to show or not show empty stats in showStats function

	SoccerTeam team[TEAMS];		//array of SoccerTeam struct for TEAMS(3) amount of teams

	welcome();		//call for welcome display function

	showStats(team, forceStats);	//call showstats function to show all stats(EXTRA CREDIT: forcestats bool set to true as default, will show empty stats)

	getTeamInfo(team);	//function call to input teams info

	forceStats = false;	//forcestats bool set to false after team info is input; this will discriminate between empty and recorded stats and only show recorded stats

	showStats(team, forceStats);	//call showstats with forcestats bool set to false

	system("pause");
	return 0;	
}

void welcome()	//definition of function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 9 - Structures" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Soccer Statistics Calculator" << endl << endl;
	return;
}

void showStats(SoccerTeam team[], bool forceStats)		//function definition: show stats of all teams and players(EXTRA CREDIT: when forcestats = false, empty stats will not display)
{
	bool isNone = false;	//bool variable to check for a 'none' user name
	cout << fixed << showpoint << setprecision(2);	//formatting for a forced 2 decimal places
	if (forceStats){ cout << "Data After Initialization:" << endl << endl; }	//if forcestats is true, the initialized data is shown
	if (!forceStats){ cout << "Data After User Input:" << endl << endl; }		//if forcestats is false, data has been input and only input data will be shown
	for (int i = 0; i < TEAMS; i++)	//for statement to run through teams
	{
		cout << "The team: " << team[i].tName << " has played " << team[i].games << " games." << endl;	//display team name and games played
		cout << "\tTheir record is " << team[i].wins << " wins and " << team[i].games - team[i].wins << " losses." << endl << endl;		//display win/loss record
		for (int j = 0; j < PLAYERS; j++)	//for statement to run through players
		{
			for (int k = 0; k < strlen(team[i].player[j].pName); k++)	//for statement to check for empty stats
			{
				if (toupper(team[i].player[j].pName[k]) == TESTSTRING[k])	//if a 'none' value was entered for a player, bool will be set to true and stats will stop displaying
				{
					isNone = true;
				}
				else { isNone = false; }	//if not 'none' value was found, stats will continue to display
			}

			if (forceStats && isNone)	//initialization instance; forcestats will show all 'none' values
			{
				cout << "Player: " << team[i].player[j].pName << ", has " << team[i].player[j].goals << " goals." << endl;
				cout << "\tThe average goals are: ";
				cout << "No Games Played" << endl;
				
			}
			else if (!forceStats && !isNone)	//Data display after user input (EXTRA CREDIT: only stats containing data are shown)
			{
				cout << "Player: " << team[i].player[j].pName << ", has " << team[i].player[j].goals << " goals." << endl;
				cout << "\tThey average " << static_cast<double>(team[i].player[j].goals) / team[i].games << " goals per game." << endl;
			}
		}
		cout << endl;
	}
}

void getTeamInfo(SoccerTeam team[])	//function definition: input all team/player stats with validation loops
{
	cout << "User Input:" << endl << endl;

	for (int i = 0; i < TEAMS; i++)		//for loop to run through each team
	{
		bool flag = true;	//bool variable to stop entering data if a 'none' is entered in a player name prompt
		cout << "Enter the team's name: ";
		cin.getline(team[i].tName, SIZE);		//getline up to SIZE for c-string
		do //validation do/while loop
		{
			cout << "Enter the number of games played: ";
			cin >> team[i].games;
			if (team[i].games < ZERO)	//error message for games played less than zero
			{
				cout << "Error - The number of games must be greater than or equal to zero. Please reenter." << endl << endl;
			}
		} while (team[i].games < ZERO);	//loop persists if entry is less than zero
		
		cin.ignore(1, '\n');	//cin.ignore for white space


		do	//validation do/while loop
		{
			cout << "Enter the number of games won: ";
			cin >> team[i].wins;
			if (team[i].wins < ZERO)	//error message for negative value entered
			{
				cout << "Error - The number of games won cannot be negative. Please reenter." << endl << endl;
			}
			if (team[i].wins > team[i].games)	//error message if entry for games won is great than the amount of games played
			{
				cout << "Error - The number of games won cannot be greater than the number of games played. Please reenter." << endl << endl;
			}
		} while (team[i].wins < ZERO || team[i].wins > team[i].games);	//loop persists upon negative input or winning games input greater than games played
		
		cin.ignore(1, '\n');	//cin.ignore for white space
		
		if (team[i].wins > ZERO)	//if the wins is greater than zero, code then allows entry of player data
		{
			int pCount = 0;		//count variable to run through player elements in struct array for loop

			do  //do/while statment to run through data input until end of array is reached or the program encounters a 'none' player entry
			{
				cout << "\tEnter the name of player " << pCount + 1 << ": ";
				cin.getline(team[i].player[pCount].pName, SIZE);

				if (strlen(team[i].player[pCount].pName) == strlen(TESTSTRING))	//if the length of the string equals the test string 'none'....
				{
					for (int j = 0; j < strlen(team[i].player[pCount].pName); j++)	//....the code starts to test the uppercase version of each element in the c-string to see if they match(EXTRA CREDIT)
					{
						if (toupper(team[i].player[pCount].pName[j]) == TESTSTRING[j])	//...if each element matches the test string then a 'none' has been confirmed
						{
							flag = false;		//bool is set to false, this will stop any further input
						}
						else { flag = true; }	//if bool is set to true, program will allow further player input until the end of the array or a false bool is encountered
					}
				}
				else { flag = true; }	//if the size of the input name and test string do not match, it cannot be a 'none' input and program allows further player data to be input


				if (flag)	//if above tests pass, no 'none' in any form has been entered; player data can now be input when bool is true
				{
					do	//do/while loop for input validation
					{
						cout << "\tEnter goals scored " << pCount + 1 << ": ";
						cin >> team[i].player[pCount].goals;
						if (team[i].player[pCount].goals < ZERO)	//error message for a negative input
						{
							cout << "\tError - Number of games must be greater than zero. Please reenter." << endl << endl;
						}
						
					} while (team[i].player[pCount].goals < ZERO);	//loop persists if a negative value is input
					cin.ignore(1, '\n');	//cin.ignore for whitespace
				}
				pCount++;	//counter for elements in array is incremented

			} while (flag && pCount < PLAYERS);		//loop will persist until end of array or until a false bool flag has been raised
			cout << endl << endl;
		}
	}
}