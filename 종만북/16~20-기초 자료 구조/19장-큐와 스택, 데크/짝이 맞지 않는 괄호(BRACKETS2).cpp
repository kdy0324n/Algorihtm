#include<iostream>
#include<stack>
using namespace std;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string str; cin >> str;
		stack<char>st;
		bool b = true;
		for (auto i : str) {
			if (i == '(' || i == '[' || i == '{')st.push(i);
			else {
				if (st.empty()) { 
					b = false; break;
				}
				char t = st.top(); st.pop();
				if (i == ')' && t != '(') { b = false; break; }
				else if (i == ']' && t != '[') { b = false; break; }
				else if (i == '}' && t != '{') { b = false; break; }
			}
		}
		if (!st.empty())b = false;
		if (b)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}