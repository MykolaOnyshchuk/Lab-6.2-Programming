#include "Hospital.h"

void Hospital::fill_patiens(){
	for (auto i = 0; i < patients_number; ++i) {
		auto patient = Patient();
		therapist.examine(patient);
		therapist.set_treatment_plan(patient);
	}
}

void Hospital::print_statitic(int month){
	std::cout << "Месяц " << month << std::endl;
	if (therapist.all_are_healhy()) {
		std::cout << "ALL ARE HEALTHY" << std::endl;
		return;
	}
	std::cout << "\nСтатистика болезней:\n\n";
	get_diseases_info();
	std::cout << "Статистика по пациентам:\n\n";
	get_patients_info();
}

Hospital::Hospital(int days, int patients_num){
	patients_number = (patients_num > 0) ? patients_num : 0;
	this->days_for_procesing = std::max(30, days);
	fill_patiens();
}

void Hospital::start_simulation(){
	for (auto i = 1; i <= days_for_procesing; ++i) {
		therapist.make_daily_check();
		// Статистику підбиваємо ЛИШЕ в кінці місяця (як написано в умові)
		if (i % 30 == 0) {
			print_statitic(i / 30);
			therapist.update_statistic();
			fill_patiens();
		}
	}
}

void Hospital::get_patients_info(){
	therapist.get_patients_info();
}

void Hospital::get_diseases_info(){
	auto statictic = therapist.get_diseases_info();
	for (auto i = 0; i < statictic.size(); ++i) {
		std::cout << statictic[i].get_info() << std::endl << std::endl;
	}
}
