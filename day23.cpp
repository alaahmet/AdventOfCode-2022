#include <bits/stdc++.h>
using namespace std;
int s[600][600];
bool check(int x,int y){
	bool flag = false;
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i==x and j==y)continue;
			if(s[i][j] == 1){
				flag = true;
			}
		}
	}
	return flag;
}
int main() {
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int lines = 70;
	vector <pair<int,int> > v;
	for(int i=0;i<lines;i++){
		string ss;
		cin >> ss;
		for(int j=0;j<ss.length();j++){
			if(ss[j] == '#'){
				s[i+300][j+300] = 1;
				v.push_back({i+300,j+300});
			}
		}
	}
	vector <pair <int,int> > q;
	bool flag;
	for(int rr=0;rr<INT_MAX;rr++){ // change INT_MAX to 10 for part-1
		q.clear();
		flag = false;
		int vis[600][600];
		for(int i=0;i<600;i++){
			for(int j=0;j<600;j++){
				vis[i][j] = 0;
			}
		}
		if(rr%4==0){
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					continue;
				}
				if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					vis[x-1][y]++;
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					vis[x+1][y]++;
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					vis[x][y-1]++;
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					vis[x][y+1]++;
				}
			}
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					q.push_back(res);
					continue;
				}
				if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					if(vis[x-1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x-1,y});
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					if(vis[x+1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x+1,y});
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					if(vis[x][y-1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y-1});
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					if(vis[x][y+1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y+1});
				}
				else{
					q.push_back({x,y});
				}
			}
		}
		if(rr%4==1){
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					continue;
				}
				if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					vis[x+1][y]++;
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					vis[x][y-1]++;
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					vis[x][y+1]++;
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					vis[x-1][y]++;
				}
			}
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					q.push_back(res);
					continue;
				}
				if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					if(vis[x+1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x+1,y});
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					if(vis[x][y-1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y-1});
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					if(vis[x][y+1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y+1});
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					if(vis[x-1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x-1,y});
				}
				else{
					q.push_back({x,y});
				}
			}
		}
		// n,so,w,e
		// w,e,n,so
		if(rr%4==2)
			assert(q.empty() and flag==false);
		if(rr%4==2){
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					continue;
				}
				if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					vis[x][y-1]++;
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					vis[x][y+1]++;
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					vis[x-1][y]++;
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					vis[x+1][y]++;
				}
			}
			// n,so,w,e
			// w,e,n,so
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					q.push_back(res);
					continue;
				}
				if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					if(vis[x][y-1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y-1});
				}
				else if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					if(vis[x][y+1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y+1});
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					if(vis[x-1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x-1,y});
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					if(vis[x+1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x+1,y});
				}
				else{
					q.push_back(res);
				}
			}
		}
		// n,so,w,e
		// e,n,so,w
		if(rr%4==3){
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					continue;
				}
				if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					vis[x][y+1]++;
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					vis[x-1][y]++;
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					vis[x+1][y]++;
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					vis[x][y-1]++;
				}
			}
			for(auto res:v){
				int x = res.first;
				int y = res.second;
				if(check(x,y) == false){
					q.push_back(res);
					continue;
				}
				if(s[x-1][y+1]==0 and s[x][y+1]==0 and s[x+1][y+1]==0){
					if(vis[x][y+1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y+1});
				}
				else if(s[x-1][y-1]==0 and s[x-1][y]==0 and s[x-1][y+1]==0){
					if(vis[x-1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x-1,y});
				}
				else if(s[x+1][y-1]==0 and s[x+1][y]==0 and s[x+1][y+1]==0){
					if(vis[x+1][y] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x+1,y});
				}
				else if(s[x-1][y-1]==0 and s[x][y-1]==0 and s[x+1][y-1]==0){
					if(vis[x][y-1] != 1){
						q.push_back({x,y});
						continue;
					}
					flag = true;
					q.push_back({x,y-1});
				}
				else{
					q.push_back(res);
				}
			}
		}
		v.clear();
		assert(v.size() == 0);
		for(int i=0;i<600;i++){
			for(int j=0;j<600;j++){
				s[i][j] = 0;
			}
		}
		for(auto x:q){
			s[x.first][x.second] = 1;
			v.push_back(x);
		}
		if(flag==false){
			cout << "Part-2: " << rr+1 << endl;
			exit(0);
		}
	}
	int n=1e9,so=-1e9,w=1e9,e=-1e9;
	for(auto res:v){
		n = min(n,res.first);
		so = max(so,res.first);
		w = min(w,res.second);
		e = max(e,res.second);
	}
	int ans = (so-n+1)*(e-w+1);
	ans = ans - v.size();
	// for(int i=n;i<=so;i++){
	// 	for(int j=w;j<=e;j++){;
	// 		if(s[i][j]==1)
	// 			cout<<'#';
	// 		else cout<<'.';
	// 	}
	// 	cout<<endl;
	// }
	// cout << n-300 << " " << so-300 << " " << w-300 << " "<< e-300 <<endl;
	cout << "Part-1: " << ans << endl;
}