#include "Disease.h"

int Disease::get_match_with(string disease, vector<string> patient_symptoms){
	int match = 0;
	// Перевіряємо число збігів по симптомам з даною хворобою
	for (auto& symptom : patient_symptoms) {
		if (std::find(diagnosis[disease].begin(), diagnosis[disease].end(), symptom) != diagnosis[disease].end())
			++match;
	};
	return match;
}

Disease::Disease(){
	patient_disease = UNKNOWN_DISEASE;
}

string Disease::get_random_symptom(){
	return all_symptoms[rand() % SYMPTOMS_NUMBER];
}

string Disease::get_string_disease()
{
	return patient_disease;
}

string Disease::detect_desease(vector<string> patient_symptoms){
	int matches[DISEASES_NUMBER];
	int maximal_index = 0;

	for (auto i = 0; i < DISEASES_NUMBER; ++i) {
		matches[i] = get_match_with(all_diseases[i], patient_symptoms);
		if (matches[i] == SYMPTOMS_BY_DISEASE) return all_diseases[i]; // Якщо повністю співпало
		maximal_index = (matches[i] > matches[maximal_index]) ? i : maximal_index;
	}
	// Максимальний збіг лише по одній хворобі і збіг більше, як по одному симптому
	int frequence = std::count(std::begin(matches), std::end(matches), matches[maximal_index]);
	return (matches[maximal_index] > 1 && frequence == 1) ? all_diseases[maximal_index] : UNKNOWN_DISEASE;
}

int Disease::get_disease_index(string disease){
	auto itr = std::find(std::begin(all_diseases), std::end(all_diseases), disease);
	return std::distance(all_diseases, itr);
}

void Disease::set_patient_disease(string disease){
	if (std::find(std::begin(all_diseases), std::end(all_diseases), disease) != std::end(all_diseases)) {
		patient_disease = disease;
	}
}
