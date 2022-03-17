// 1079
#include <stdio.h>

using namespace std;

int main() {
	char a;
	do {
		scanf("%s ", &a);
		printf("%c\n", a);
	} while (a != 'q');
}
// 1080
/*
#include <iostream>

using namespace std;

int main() {
	int n, sum, cnt = 0;
	cin >> n;

	for (cnt = 1; sum < n; cnt++) {
		sum = sum + cnt;
		if (sum >= n) {
			cout << cnt << endl;
		}
	}
	return 0;
}
*/
// 1081
/*
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << i << " " << j << endl;
		}
	}
}
*/
// 1083
/*
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
		if (i == 3 || i == 6 || i == 9) {
			cout << 'X' << " ";
		}
		else
		    cout << i << " ";
	
	}
	cout << endl;
}
*/
// 1084
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int r, g, b;
	int cnt = 0;
	cin >> r >> g >> b;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < g; j++) {
			for (int k = 0; k < b; k++) {
				printf("%d %d %d\n", i, j, k);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
*/
