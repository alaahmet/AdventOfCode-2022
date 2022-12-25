#include <bits/stdc++.h>
using namespace std;
#define int long long
list <pair <int,int> > v;
int32_t main() {
	freopen("input.txt","r",stdin);

	int n = 5000;

	list <pair <int,int > >:: iterator it = v.begin();
	list <pair <int,int > >:: iterator tit = v.begin();
	for(int i=0;i<n;i++){
		int x;cin >> x;
		v.push_back({i,x*811589153});
	}
	for(int cnt = 0; cnt<10; cnt++){
		for(int id=0;id<n;id++){
			int idx = -1;
			for(auto kit:v){
				idx++;
				if(kit.first == (id+cnt*n))break;
			}
			it = v.begin();
			advance(it, idx);
			int val = (*it).second;
			int rest = (val +  (int)(1e12)*(n-1))%(n-1);
			if(rest == 0){
				(*it).first = (*it).first + n;
				continue;
			}
			rest = rest + 1;
			while(rest--){
				it++;
				if(it == v.end()){
					it = v.begin();
				}
			}
			v.insert(it,make_pair(id+(cnt+1)*n,val));
			tit = v.begin();
			while(1){
				pair <int,int> p = *tit;
				if(p.first == id + cnt*n){
					v.erase(tit);
					break;
				}
				tit++;
			}
		}
	}
	int ans = 0;
	int md1 = 1000%n;
	int md2 = 2000%n;
	int md3 = 3000%n;
	it = v.begin();
	while(1){
		pair <int,int> p = *it;
		if(p.second ==0)break;
		it++;
		if(it == v.end())
			it = v.begin();
	}
	auto kit = it;
	while(md1--){
		kit++;
		if(kit == v.end())
			kit = v.begin();
	}
	ans += (*kit).second;
	kit = it;
	while(md2--){
		kit++;
		if(kit == v.end())
			kit = v.begin();
	}
	ans += (*kit).second;
	kit = it;
	while(md3--){
		kit++;
		if(kit == v.end())
			kit = v.begin();
	}
	ans += (*kit).second;
	cout << ans << endl;
}
