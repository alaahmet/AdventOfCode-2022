#include <bits/stdc++.h>
using namespace std;
const int mx=62;
vector <int> g[mx];
map <string,int> m;
int val[mx];
int ans;
int dist[mx][mx];
vector <int> nonzero;
int nid[mx];
map <int,int> v;
void go(int valve,int minute,int pres,int sum,int bw){
	if(minute>27)return;
	else if(minute==27){
		v[bw] = max(v[bw],sum);
		return;
	}
	sum += pres;
	
	go(valve,minute+1,pres,sum,bw);
	
	for(auto y:nonzero){
		if((bw & (1<<nid[y])) != 0) continue;
		if(dist[valve][y]==-1e9);
		else go(y,minute+dist[valve][y]+1,pres+val[y],sum+(dist[valve][y])*pres,bw  | (1<<nid[y]));
	}

}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin); 
	// freopen("output.txt","w",stdout);

	string line;
	int id = 1;
	int niden = 0;
	for(int i=0;i<mx;i++)nid[i] = -1e9;
	while(getline(cin,line)){
		stringstream ss{line};
		string x;
		string y;
		int value;
		ss >> x >> value;
		if(m[x] == 0) m[x] = id++;
		val[m[x]] = value;
		while(ss>>y){
			if(m[y] == 0)m[y] = id++;
			g[m[x]].push_back(m[y]);
		}
		if(value>0){
			nonzero.push_back(m[x]);
			nid[m[x]] = niden++;
		}
	}
	for(int i=0;i<mx;i++){
		for(int j=0;j<mx;j++){
			dist[i][j] = - 1e9;
		}
	}

	for(int i=1;i<=60;i++){
		queue <pair<int,int> > q;
		q.push({i,0});
		while(!q.empty()){
			int x = q.front().first;
			int dis = q.front().second;
			q.pop();
			if(dist[i][x]>=0)continue;
			dist[i][x] = dis;
			for(auto y:g[x]){
				q.push({y,dis+1});
			}
		}
	}

	int start = m["AA"];
	for(auto y:nonzero){
		if(start==y)continue;
		if(dist[start][y]==-1e9)continue;
		go(y,dist[start][y]+2,val[y],0,1<<(nid[y]));
	}

	int ans = 0;	
	for(auto x = v.begin(); x!=v.end(); x++){
		for(auto y = v.begin(); y!=v.end(); y++){
			if(((x->first) & (y->first)) == 0){
				int sum = (x->second)+(y->second);
				ans = max(ans,sum);
			}
		}
	}

	cout << ans << endl;
}
