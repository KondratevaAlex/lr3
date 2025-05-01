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
