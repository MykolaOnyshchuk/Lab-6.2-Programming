#pragma once
#include "DiseaseConst.h"

// Структура для щомісячної статистики
struct DiseaseStatictic {
	string disease_name;
	int patients_number;

	DiseaseStatictic(string disease_name = UNKNOWN_DISEASE, int patients_number = 0) {
		this->disease_name = disease_name;
		this->patients_number = patients_number;
	}
	
	string get_info() {
		return "Заболевание: " + disease_name +
			   "\nЗаболело за месяц: " + std::to_string(patients_number);
	}
};
