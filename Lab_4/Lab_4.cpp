#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int factorial(int numb) {
	int result = 1;
	for (int k = 1; k <= numb; k++) {
		result *= k;
	}
	return result;
}

void permutation(int n) {
	int* i = new int[n];
	for (int k = 0; k < n; k++) {
		i[k] = k + 1;
	}
	sort(i, i + n);
	cout << n << "! <" << factorial(n) << "> permutations with " << n << " elements:" << endl;
	do
	{
		for (int k = 0; k < n; k++) {
			cout << i[k] << " ";
		}
		cout << endl;
	} while (next_permutation(i, i + n));
}

void combination(int en, int er) {
	vector<bool> v(en); //Масив Селекторів
	fill(v.begin(), v.begin() + er, true); //Відкриваєм r елементів в масиві селекторів
	cout << en << "! / (" << er << "! * (" << en << " - " << er << ")) <" << factorial(en) / (factorial(er) * factorial(en - er)) << "> combinations with " << en << " elements by " << er << ":" << endl;
	do {
		for (int i = 0; i < en; ++i) {
			if (v[i]) {
				cout << (i + 1) << " ";
			}
		}
		cout << endl;
	} while (prev_permutation(v.begin(), v.end())); 
	//Переставляєм числа n перестановкою. В if якщо число стоїть на місці селектора true - то
	//виводимо його. В результаті виводяться всі можливі комбінації без 
}

int main()
{
	int n = 0;
	cout << "n = ";
	cin >> n;

	permutation(n);

	int en = 0;
	int er = 0;
	cout << "en = ";
	cin >> en;
	cout << "er (er <= en) = ";
	cin >> er;
	er = abs(er);

	combination(en, er);
}