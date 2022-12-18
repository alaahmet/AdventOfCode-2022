#include <bits/stdc++.h>
using namespace std;
const int mx=50;
int a[mx][mx][mx];
struct co{
	int x,y,z;
};
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};
int vis[25][25][25];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	vector <co> v;	
	string s;
	int ans = 0;
	while(cin >> s){
		stringstream ss{s};
		int x,y,z;
		char ch;
		ss >> x >> ch >> y >> ch >> z;
		a[x+1][y+1][z+1] = 1;
		v.push_back({x+1,y+1,z+1});
	}
	for(auto res:v){
		for(int i=0;i<6;i++){
			if(a[res.x+dx[i]][res.y+dy[i]][res.z+dz[i]] == 0)
				ans++;
		}
	}
	cout << "Part-1: " << ans << endl;
	ans = 0;
	queue <co> q;
	q.push({22,22,22});
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		if(x>22 or y>22 or z>22 or x<0 or y<0 or z<0)continue;
		if(vis[x][y][z] == 1)continue;
		vis[x][y][z] = 1;
		for(int i=0;i<6;i++){
			if(a[x+dx[i]][y+dy[i]][z+dz[i]] == 1)
				ans++;
		}
		for(int i=0;i<6;i++){
			if(a[x+dx[i]][y+dy[i]][z+dz[i]]==1) continue;
			else if(vis[x+dx[i]][y+dy[i]][z+dz[i]] == 1)continue;
			q.push({x+dx[i],y+dy[i],z+dz[i]});
		}
	}
	cout << "Part-2: " << ans << endl;
}