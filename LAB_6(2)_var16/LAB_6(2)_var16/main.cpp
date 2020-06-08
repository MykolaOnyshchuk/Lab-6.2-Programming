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
	mainMenu();   //��������� ������� ����
}

void mainMenu()  //������� ����
{
	std::cout << "������ ������, ��-92, ������� 16: ������ ��������, ������� ��������� �\n\n";
	std::cout << "������� ���������� ���� ��� ��������� (�� ������ 365 � �� ������ 30):\n";
	auto days_number = get_input(30, 365);
	std::cout << "������� ���������� ���������, ������� ����� ����������� ������ ����� � ��������:\n";
	auto  patients_number = get_input(1, 100);

	Hospital newHospital = Hospital(days_number, patients_number);
	newHospital.start_simulation();
	helper();
}

void helper()   //�������� ������� ��� ��������� ����
{
	int in = 0;
	std::cout << "���� ������ ����������, ������� 1\n";
	std::cout << "���� ������ �����, ������� 2\n";
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