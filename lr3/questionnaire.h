#pragma once
#include <string>
#include <fstream>

using namespace std;

class questionnaire
{
private:
	int answer;
	int answersMatr[2][2];
public:
	void setAnswer(int ans);
	int getAnswer();
	int getAnswerFromMatrix(int i, int j);
	bool loadAnswersFromFile(string filename);
};

