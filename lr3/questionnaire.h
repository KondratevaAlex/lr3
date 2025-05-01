#pragma once
#include <string>
#include <fstream>

using namespace std;

class questionnaire
{
private:
	int answer;
	int answersMatr[15][15];
public:
	void setAnswer(int ans);
	int getAnswer();
	int getAnswerFromMatrix(int i, int j);
	bool loadAnswersFromFile(string filename);
};

