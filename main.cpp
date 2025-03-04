#include <iostream>
#include "Que.hpp"

using namespace std;

int min(int a, int b, int c) {
	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	else if (b < c) {
		return b;
	}
	else {
		return c;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Que<int> result;
	int tmp;
	int tmp2;
	int choice = 0;
	while (choice != 2) {
		cout << "Что хотите выполнить? \n1. Задание \n2. Выход.\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Какое количество чисел вывести?: ";
			cin >> tmp;
			Que<int> q2(2);
			Que<int> q3(3);
			Que<int> q5(5);
			for (size_t i = 0; i < tmp; i++) {
				tmp2 = min(q2.ctop(), q3.ctop(), q5.ctop());
				result.push(tmp2);
				q2.push(2 * tmp2);
				q3.push(3 * tmp2);
				q5.push(5 * tmp2);
				if (tmp2 == q2.ctop()) {
					q2.pop();
				}
				if (tmp2 == q3.ctop()) {
					q3.pop();
				}
				if (tmp2 == q5.ctop()) {
					q5.pop();
				}
			}
			while (result.size_() > 1) {
				cout << result.pop() << ", ";
			}
			if (result.size_() == 1) {
				cout << result.pop() << ".\n";
			}
			break;
		}
		case 2:
			cout << "Завершение\n";
			break;
		default:
			cout << "Ошибка ввода\n";
			break;
		}
	}
}