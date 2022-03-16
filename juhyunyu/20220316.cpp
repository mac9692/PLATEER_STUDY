// 1071
#include <iostream>

using namespace std;

int main() {
	int n;
reload:
	cin >> n;

	
	if (n != 0) {
		cout << n << endl;
		goto reload;

	}
}
// 1072
/*
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n;
reget:
	cin >> m;
	
	if (n-- != 0) {
	    cout << m << endl;
	    goto reget;
	}
}
*/
// 1073
/*
#include <iostream>

using namespace std;

int main() {
	int n;
	
reload:
	cin >> n;
	if (n != 0) {
		cout << n << endl;
		goto reload;
	}
		
}
*/
// 1074
/*
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		cout << n << endl;
		--n;
	}
		
}
*/
// 1075
/*
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		--n;
		cout << n << endl;
		
	}
		
}
*/
// 1076
/*
#include <iostream>

using namespace std;

int main() {
	char a, x = 'a';
	cin >> a;
	do {
		cout << x << endl;
		x = x + 1;
	} while (x < a + 1);
		
}
*/
// 1077
/*
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << i << endl;
	}
}
*/
// 1078
/*
#include <iostream>

using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)
			sum += i;
	}
	cout << sum << endl;
}
*/
