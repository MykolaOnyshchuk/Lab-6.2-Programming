#include <ctime>
#include "Hospital.h"

int get_input(int lower_bound, int upper_bound) {
	int input = lower_bound - 1;
	while (input < lower_bound || input > upper_bound) {
		std::cin >> input;
	}
	return input;
}

void mainMenu();

void helper();

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	mainMenu();   //Викликаємо головне меню
}

void mainMenu()  //Головне меню
{
	std::cout << "Онищук Микола, ИП-92, вариант 16: Работа педиатра, уровень сложности В\n\n";
	std::cout << "Введите количество дней для симуляции (не больше 365 и не меньше 30):\n";
	auto days_number = get_input(30, 365);
	std::cout << "Введите количество пациентов, которое будет добавляться каждый месяц в больницу:\n";
	auto  patients_number = get_input(1, 100);

	Hospital newHospital = Hospital(days_number, patients_number);
	newHospital.start_simulation();
	helper();
}

void helper()   //Допоміжна функція для головного меню
{
	int in = 0;
	std::cout << "Если хотите продолжить, нажмите 1\n";
	std::cout << "Если хотите выйти, нажмите 2\n";
	std::cin >> in;
	if (in == 1)
	{
		system("cls");
		mainMenu();
	}
	if (in == 2)
	{
		system("exit");
	}
}
