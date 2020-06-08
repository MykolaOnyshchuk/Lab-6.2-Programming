#pragma once
#include "Disease.h"

// Імені пацієнта не зберігаємо (для більшої реалістичності)
class Patient {
private:
	int treatment_time;
	vector<string> symptoms;
	Disease disease;

	void fill_symptoms(); // Надає пацієнту випадкові симптоми
public:
	Patient(); // Конструктор
	vector<string> get_symptoms(); // Геттер для симптомів
	void clarify_symptoms(); // Уточнити інформацію, тобто додати ще один симптом
	string get_info(); // Повертає рядкове предтавлення інф. про пацієнта
	Disease& get_disease(); // Повертає хворобу пацієнта (класс для роботи з нею)
	int get_treatment_time(); // Повертає час лікування
	void set_treatment_time(int); // Назначити час лікування
	void make_health(); // Час лікування минув
	void decrease_treatment_time(); // Минув один день лікування
};



