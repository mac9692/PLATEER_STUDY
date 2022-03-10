#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int y, m, d;
	cin >> y;
	cin.ignore(256, '.');
	cin >> m;
	cin.ignore(256, '.');
	cin >> d;
	cout << setfill('0') << setw(2) << d << "-";
	cout << setfill('0') << setw(2) << m << "-";
	cout << setfill('0') << setw(4) << y << endl;

}

/*
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	int y, m, d;
	cin >> y;
	cin.ignore(256, '.');
	cin >> m;
	cin.ignore(256, '.');
	cin >> d;
	printf("%02d-%02d-%04d", d, m, y);

}
*/
