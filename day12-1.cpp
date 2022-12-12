#include <bits/stdc++.h>
using namespace std;
const int mx=2000;
int vis[mx][mx];
int dis[mx][mx];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
// 368
int main() {	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int lines = 41; // line size
	string s[lines];
	int ansx=0,ansy=0;
	for(int i=0;i<lines;i++){
		cin >> s[i];
		for(int j=0;j<s[i].length();j++){
			if(s[i][j] == 'E'){
				ansx = i;
				ansy = j;
			}
		}
	}
	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			dis[i][j] = 1e9;
		}
	}
	queue <pair<int,int> > q;
	q.push({20,0});
	dis[20][0] = 0;
	int len = s[0].length();
	s[20][0] = 'a';
	s[ansx][ansy] = 'z';
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(min(nx,ny)<0 or ny>=len or nx>=lines)continue;
			if(s[x][y]+1 < s[nx][ny])continue;
			if(dis[nx][ny]==1e9){
				q.push({nx,ny});
				dis[nx][ny] = dis[x][y]+1;
			}
		}
	}
	cout << dis[ansx][ansy] << endl;


}
 
