#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	int packet_length = 14; // part-2, for part-1 substitute 4
	for(int i=0;i<s.length();i++){
		set <int> v;
		for(int j=i;j<i+packet_length;j++){
			v.insert(s[j]);
		}
		if(v.size()==packet_length){
			cout << i + packet_length << endl;
			break;
		}
	}
}
