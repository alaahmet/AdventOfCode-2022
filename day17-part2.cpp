#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int mx=1e6+6;// 1000000
int a[mx][9];
#define int long long
string s;
int n;
int idx;
int low;
int res;
void go(vector <pair<int,int> > v,bool str){ // do stringd
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
int32_t main() {
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> s;
	n = s.length();
	for(int i=0;i<mx;i++){
		for(int j=0;j<9;j++){
			if(i==0 or j==0 or j==8)
				a[i][j] = 1;
		}
	}
	low = 0;
	idx=0;
	map <int,int> mlow;
	map <int,int> mres;
	for(res=0;res<100000;res++){
		mlow[low] = res;
		mres[res] = low;
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
	map <string,int> m;
	int start,end;
	int left,right;
	// FINDING THE CYCLE
	for(int i=0;i<=20000;i++){
		string s = "";
		for(int j=0;j<1000;j++){
			for(int k=1;k<=7;k++){
				if(a[i+j][k]==1)s+='1';
				else s+='0';
			}
		}
		if(m[s]!=0){
			end = i;
			right = mlow[end];
			start = m[s];
			left = mlow[start];
			break;
		}
		else
			m[s] = i;
	}
	// FINDING THE CYCLE
	int top = 1e12;
	int div = (top-left)/(right-left);
	cout << div << endl;
	int rest = top - (left + div*(right-left));
	cout << rest << endl;
	int ans = div*(end-start)+start+mres[right+rest]-mres[right];
	cout << ans << endl;

}
