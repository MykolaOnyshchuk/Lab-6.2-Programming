#pragma once
#if !defined(DISEASES_NUMBER) // ������ �� ����������� ���������

#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

// ʳ������ ������
static const int DISEASES_NUMBER = 12;
// ʳ������ ��������
static const int SYMPTOMS_NUMBER = 18;
// ����������� ������� �������� ��� ���� �������
static const int SYMPTOMS_BY_DISEASE = 3;
// ������� �������
static const string UNKNOWN_DISEASE = "UNDEFINED";
			
// ������ ������������
static string all_diseases[]{
		"�����������", "����", "����������",
		"��������", "����", "����", "������",
		"��������", "���", "�����", "����������",
		"����������"
};

// ������ ��������
static string all_symptoms[]{
	"�������� ����", "������", "������� �����������",
	"�������", "��������", "������", "���� � �����",
	"���� � ������", "�����", "�������", "c���", 
	"����������� �����", "��������", "������ �����������", 
	"�������� �������", "�����", "��������� ������",
	"���� � �����"
};


// �������� ��� ����� �������
static map<string, vector<string>> diagnosis = {
	{all_diseases[0], {all_symptoms[1], all_symptoms[2], all_symptoms[4]}}, 
	{all_diseases[1], {all_symptoms[3], all_symptoms[5], all_symptoms[7]}},
	{all_diseases[2], {all_symptoms[4], all_symptoms[3], all_symptoms[7]}},
	{all_diseases[3], {all_symptoms[1], all_symptoms[2], all_symptoms[9]}},
	{all_diseases[4], {all_symptoms[0], all_symptoms[1], all_symptoms[2]}},
	{all_diseases[5], {all_symptoms[2], all_symptoms[9], all_symptoms[10]}},
	{all_diseases[6], {all_symptoms[2], all_symptoms[4], all_symptoms[6]}},
	{all_diseases[7], {all_symptoms[2], all_symptoms[4], all_symptoms[11]}},
	{all_diseases[8], {all_symptoms[0], all_symptoms[12], all_symptoms[13]}},
	{all_diseases[9], {all_symptoms[1], all_symptoms[14], all_symptoms[15]}},
	{all_diseases[10], {all_symptoms[5], all_symptoms[0], all_symptoms[16]}},
	{all_diseases[11], {all_symptoms[1], all_symptoms[4], all_symptoms[17]}}
};
#endif
