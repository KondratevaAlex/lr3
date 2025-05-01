#include "questionnaire.h"


void questionnaire::setAnswer(int ans)
{
	answer = ans;
}

int questionnaire::getAnswer()
{
	return answer;
}

int questionnaire::getAnswerFromMatrix(int i, int j)
{
	return answersMatr[i][j];
}

bool questionnaire::loadAnswersFromFile(string filename)
{
	ifstream in(filename);
	if (!in.is_open()) return false;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			in >> answersMatr[i][j];
		}
	}
	in.close();
	return true;
}

void questionnaire::setAnswerToLine(int questionNumber)
{
	answerLine[questionNumber] = answer;
}

int questionnaire::getAnswerFromLine(int answerNumber)
{
	return answerLine[answerNumber];
}

void questionnaire::countPossibleIllness()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (answersMatr[i][j] == answerLine[j]) {
				possibleIllnessLine[i]++;
			}
		}
	}
}

int questionnaire::getPossibleIllnessValue(int diseaseLine)
{
	return possibleIllnessLine[diseaseLine];
}

void questionnaire::sortDeseases()
{
	int diagnoseValue = 0;
	for (int i = 0; i < 15; i++) {
		if (possibleIllnessLine[i] > diagnoseValue) {
			thirdDiagnose = secondDiagnose;
			secondDiagnose = mainDiagnose;
			mainDiagnose = i;
			diagnoseValue = possibleIllnessLine[i];
		}
	}
}

int questionnaire::getMainDiagnose()
{
	return mainDiagnose;
}
