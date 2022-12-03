#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int mx = 300;
	long long sum = 0;
	for(int i=0;i<mx/3;i++){
		string s;
		cin >> s;
		int n = s.length();
		char c;
		map <char, int> m;
		for(int j=0; j<n; j++){
			if(m[s[j]] == 0)
			 m[s[j]] = 1;
		}
		cin >> s;
		n = s.length();
		for(int j=0; j<n; j++){
			if(m[s[j]] == 1)
			 m[s[j]] = 2;
		}
		cin >> s;
		n = s.length();
		for(int j=0; j<n; j++){
			if(m[s[j]] == 2){
				m[s[j]] = 3;
				c = s[j];
			}
		}
		if(c>=65 and c<=90)
			sum += 27+c-65;
		else if(c>=97 and c<=122)
			sum += c-96;
		// cout << c << endl;
	}
	cout << sum << endl;


}
