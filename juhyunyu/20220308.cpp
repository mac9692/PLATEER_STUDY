#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	string str;
	string front, back;
	int f, b;
	cin >> str;
	int i;
	for (i = 0; i < str.length(); i++) {
		if (str[i] == '-') {
			front = str.substr(0, i);
			break;
		}
	}
	back = str.substr(i + 1);
	f = stoi(front);
	b = stoi(back);
    printf("%06d%d",f,b);
}
