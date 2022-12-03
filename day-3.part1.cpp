#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int mx = 300; //input line size
	long long sum = 0;
	for(int i=0;i<mx;i++){
		string s;
		cin >> s;
		int n = s.length();
		map <char, int> m;

		for(int i=0; i<n/2; i++){
			if(m[s[i]] == 0)
			 m[s[i]] = 1;
		}
		char c = '.';
		for(int i=n/2 ;i<n; i++){
			if(m[s[i]] == 1)
				c = s[i];
		}
		if(c>=65 and c<=90)
			sum += 27+c-65;
		else if(c >= 97 and c <= 122)
			sum += c-96;
	}
	cout << sum << endl;


}
 
 