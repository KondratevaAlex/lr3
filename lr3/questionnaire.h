#pragma once
#include <string>
#include <fstream>

using namespace std;

class questionnaire
{
private:
	int answer,
		mainDiagnose = -1,
		secondDiagnose = -1,
		thirdDiagnose = -1,
		answersMatr[15][15],
		answerLine[15] = { 0 },
		possibleIllnessLine[15] = { 0 };
	string question;

public:
	void setAnswer(int ans);
	int getAnswer();
	int getAnswerFromMatrix(int i, int j);
	bool loadAnswersFromFile(string filename);
	void setAnswerToLine(int questionNumber);
	int getAnswerFromLine(int answerNumber);
	void countPossibleIllness();
	int getPossibleIllnessValue(int diseaseLine);
	void sortDeseases();
	int getMainDiagnose();
	void chooseQuestion(int questionNumber);
	string getQuestion();
};

