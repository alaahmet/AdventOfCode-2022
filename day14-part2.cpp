#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int vis[1500][1500];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int mx = 0;
	while (getline(cin, s)) {
		vector <pair<int,int> > v;
		int dec;
		char ch;
		int frac;
		string str;
		stringstream sstream = stringstream(s);
		while(sstream >> dec >> ch >> frac){
			sstream >> str;
			v.pb({dec,frac});
		}
		mx = max(mx,frac);
		v.pb({dec,frac});
		for(int i=1;i<v.size();i++){
			auto x = v[i-1];
			auto y = v[i];
			if(x.first == y.first){
				int minx = min(x.second,y.second);
				int maxx = max(x.second,y.second);
				for(int j=minx;j<=maxx;j++){
					vis[j][x.first] = 1;
				}
			}
			if(x.second == y.second){
				int minx = min(x.first,y.first);
				int maxx = max(x.first,y.first); 
				for(int j=minx;j<=maxx;j++){
					vis[x.second][j] = 1;
				}
			}
		}
	}
	mx = mx+2;
	for(int i=0;i<1500;i++){
		vis[mx][i] = 1;
	}
	int ans=0;
	while(1){
		if(vis[0][500]==1)break;
		int y = 500;
		int x = 0;
		bool flag = true;
		while(1){
			if(vis[x+1][y+1] == 1 and vis[x+1][y-1] == 1 and vis[x+1][y] == 1){
				vis[x][y] = 1;
				break;
			}
			else if(vis[x+1][y] == 0){ // down is empty
				x++;
			}
			else if(vis[x+1][y]==1 and vis[x+1][y-1]==0){ // left down
				x++;
				y--;
			}
			else if(vis[x+1][y]==1 and vis[x+1][y-1]==1 and vis[x+1][y+1]==0){ // right down
				x++;
				y++;
			}
			
			if(x==999){
				flag = false;
				break;
			}
		}
		if(flag==false){
			break;
		}
		ans++;
	}
	cout << ans << endl;
}
 
