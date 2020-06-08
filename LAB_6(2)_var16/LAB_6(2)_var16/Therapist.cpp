#include "Therapist.h"

void Therapist::check_patient(int index){
	// ����������, �� ������� �������� � ����
	// �������� ���������
	if (recovery_chance[index] > 0.95) {
		patients[index].make_health();
	}
	else {
		// ������ ���������� ��������, ��� �������� ���� �����������
		auto treatment_time = patients[index].get_treatment_time();
		patients[index].set_treatment_time(rand() % MAXIMAL_TREAMENT_TIME / 2 + 1);
		recovery_chance[index] += 0.25;
	}
}

Therapist::Therapist(){
	for (auto i = 0; i < DISEASES_NUMBER; ++i) {
		patients_by_disease[i] = 0;
	}
}


void Therapist::examine(Patient& patient){
	string potential_disease = UNKNOWN_DISEASE;

	while (potential_disease == UNKNOWN_DISEASE) { // ��������� �������� (����������� �� ������)
		patient.clarify_symptoms();
		potential_disease = Disease::detect_desease(patient.get_symptoms());
	}

	patient.get_disease().set_patient_disease(potential_disease);
	++patients_by_disease[Disease::get_disease_index(potential_disease)];
}

void Therapist::set_treatment_plan(Patient& patient){
	// ������������ ���� �������� �� ���� ����������� �� ���
	// ����� ���� (�� ��������� ��� ��������� ���������� ����������)
	patient.set_treatment_time(rand() % MAXIMAL_TREAMENT_TIME + 1);
	patients.add(patient);
	auto health_chance = (float)rand() / RAND_MAX + 0.5;
	recovery_chance.add((health_chance >= 1) ? 1 : health_chance);
}

void Therapist::make_daily_check(){
	// ��������� �� ��� ��������� � �������� ��� ��������
	// �� ���� ����. ����������, �� ������� ������� �������� ������
	for (auto i = 0; i < patients.size(); ++i) {
		patients[i].decrease_treatment_time();
		if (patients[i].get_treatment_time() == 0)
			check_patient(i);
	}
}

void Therapist::get_patients_info(){
	for (auto i = 0; i < patients.size(); ++i) {
		std::cout << patients[i].get_info() << std::endl << std::endl;
	}
}

TemplateCollection<DiseaseStatictic>& Therapist::get_diseases_info(){
	TemplateCollection<DiseaseStatictic> statistic;
	// ������� ������-��� �� ��������, ����� ������ ����� ��������
	for (auto i = 0; i < DISEASES_NUMBER; i++) {
		statistic.add(DiseaseStatictic(all_diseases[i], patients_by_disease[i]));
	}
	return statistic;
}

void Therapist::update_statistic(){
	// ������� ���������� �� ��������� �����
	for (auto i = 0; i < DISEASES_NUMBER; ++i)
		patients_by_disease[i] = 0;
	// �������� ��������, �� �� �� �����������
	auto temp = TemplateCollection<Patient>();
	for (auto i = 0; i < patients.size(); ++i) {
		if (patients[i].get_treatment_time() != -1) {
			temp.add(patients[i]);
		}
	}
	// ��������� ��� ��������, ��� ������ ����� ���, 
	// ���x ��������, � ��� �� ��� ���������� ����������
	patients.clear();
	patients = TemplateCollection<Patient>();
	for (auto i = 0; i < temp.size(); ++i) {
		string curr_disease = temp[i].get_disease().get_string_disease();
		++patients_by_disease[Disease::get_disease_index(curr_disease)];
		patients.add(temp[i]);
	}
}

bool Therapist::all_are_healhy(){
	return patients.size() == 0;
}
