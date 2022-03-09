#include <iostream>
#include <string>

using namespace std;

int main() {
	string w;

	cin >> w;
	string ww;
	for (int i = 0; i < w.length(); i++) {
		ww = w.substr(i, 1);
		cout << "'" << ww << "'" << endl;
		
	}

}
