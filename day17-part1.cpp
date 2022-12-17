#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int mx=1e6+6;// 1000000
int a[mx][9];
string s;
int n;
int idx;
int low;
int res;
void go(vector <pair<int,int> > v,bool str){ // do string

	idx = idx%n;
	if(str == true){
		bool check  = true;
		for(auto t:v){
			int x = t.first;
			int y = t.second;
			if(s[idx]=='>'){
				if(a[x][y+1]==1)check = false;
			}
			else if(s[idx]=='<'){
				if(a[x][y-1]==1)check = false;
			}
		}
		if(check == true){
			vector <pair<int,int> > p;
			for(auto t:v){
				int x = t.first;
				int y = t.second;
				if(s[idx]=='>'){
					p.pb({x,y+1});
				}
				else if(s[idx]=='<'){
					p.pb({x,y-1});
				}
			}
			idx++;
			go(p,!str);
		}	
		else if(check == false){
			idx++;
			go(v,!str);
			return;
		}
	}
	else if(str == false){ // move down
		bool check = true;
		for(auto t:v){
			int x = t.first;
			int y = t.second;
			if(a[x-1][y]==1){
				check = false;
			}
		}
		if(check == true){
			vector <pair<int,int> > p;
			for(auto t:v){
				int x = t.first;
				int y = t.second;
				p.push_back({x-1,y});
			}
			go(p,!str);
		}
		else if(check == false){
			for(auto t:v){
				int x = t.first;
				int y = t.second;
				a[x][y] = 1;
				low = max(low,x);
			}
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> s;
	n = s.length();
	for(int i=0;i<mx;i++){
		for(int j=0;j<9;j++){
			if(i==0 or j==0 or j==8)
				a[i][j] = 1;
		}
	}
	low = 0;
	for(res=0;res<134;res++){
		cout << res << ": " << low << endl;
		if(res%5==0){
			vector <pair<int,int> > v;
			v.pb({low+4,3});
			v.pb({low+4,4});
			v.pb({low+4,5});
			v.pb({low+4,6});
			go(v,true);
		}
		else if(res%5==1){
			vector <pair<int,int> > v;
			v.pb({low+4,4});
			v.pb({low+5,3});
			v.pb({low+5,4});
			v.pb({low+5,5});
			v.pb({low+6,4});
			go(v,true);
		}
		else if(res%5==2){
			vector <pair<int,int> > v;
			v.pb({low+4,3});
			v.pb({low+4,4});
			v.pb({low+4,5});
			v.pb({low+5,5});
			v.pb({low+6,5});
			go(v,true);
		}
		else if(res%5==3){
			vector <pair<int,int> > v;
			v.pb({low+4,3});
			v.pb({low+5,3});
			v.pb({low+6,3});
			v.pb({low+7,3});
			go(v,true);
		}
		else if(res%5==4){
			vector <pair<int,int> > v;
			v.pb({low+4,3});
			v.pb({low+4,4});
			v.pb({low+5,3});
			v.pb({low+5,4});
			go(v,true);
		}
	}
	cout << low << endl;	
}
