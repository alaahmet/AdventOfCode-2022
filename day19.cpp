#include <bits/stdc++.h>
using namespace std;
int oreore,clayore,obsore,obsclay,geoore,geoobs;
int maxore;
int maxclay;
int maxobs;
int ans;
void go(int minute,int ore,int clay,int obs,int geo,int orerob,int clayrob,int obsrob,int georob,int mask){
	if(minute==25){
		if(geo>ans){
			ans = max(ans, geo);
		}
		return;
	}
	int newore = orerob + ore;
	int newclay = clay + clayrob;
	int newobs = obs + obsrob;
	int newgeo = geo + georob;
	// Assuming we can not build more than one robot in the same minute
	// When we are able to build geo robot we build it immediately
	// If we don't build the robot even though we are able to, then we don't build it in the further rounds until we build another one. ::mask::
	// If it is unnecessary to build a robot don't build it, e.g. we have 10 ore robots while max needed ore for building a robot is 10.So we don't build ore robots anymore
	if(ore>=geoore and obs>=geoobs) // geo robot
		go(minute+1,newore-geoore,newclay,newobs-geoobs,newgeo,orerob,clayrob,obsrob,georob+1,0);
	else{
		if(ore>=obsore and clay>=obsclay and maxobs > obsrob and ((mask&4)==0)){ // obs robot
			go(minute+1,newore-obsore,newclay-obsclay,newobs,newgeo,orerob,clayrob,obsrob+1,georob,0);
			mask = mask|4;	
		}
		if(ore >= clayore and maxclay > clayrob and ((mask&2)==0)){ // clay robot
			go(minute+1,newore-clayore,newclay,newobs,newgeo,orerob,clayrob+1,obsrob,georob,0);
			mask = mask|2;		
		}
		if(ore >= oreore and maxore > orerob and ((mask&1)==0)){ // ore robot
			go(minute+1,newore-oreore,newclay,newobs,newgeo,orerob+1,clayrob,obsrob,georob,0);
			mask = mask|1;
		}
		if((ore>=obsore and clay>=obsclay and maxobs > obsrob)==false
			or (ore >= clayore and maxclay > clayrob) ==false or (ore >= oreore and maxore > orerob)==false)
			go(minute+1,newore,newclay,newobs,newgeo,orerob,clayrob,obsrob,georob,mask);
	}
}
void go2(int minute,int ore,int clay,int obs,int geo,int orerob,int clayrob,int obsrob,int georob,int mask){
	if(minute==33){
		if(geo>ans){
			ans = max(ans, geo);
		}
		return;
	}
	int newore = orerob + ore;
	int newclay = clay + clayrob;
	int newobs = obs + obsrob;
	int newgeo = geo + georob;
	// Assuming we can not build more than one robot in the same minute
	// When we are able to build geo robot we build it immediately
	// If we don't build the robot even though we are able to, then we don't build it in the further rounds until we build another one. ::mask::
	// If it is unnecessary to build a robot don't build it, e.g. we have 10 ore robots while max needed ore for building a robot is 10.So we don't build ore robots anymore
	if(ore>=geoore and obs>=geoobs) // geo robot
		go2(minute+1,newore-geoore,newclay,newobs-geoobs,newgeo,orerob,clayrob,obsrob,georob+1,0);
	else{
		if(ore>=obsore and clay>=obsclay and maxobs > obsrob and ((mask&4)==0)){ // obs robot
			go2(minute+1,newore-obsore,newclay-obsclay,newobs,newgeo,orerob,clayrob,obsrob+1,georob,0);
			mask = mask|4;	
		}
		if(ore >= clayore and maxclay > clayrob and ((mask&2)==0)){ // clay robot
			go2(minute+1,newore-clayore,newclay,newobs,newgeo,orerob,clayrob+1,obsrob,georob,0);
			mask = mask|2;		
		}
		if(ore >= oreore and maxore > orerob and ((mask&1)==0)){ // ore robot
			go2(minute+1,newore-oreore,newclay,newobs,newgeo,orerob+1,clayrob,obsrob,georob,0);
			mask = mask|1;
		}
		if((ore>=obsore and clay>=obsclay and maxobs > obsrob)==false
			or (ore >= clayore and maxclay > clayrob) ==false or (ore >= oreore and maxore > orerob)==false)
			go2(minute+1,newore,newclay,newobs,newgeo,orerob,clayrob,obsrob,georob,mask);
	}
}
int main() {
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int n = 30;
	int part1 = 0;
	int part2 = 1;
	string s;
	for(int i=1;i<=n;i++){
		int day;
		scanf("Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.\n",&day,&oreore,&clayore,&obsore,&obsclay,&geoore,&geoobs);
		maxore = max(oreore,max(clayore,max(obsore,geoore)));
		maxclay = obsclay;
		maxobs = geoobs;
		ans = 0;
		go(1,0,0,0,0,1,0,0,0,0);
		// cout << "Blueprint: " << i << " " << ans << endl;
		part1 += ans*i;
		if(i<4){
			ans = 0;
			go2(1,0,0,0,0,1,0,0,0,0);
			part2 *= ans;
		}
	}
	cout << "Part-1: " << part1 << endl;
	cout << "Part-2: " << part2 << endl;
	
}
//   Time (mean ± σ):      74.0 ms ±   6.2 ms    [User: 73.3 ms, System: 0.7 ms]
