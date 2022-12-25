#include <bits/stdc++.h>
using namespace std;
list <pair <int,int> > v;
int main() {
	freopen("input.txt","r",stdin);

	int n = 5000;

	list <pair <int,int > >:: iterator it = v.begin();
	list <pair <int,int > >:: iterator tit = v.begin();
	for(int i=0;i<n;i++){
		int x;cin >> x;
		v.push_back({i,x});
	}
	for(int id=0;id<n;id++){
		int idx = -1;
		for(auto kit:v){
			idx++;
			if(kit.first == id)break;
		}
		it = v.begin();
		advance(it, idx); 
		int val = (*it).second;
		int rest = (val +  10000*(n-1))%(n-1);
		if(rest == 0)continue;
		rest = rest + 1;
		while(rest--){
			it++;
			if(it == v.end()){
				it = v.begin();
			}
		}
		v.insert(it,make_pair(id+n,val));
		tit = v.begin();
		while(1){
			pair <int,int> p = *tit;
			if(p.first == id){
				v.erase(tit);
				break;
			}
			tit++;
		}
	}
	cout << endl;
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
