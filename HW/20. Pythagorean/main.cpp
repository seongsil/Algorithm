#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
	ifstream inStream;
	int cases;
	int how_many_teams, how_many_games;
	int playteam1, playteam2;
	int score1, score2;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream >> cases;

	for(int i=0; i<cases; i++)
	{
	int total_get_score[1000] = {0};
	int total_lost_score[1000] = {0};
	int expectation[1000] = {0};
		inStream >> how_many_teams >> how_many_games;

		for(int j=0; j<how_many_games; j++)
		{
			inStream >> playteam1 >> playteam2;
			inStream >> score1 >> score2;

			for(int i=0; i<how_many_teams; i++)
			{
				if((i+1) == playteam1)
				{
					total_get_score[i] += score1;
					total_lost_score[i] += score2;
				}
				else if((i+1) == playteam2)
				{
					total_get_score[i] += score2;
					total_lost_score[i] += score1;
				}

				else
					;
			}
		}

		for(int i=0; i<how_many_teams; i++)
		{
			if((total_get_score[i] == 0) && (total_lost_score[i] == 0))
				expectation[i] = 0;
			else
				expectation[i] = (total_get_score[i]* total_get_score[i] * 1000) / 
			(total_get_score[i]* total_get_score[i] + total_lost_score[i]* total_lost_score[i]);
		}
		sort(expectation, expectation+how_many_teams);
		cout << expectation[how_many_teams-1] << endl;
		cout << expectation[0]<< endl;
	}
}