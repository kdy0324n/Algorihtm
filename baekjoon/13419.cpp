#include<iostream>
#include<string>

using namespace std;

int main(){
	int T;
	cin >> T;
	string input;
	for(int i = 0; i < T; i++)
	{
		cin >> input;
		int n = input.size();
		string user1(""), user2("");
		if(n%2==0)	{
			for(int j = 0; j < n; j=j+2)
			{
				user1.push_back(input[j]);
                if(j+1<n)
				    user2.push_back(input[j+1]);
			}
			cout << user1 << "\n";
			cout << user2 << "\n";
		}
		else{
			for(int j = 0; j < n; j=j+2)
			{
				user1.push_back(input[j]);
                if(j+1<n)
				    user2.push_back(input[j+1]);
			}
			for(int j = 0; j < n; j=j+2)
			{
                if(j+1<n)
				    user1.push_back(input[j+1]);
				user2.push_back(input[j]);
			}
			cout << user1 << "\n";
			cout << user2 << "\n";
		}
	}
	return 0;
}