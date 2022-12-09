#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
const int mx=10000;
int vis[2*mx][2*mx];
int tx[9];
int ty[9];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int hx,hy;
	hx = hy = mx;
	for(int i=0;i<9;i++){
		tx[i] = ty[i] = mx;
	}
	int lines = 2000;
	map <char,pair<int,int > > go;
	go['D'] = {0,-1};
	go['U'] = {0,1};
	go['L'] = {-1,0};
	go['R'] = {1,0};
	vis[tx[8]][ty[8]] = 1;
	for(int i=0;i<lines;i++){
		char c; int steps;
		cin >> c >> steps;
		for(int j=0;j<steps;++j){
			vis[tx[8]][ty[8]] = 1;
			hx += go[c].first;
			hy += go[c].second;
			if(abs(hx-tx[0]) + abs(hy-ty[0])<=1);// do nothing
			else if(((abs(hx-tx[0])==2) and (abs(hy-ty[0])==0)) or ((abs(hx-tx[0])==0) and (abs(hy-ty[0])==2)) ){ // 2steps l,r,d,u
				if(hx-tx[0]==2)tx[0]++;
				else if(tx[0]-hx==2)tx[0]--;
				else if(hy-ty[0]==2)ty[0]++;
				else if(ty[0]-hy==2)ty[0]--;
			}
			else if(abs(hx-tx[0])+abs(hy-ty[0])==3){
				if(hx>tx[0])tx[0]++;
				else tx[0]--;
				if(hy>ty[0])ty[0]++;
				else ty[0]--;
			}
			for(int k=1;k<9;k++){

				vis[tx[8]][ty[8]] = 1;
				if(abs(tx[k-1]-tx[k]) + abs(ty[k-1]-ty[k])<=1){
					// do nothing
					;
				}
				else if(((abs(tx[k-1]-tx[k])==2) and (abs(ty[k-1]-ty[k])==0)) or ((abs(tx[k-1]-tx[k])==0) and (abs(ty[k-1]-ty[k])==2)) ){ // 2steps l,r,d,u

					if(tx[k-1]-tx[k]==2)tx[k]++;
					else if(tx[k]-tx[k-1]==2)tx[k]--;
					else if(ty[k-1]-ty[k]==2)ty[k]++;
					else if(ty[k]-ty[k-1]==2)ty[k]--;
				}
				else if((abs(tx[k-1]-tx[k])==1 and abs(ty[k-1]-ty[k])==2) or ((abs(tx[k-1]-tx[k])==2 and abs(ty[k-1]-ty[k])==1))){
					if(tx[k-1]>tx[k])tx[k]++;
					else tx[k]--;
					if(ty[k-1]>ty[k])ty[k]++;
					else ty[k]--;
				}
				else if(abs(tx[k-1]-tx[k])==2 and abs(ty[k-1]-ty[k])==2){
					if(tx[k-1]>tx[k])tx[k]++;
					else tx[k]--;
					if(ty[k-1]>ty[k])ty[k]++;
					else ty[k]--;
				}
				vis[tx[8]][ty[8]] = 1;
			}
			vis[tx[8]][ty[8]] = 1;
		}
	}
	vis[tx[8]][ty[8]] = 1;
	int ans = 0;
	for(int i=0;i<2*mx;i++){
		for(int j=0;j<2*mx;j++){
			if(vis[i][j]==1){
				ans++;
			}
		}
	}
	cout << ans << endl;
}