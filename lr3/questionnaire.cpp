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

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			in >> answersMatr[i][j];
		}
	}
}
