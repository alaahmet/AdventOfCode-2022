#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 99; // lines
	string s[n];
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int m = s[0].length();
	set < pair <int,int> > sett;
	for(int i=0;i<n;i++){
		sett.insert({i,0});
		int j;
		char maks = s[i][0];
		for(j=1;j<m;++j){
			if(s[i][j]>maks){
				sett.insert({i,j});
				maks=max(s[i][j],maks);
			}
		}
		sett.insert({i,m-1});
		maks = s[i][m-1];
		for(j=m-2;j>=0;j--){
			if(s[i][j]>maks){
				sett.insert({i,j});
				maks=max(s[i][j],maks);
			}
		}
	}
	for(int j=0;j<m;j++){
		sett.insert({0,j});
		int i;
		char maks = s[0][j];
		for(i=1;i<n;++i){
			if(s[i][j]>maks){
				sett.insert({i,j});
				maks=max(s[i][j],maks);
			}
		}
		sett.insert({n-1,j});
		maks = s[n-1][j];
		for(i=n-2;i>=0;i--){
			if(s[i][j]>maks){
				sett.insert({i,j});
				maks=max(s[i][j],maks);
			}
		}
	}
	cout << sett.size() << endl; // part1
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int cnt = 0;
			int res = 1;
			int last = i;
			for(int k=i+1;k<n;k++){
				if(s[k][j]>=s[i][j]){
				++cnt;
				last=k;
				break;
			}
				else cnt++;
				last = k;
			}
			res = res*(abs(last-i));
			cnt=0;
			last = i;
			for(int k=i-1;k>=0;k--){
				if(s[k][j]>=s[i][j]){
					++cnt;
					last = k;
					break;
				}
				else cnt++;
				last = k;
			}

			res = res*(abs(last-i));
			cnt=0;
			last=j;
			for(int k=j+1;k<m;k++){
				if(s[i][k]>=s[i][j]){
					++cnt;
					last=k;
					break;
				}
				else cnt++;
				last = k;
			}
			res = res*(abs(last-j));
			cnt=0;
			last = j;
			for(int k=j-1;k>=0;k--){
				if(s[i][k]>=s[i][j]){
				++cnt;
				last=k;
				break;
			}
				else cnt++;
				last = k;
			}
			res = res*(abs(last-j));
			ans = max(ans,res);
		}
	}
	cout << ans << endl; // part2
}