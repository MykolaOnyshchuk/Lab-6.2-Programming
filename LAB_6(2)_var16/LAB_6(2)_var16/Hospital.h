#pragma once
#include "Therapist.h"

class Hospital{
private:
	Therapist therapist;
	int patients_number;
	int days_for_procesing;

	void fill_patiens(); // Додає випадкових пацієнтів щомісяца
	void print_statitic(int); // Виводить щомісячну статистику хвороб та список пацієнтів
	void get_patients_info(); // Виводить інформацію про пацієнтів
	void get_diseases_info(); // Виводить статистику хвороб
public:
	Hospital(int, int);
	void start_simulation(); // Розпочинає симуляцію
};

