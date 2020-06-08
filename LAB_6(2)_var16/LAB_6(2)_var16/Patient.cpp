#include "Patient.h"

void Patient::fill_symptoms(){
	for (auto i = 0; i < SYMPTOMS_BY_DISEASE; ++i)
		clarify_symptoms();
}

string Patient::get_info(){
	string symptoms_info = "";
	for (auto i = 0; i < symptoms.size(); ++i) {
		symptoms_info += symptoms[i];
		symptoms_info += (i != symptoms.size() - 1) ? ", " : "";
	}
	return "Информация о пациенте:\nСимптомы: " + symptoms_info +
		"\nЗаболевание: " + disease.get_string_disease() +
		"\nОсталось лечится (дней): " + std::to_string(std::max(treatment_time, 0));
}

Disease& Patient::get_disease()
{
	return disease;
}

int Patient::get_treatment_time(){
	return treatment_time;
}

void Patient::set_treatment_time(int _treatment_time){
	treatment_time = _treatment_time;
}

void Patient::make_health(){
	treatment_time = -1; // Сигнал, що пацієнт уже НЕ в лікарні
}

void Patient::decrease_treatment_time(){
	treatment_time = (treatment_time > 0) ? treatment_time - 1 : 0;
}

Patient::Patient(){
	disease = Disease();
	treatment_time = 0;
	fill_symptoms();
}

vector<string> Patient::get_symptoms(){
	return symptoms;
}

void Patient::clarify_symptoms(){
	string new_symptom = UNKNOWN_DISEASE;
	// Перевіряємо, чи немає ВЖЕ такого симптому
	// генеруємо, доки не отримаємо новий
	do{
		new_symptom = disease.get_random_symptom();
	} while (std::find(symptoms.begin(), symptoms.end(), new_symptom) != symptoms.end());
	symptoms.push_back(new_symptom);
}
