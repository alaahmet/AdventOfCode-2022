#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int mx=10000;
int vis[2*mx][2*mx];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int hx,hy,tx,ty;
	hx = hy = tx = ty = mx;
	int lines = 2000;
	map <char,pair<int,int > > go;
	go['D'] = {0,-1};
	go['U'] = {0,1};
	go['L'] = {-1,0};
	go['R'] = {1,0};
	vis[tx][ty] = 1;
	for(int i=0;i<lines;i++){
		char c; int steps;
		cin >> c >> steps;
		for(int j=0;j<steps;++j){
			vis[tx][ty] = 1;
			hx += go[c].first;
			hy += go[c].second;
			if(abs(hx-tx) + abs(hy-ty)<=1);// do nothing
			else if(((abs(hx-tx)==2) and (abs(hy-ty)==0)) or ((abs(hx-tx)==0) and (abs(hy-ty)==2)) ){ // 2steps l,r,d,u
				if(hx-tx==2)tx++;
				else if(tx-hx==2)tx--;
				else if(hy-ty==2)ty++;
				else if(ty-hy==2)ty--;
			}
			else if(abs(hx-tx)+abs(hy-ty)==3){
				if(hx>tx)tx++;
				else tx--;
				if(hy>ty)ty++;
				else ty--;
			}
		}
	}

	int ans = 0;
	for(int i=0;i<2*mx;i++){
		for(int j=0;j<2*mx;j++){
			if(vis[i][j]==1)ans++;
		}
	}
	cout << ans << endl;
}