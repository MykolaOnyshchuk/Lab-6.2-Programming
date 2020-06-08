#pragma once
#include "Therapist.h"

class Hospital{
private:
	Therapist therapist;
	int patients_number;
	int days_for_procesing;

	void fill_patiens(); // ���� ���������� �������� �������
	void print_statitic(int); // �������� �������� ���������� ������ �� ������ ��������
	void get_patients_info(); // �������� ���������� ��� ��������
	void get_diseases_info(); // �������� ���������� ������
public:
	Hospital(int, int);
	void start_simulation(); // ��������� ���������
};

