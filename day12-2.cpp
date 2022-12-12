#include <bits/stdc++.h>
using namespace std;
const int mx=2000;
int vis[mx][mx];
int dis[mx][mx];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int lines = 41;
	string s[lines];
	int endx=0,endy=0,startx=0,starty=0;
	for(int i=0;i<lines;i++){
		cin >> s[i];
		for(int j=0;j<s[i].length();j++){
			if(s[i][j] == 'E'){
				endx = i;
				endy = j;
			}
			else if(s[i][j] == 'S'){
				startx = i;
				starty = j;
			}
		}
	}
	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			dis[i][j] = 1e9;
		}
	}
	queue <pair<int,int> > q;
	q.push({endx,endy});
	dis[endx][endy] = 0;
	int len = s[0].length();
	s[endx][endy] = 'z';
	s[startx][starty] = 'a';

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		if(x==endx and y==endy);
		else if(s[x][y]=='a'){
			cout<<dis[x][y] << endl;
			break;
		}
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(min(nx,ny)<0 or ny>=len or nx>=lines)continue;
			if(!(s[x][y] <= (s[nx][ny]+1)))continue;
			if(dis[nx][ny]==1e9){
				q.push({nx,ny});
				dis[nx][ny] = dis[x][y]+1;
			}
		}
	}

}
 
