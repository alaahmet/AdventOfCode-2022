#include <bits/stdc++.h>
using namespace std;
set <int> s;
int lines;
struct item{
	int x,y,a,b;
	int dis;
};
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	int x,y,z,t;
	lines = 38;
	int beaconX,beaconY;
	int beaconsOnRow = 0;
	vector <item> v; // for part2
	vector <pair <int,int> > c; // for part2
	// in part-1 only checking for row = 2000000
	for(int i=0;i<lines;i++){
		int x,y,beaconX,beaconY;
		cin >> x >> y >> beaconX >> beaconY;
		int dist = abs(x-beaconX) + abs(y-beaconY);
		item it = {x,y,beaconX,beaconY,dist};

		// for part1
		if(beaconY == 2000000)beaconsOnRow++;
		for(int j=-6e6;j<6e6;j++){
			beaconX = j;
			beaconY = 2000000;
			if(x == beaconX and y == beaconY)continue;
			int res = abs(x-beaconX) + abs(y-beaconY);
			if(res <= dist){
				s.insert(j);
			}
		}
		// for part1

		// for part2
		// using the fact that the distress beacon is unique
		// it needs to have a manhattan distance+1 to an another beacon
		// putting possible candidates into my c vector, and will check them afterwards for all sensors in v vector
		v.push_back(it);
		for(int j=0;j<=dist+1;j++){
			int fst;int sec;
			fst = j;
			sec = dist+1-fst;
			c.push_back({x+fst,y+sec});
			c.push_back({x-fst,y+fst});
			c.push_back({x-fst,y-sec});
			c.push_back({x+fst,y-sec});
		}
		// for part2

	}
	cout << "Part1: " <<  s.size()-beaconsOnRow << endl;

	pair <long long, long long> ans;
	for(auto co: c){
		bool check = true;
		if(min(co.first,co.second) >= 0 and max(co.first,co.second) <= 4e6); // constraints check
		else continue;
		for(auto it: v){
			if(it.dis >= abs(it.x-co.first) + abs(it.y-co.second)){
				// if the possible candidate co is closer than beacon
				check = false;
			}
		}
		if(check)
			ans = {co.first, co.second};
	}
	cout << "Part2: " << (ans.first*4000000+ans.second) << endl;

}
