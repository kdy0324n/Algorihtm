#include<iostream>
#include<string>
using namespace std;


string str;
int key = 0;
string rev() {
	char head = str[key];
	++key;
	if (head == 'b' || head == 'w') {
		string re(1, head);
		return re;
	}
	string upperLeft = rev();
	string upperRight = rev();
	string lowerLeft = rev();
	string lowerRight = rev();

	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		key = 0;
		cout << rev()<<'\n';
	}


	return 0;
}