#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int lines = 502;
	int strings = 9;
	string s[10];
	
	s[1] = "WLS";
	s[2] = "QNTJ";
	s[3] = "JFHCS";
	s[4] = "BGNWMRT";
	s[5] = "BQHDSLRT";
	s[6] = "LRHFVBJM";
	s[7] = "MJNRWD";
	s[8] = "JDNHFTZB";
	s[9] = "TFBNQLH";



	for(int i = 0; i < lines ; i++){
		int x, from, to;
		cin >> x >> from >> to;
		//removed "move" "from" "to" from the input file with a text editor
		string t = s[from].substr(0, x);
		reverse(t.begin(), t.end()); // comment this line for part-1
		s[to] = t + s[to];
		string m = s[from].substr(x);
		s[from].clear();
		s[from] = m;
		// cout <<s[1] << " "<< s[2] << " "<<s[3] << endl;
	}	
	for(int i = 1; i <= strings; ++i){
		cout << s[i][0];
	}


}
 
