#pragma once
#include <iostream>
#include "Patient.h"
#include "TemplateCollection.h"
#include "DiasesStatictic.h"

/* Уявляємо, що терапевт НЕ має права надавати інформацію щодо пацієнтів, тому лише її виводить,
 * але не дає доступ до самого списку хворих. Однак, повертає УВЕСЬ список статистики щодо
 * кожної із хвороб (шаблонний TemplateCollection типу DiseaseStatictic). Дану інформацію виводить
 * сама лікарня (можна вважати, що головний лікар, як і зазначено в умові)
*/

class Therapist{
private:
	TemplateCollection<Patient> patients;
	TemplateCollection<double> recovery_chance;
	int patients_by_disease[DISEASES_NUMBER];
	const int MAXIMAL_TREAMENT_TIME = 35;

	void check_patient(int); // Робота з пацієнтом, час лікування якого минув
public:
	Therapist();
	void examine(Patient&); // Перевірка нового пацієнта
	void set_treatment_plan(Patient&); // Назначення лікування і записування в історію
	void make_daily_check(); // Щоденний прохід по пацієнтам
	void get_patients_info(); // Інформація щодо пацієнтів
	TemplateCollection<DiseaseStatictic>& get_diseases_info(); // Стастиска щодо хвороб
	void update_statistic(); // Оновлення щомісяця
	bool all_are_healhy(); // Перевірка чи всі виздоровіли
};

