#pragma once
#include "Disease.h"

// ���� �������� �� �������� (��� ����� ������������)
class Patient {
private:
	int treatment_time;
	vector<string> symptoms;
	Disease disease;

	void fill_symptoms(); // ���� �������� �������� ��������
public:
	Patient(); // �����������
	vector<string> get_symptoms(); // ������ ��� ��������
	void clarify_symptoms(); // �������� ����������, ����� ������ �� ���� �������
	string get_info(); // ������� ������� ������������ ���. ��� ��������
	Disease& get_disease(); // ������� ������� �������� (����� ��� ������ � ���)
	int get_treatment_time(); // ������� ��� ��������
	void set_treatment_time(int); // ��������� ��� ��������
	void make_health(); // ��� �������� �����
	void decrease_treatment_time(); // ����� ���� ���� ��������
};



