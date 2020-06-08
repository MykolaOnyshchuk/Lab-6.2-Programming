#pragma once
#include <iostream>
#include "Patient.h"
#include "TemplateCollection.h"
#include "DiasesStatictic.h"

/* ��������, �� �������� �� �� ����� �������� ���������� ���� ��������, ���� ���� �� ��������,
 * ��� �� �� ������ �� ������ ������ ������. �����, ������� ����� ������ ���������� ����
 * ����� �� ������ (��������� TemplateCollection ���� DiseaseStatictic). ���� ���������� ��������
 * ���� ������ (����� �������, �� �������� ����, �� � ��������� � ����)
*/

class Therapist{
private:
	TemplateCollection<Patient> patients;
	TemplateCollection<double> recovery_chance;
	int patients_by_disease[DISEASES_NUMBER];
	const int MAXIMAL_TREAMENT_TIME = 35;

	void check_patient(int); // ������ � ���������, ��� �������� ����� �����
public:
	Therapist();
	void examine(Patient&); // �������� ������ ��������
	void set_treatment_plan(Patient&); // ���������� �������� � ����������� � ������
	void make_daily_check(); // �������� ������ �� ���������
	void get_patients_info(); // ���������� ���� ��������
	TemplateCollection<DiseaseStatictic>& get_diseases_info(); // ��������� ���� ������
	void update_statistic(); // ��������� �������
	bool all_are_healhy(); // �������� �� �� ����������
};

