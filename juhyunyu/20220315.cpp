// 1061
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	printf("%d", (a|b));
}
// 1062
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	printf("%d", (a^b));
}
*/
// 1063
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	printf("%d", a > b ? a : b);
}
*/
// 1064
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	printf("%d", (a < b ? a : b) < c ? (a < b ? a : b) : c);
}
*/
// 1065
/*
#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0)
		cout << a << endl;
	if (b % 2 == 0)
		cout << b << endl;
	if (c % 2 == 0)
		cout << c << endl;
}
*/
// 1066
/*
#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;

	if (b % 2 == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;

	if (c % 2 == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;
}
*/
// 1067
/*
#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	if (a > 0) {
		cout << "plus" << endl;
		if (a % 2 == 0) {
			cout << "even" << endl;
		}
		else
			cout << "odd" << endl;
	}
	else {
		cout << "minus" << endl;
		if (a % 2 == 0) {
			cout << "even" << endl;
		}
		else
			cout << "odd" << endl;
	}
		
}
*/
// 1068
/*
#include <iostream>

using namespace std;

int main() {
	int score;
	cin >> score;
	if (score >= 90)
		cout << "A" << endl;
	else if (score >= 70)
		cout << "B" << endl;
	else if (score >= 40)
		cout << "C" << endl;
	else
		cout << "D" << endl;
}
*/
// 1069
/*
#include <iostream>

using namespace std;

int main() {
	char grade;
	cin >> grade;
	switch (grade) {
	case 'A':
		cout << "best!!!" << endl;
		break;
	case 'B':
		cout << "good!!" << endl;
		break;
	case 'C':
		cout << "run!" << endl;
		break;
	case 'D':
		cout << "slowly~" << endl;
		break;
	default:
		cout << "what?" << endl;
		break;
	}
}
*/
// 1070
/*
#include <iostream>

using namespace std;

int main() {
	int season;
	cin >> season;
	switch (season) {
	case 3:
	case 4:
	case 5:
		cout << "spring" << endl;
		break;
	case 6:
	case 7:
	case 8:
		cout << "summer" << endl;
		break;
	case 9:
	case 10:
	case 11:
		cout << "fall" << endl;
		break;
	default:
		cout << "winter" << endl;
		break;
	}
}
*/
