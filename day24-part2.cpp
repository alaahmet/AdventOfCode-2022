#include <bits/stdc++.h>
using namespace std;
string s[30];
int sx,sy;
int ex,ey;
int lines,n;
int mod;
int dp[3][30][150][6000];
struct blizz{
	int dirx;
	int diry;
	int posx;
	int posy;
};
struct bfs{
	int x;
	int y;
	int time;
	vector <blizz> b;
	int round;
};
int ans;

int main() {
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	for(int rr=0;rr<3;rr++){
		for(int i=0;i<30;i++){
			for(int j=0;j<150;j++){
				for(int k=0;k<6000;k++){
					dp[rr][i][j][k] = 1e9;
				}
			}
		}	
	}
	
	ans = 1e9;
	lines = 22;
	for(int i=0;i<lines;i++){
		cin >> s[i];
	}
	n = s[0].length();
	mod = (lines-2)*n;
	for(int j=0;j<n;j++){
		if(s[0][j] == '.'){
			sx = 0;
			sy = j;
			break;
		}
	}
	vector <blizz> ob;
	for(int i=0;i<lines;i++){
		for(int j=0;j<n;j++){
			if(s[i][j] == 'v'){
				ob.push_back({1,0,i,j});
			}
			else if(s[i][j] == '<'){
				ob.push_back({0,-1,i,j});
			}
			else if(s[i][j] == '>'){
				ob.push_back({0,1,i,j});
			}
			else if(s[i][j] == '^'){
				ob.push_back({-1,0,i,j});
			}
		}
	}
	queue <bfs> q;
	q.push({sx,sy,0,ob,0});
	while(!q.empty()){
		bfs res = q.front();
		q.pop();
		int x = res.x;
		int y = res.y;
		int time = res.time;
		vector <blizz> b = res.b;
		int round = res.round;
		if(x==-1 or x==lines)continue;
		if(s[x][y] == '#')continue;
		if((round == 0) and (x==lines-1)){
			round = 1;
		}
		if((round == 1) and (x==0)){
			round = 2;
		}
		if((round == 2) and (x==lines-1)){
			if(ans > time){
				ans = time;
				cout << ans << endl;
			}
			return 0;
		}
		bool check = true;
		for(int f=0;f<b.size();f++){
			if(b[f].posx == x){
				if(b[f].posy == y){
					check = false;
				}
			}
		}
		if(check == false)continue;
		if(dp[round][x][y][time%mod] <= time){
			continue;
		}
		dp[round][x][y][time%mod] = time;
		vector <blizz> ne;
		for(int f=0;f<b.size();f++){
			b[f].posx = b[f].posx + b[f].dirx;
			b[f].posy = b[f].posy + b[f].diry;
			if(b[f].posx==lines-1)
		      b[f].posx = 1;
		    if(b[f].posx == 0)
		      b[f].posx = lines-2;
		    if(b[f].posy==n-1)
		      b[f].posy = 1;
		    if(b[f].posy == 0)
		      b[f].posy = n-2;
			ne.push_back({b[f].dirx,b[f].diry,b[f].posx,b[f].posy});
		}
		q.push({x,y,time+1,ne,round});
		q.push({x,y+1,time+1,ne,round});
		q.push({x,y-1,time+1,ne,round});
		q.push({x-1,y,time+1,ne,round});
		q.push({x+1,y,time+1,ne,round});
	}
}
