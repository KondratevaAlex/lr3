#pragma once
#include <string>
#include <fstream>

using namespace std;

class questionnaire
{
private:
	int answer,
		answersMatr[15][15],
		answerLine[15] = { 0 },
		possibleIllnessLine[15] = { 0 };
public:
	void setAnswer(int ans);
	int getAnswer();
	int getAnswerFromMatrix(int i, int j);
	bool loadAnswersFromFile(string filename);
	void setAnswerToLine(int questionNumber);
	int getAnswerFromLine(int answerNumber);
	void countPossibleIllness();
	int getPossibleIllnessValue(int diseaseLine);
};

