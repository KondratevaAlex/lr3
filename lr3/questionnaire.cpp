#include "questionnaire.h"
#include <iostream>
using namespace std;

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

int questionnaire::getMainDiagnose()
{
    return mainDiagnose;
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
	int questionValue = 0;
	for (int i = 0; i < 15; i++) {
		if (possibleIllnessLine[i] > questionValue) {
			thirdDiagnose = secondDiagnose;
			secondDiagnose = mainDiagnose;
			mainDiagnose = i;
			questionValue = possibleIllnessLine[i];
		}
	}
}

void questionnaire::chooseQuestion(int questionNumber)
{
    switch (questionNumber)
    {
    case 0: {
        question = "1. Как давно начались ваши симптомы?\n   1 - Сегодня\n   2 - 1-3 дня назад\n   3 - 4-7 дней назад\n   4 - Более недели назад\n   5 - Несколько месяцев или больше";
        break;
    }
    case 1: {
        question = "2. Есть ли у вас температура?\n   1 - Нет\n   2 - До 37.5°C\n   3 - 37.6-38.5°C\n   4 - 38.6-39.5°C\n   5 - Выше 39.5°C";
        break;
    }
    case 2: {
        question = "3. Как бы вы описали общее самочувствие?\n   1 - Хорошее, чувствую себя нормально\n   2 - Лёгкое недомогание\n   3 - Среднее ухудшение\n   4 - Тяжёлое состояние\n   5 - Очень тяжёлое";
        break;
    }
    case 3: {
        question = "4. Где у вас болит сильнее всего?\n   1 - Нет боли\n   2 - Голова\n   3 - Грудь\n   4 - Живот\n   5 - Поясница/спина";
        break;
    }
    case 4: {
        question = "5. Какая боль преобладает?\n   1 - Тупая\n   2 - Острая\n   3 - Ноющая\n   4 - Жгучая\n   5 - Приступообразная";
        break;
    }
    case 5: {
        question = "6. Есть ли у вас кашель?\n   1 - Нет\n   2 - Да, сухой\n   3 - Да, с мокротой\n   4 - Да, с кровью\n   5 - Кашель + одышка";
        break;
    }
    case 6: {
        question = "7. Как вы дышите?\n   1 - Нормально\n   2 - Немного затруднённо\n   3 - Одышка при нагрузке\n   4 - Одышка в покое\n   5 - Затруднённое дыхание с болью";
        break;
    }
    case 7: {
        question = "8. Как себя чувствует ваше горло?\n   1 - Нормально\n   2 - Лёгкое першение\n   3 - Сильная боль\n   4 - Сухость\n   5 - Ощущение кома или сдавливания";
        break;
    }
    case 8: {
        question = "9. Есть ли симптомы со стороны ЖКТ (желудка/кишечника)?\n   1 - Нет\n   2 - Тошнота\n   3 - Рвота\n   4 - Диарея\n   5 - Запор";
        break;
    }
    case 9: {
        question = "10. Какой у вас аппетит?\n   1 - Нормальный\n   2 - Слегка снижен\n   3 - Практически отсутствует\n   4 - Повышен\n   5 - Отвращение к еде";
        break;
    }
    case 10: {
        question = "11. Как вы себя чувствуете физически?\n   1 - В норме\n   2 - Усталость\n   3 - Сильная слабость\n   4 - Головокружение\n   5 - Обмороки или полуобморочные состояния";
        break;
    }
    case 11: {
        question = "12. Замечали ли вы кожные изменения?\n   1 - Нет\n   2 - Сыпь\n   3 - Покраснение\n   4 - Зуд\n   5 - Отёк или пятна";
        break;
    }
    case 12: {
        question = "13. Есть ли изменения мочеиспускания?\n   1 - Нет\n   2 - Стало чаще\n   3 - Редкое мочеиспускание\n   4 - Боль или жжение\n   5 - Мутная/тёмная моча";
        break;
    }
    case 13: {
        question = "14. Были ли у вас контакты с больными людьми или поездки в последние 14 дней?\n   1 - Нет\n   2 - Контакт с больным человеком\n   3 - Поездка в другой регион\n   4 - Посещение больницы или поликлиники\n   5 - Пребывание в местах скопления людей";
        break;
    }
    case 14: {
        question = "15. Есть ли у вас хронические заболевания?\n   1 - Нет\n   2 - Сердечно-сосудистые\n   3 - Сахарный диабет\n   4 - Болезни дыхательной системы (астма, ХОБЛ и др.)\n   5 - Другое (иммунные, ЖКТ, неврологические и т.д.)";
        break;
    }

    default:
        break;
    }
}

string questionnaire::getQuestion()
{
    return question;
}
