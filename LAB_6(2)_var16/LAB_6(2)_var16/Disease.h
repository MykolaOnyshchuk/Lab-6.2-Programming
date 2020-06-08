#pragma once
#include "DiseaseConst.h"
#include <algorithm>

class Disease{
private:
	string patient_disease; // ����� �������
	static int get_match_with(string, vector<string>); // ������� ��� ��������, �������� �������

public:
	Disease();
	void set_patient_disease(string disease); // ���������� �������� �������
	string get_string_disease(); // ������ ��� ����� �������

	static string get_random_symptom(); // ������� ���������� ������ �� ��� �������x
	static string detect_desease(vector<string>);  // �������� �������
	static int get_disease_index(string); // ������� ������ ������� � ������
};

