#include <bits/stdc++.h>
using namespace std;
const long long mx=8; // total monkey number
long long cnt[mx];

int main() {
	// HARDCODING GOES BRR	
	vector <long long> v[mx];
	v[0] = {50, 70, 89, 75, 66, 66};
	v[1] = {85};
	v[2] = {66, 51, 71, 76, 58, 55, 58, 60};
	v[3] = {79, 52, 55, 51};
	v[4] = {69, 92};
	v[5] = {71, 76, 73, 98, 67, 79, 99};
	v[6] = {82, 76, 69, 69, 57};
	v[7] = {65, 79, 86};
	long long mod = 2*7*13*3*19*5*11*17;
	long long rounds = 10000;

	for(long long i=1;i<=rounds;i++){
		
		for(auto x:v[0]){
			cnt[0]++;
			long long y = x*5;
			// y = y/3; /uncomment for part1
			if(y%2==0)v[2].push_back(y%mod);
			else v[1].push_back(y%mod);
		}v[0].clear();
		
		for(auto x:v[1]){
			cnt[1]++;
			long long y = x*x;
			// y = y/3;
			if(y%7==0)v[3].push_back(y%mod);
			else v[6].push_back(y%mod);
		}v[1].clear();

		for(auto x:v[2]){
			cnt[2]++;
			long long y = x+1;
			// y = y/3;
			if(y%13==0)v[1].push_back(y%mod);
			else v[3].push_back(y%mod);
		}v[2].clear();

		for(auto x:v[3]){
			cnt[3]++;
			long long y = x+6;
			// y = y/3;
			if(y%3==0)v[6].push_back(y%mod);
			else v[4].push_back(y%mod);
		}v[3].clear();

		for(auto x:v[4]){
			cnt[4]++;
			long long y = x*17;
			// y = y/3;
			if(y%19==0)v[7].push_back(y%mod);
			else v[5].push_back(y%mod);
		}v[4].clear();

		for(auto x:v[5]){
			cnt[5]++;
			long long y = x+8;
			// y = y/3;
			if(y%5==0)v[0].push_back(y%mod);
			else v[2].push_back(y%mod);
		}v[5].clear();

		for(auto x:v[6]){
			cnt[6]++;
			long long y = x+7;
			// y = y/3;
			if(y%11==0)v[7].push_back(y%mod);
			else v[4].push_back(y%mod);
		}v[6].clear();

		for(auto x:v[7]){
			cnt[7]++;
			long long y = x+5;
			// y = y/3;
			if(y%17==0)v[5].push_back(y%mod);
			else v[0].push_back(y%mod);
		}v[7].clear();

	}

	sort(cnt,cnt+8);
	cout << cnt[6]*cnt[7] << endl;

}