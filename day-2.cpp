#include <bits/stdc++.h>
using namespace std;
int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	pair <char,char> pc [9] = {{'A','X'},{'A','Y'},{'A','Z'},{'B','X'},{'B','Y'},{'B','Z'},{'C','X'},{'C','Y'},{'C','Z'}};
	int res[9] = {4,8,3,1,5,9,7,2,6};
	int ans=0;
	int mx=2500; // input line size
	vector <pair<char,char> > vp;
	for(int i=0;i<mx;i++){
		char x,y;cin>>x>>y;
		vp.push_back({x,y});
		for(int j=0;j<9;j++){
			if(pc[j].first==x and pc[j].second==y)ans+=res[j];
		}
	}
	cout << "Part-1: " << ans << endl; // part1
	
	ans=0;
	int rep[9] = {3,4,8,1,5,9,2,6,7};
	for(int i=0;i<mx;i++){
		int x = vp[i].first;
		int y = vp[i].second;
		for(int j=0;j<9;j++){
			if(pc[j].first==x and pc[j].second==y)ans+=rep[j];
		}
	}
	cout << "Part-2: " << ans << endl; // part2

}	

