#pragma once
#include "DiseaseConst.h"
#include <algorithm>

class Disease{
private:
	string patient_disease; // Назва хвороби
	static int get_match_with(string, vector<string>); // Хвороба для перевірки, симптоми хворого

public:
	Disease();
	void set_patient_disease(string disease); // Втавновлює значення хвороби
	string get_string_disease(); // Геттер для назви хвороби

	static string get_random_symptom(); // Повертає випадковий симтом із усіх можливиx
	static string detect_desease(vector<string>);  // Симптоми хворого
	static int get_disease_index(string); // Повертає індекс хвороби у списку
};

