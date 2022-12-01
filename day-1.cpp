#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	long ans=0;
	long sum=0;
	vector<int> v;
	string line;
	while(getline(cin,line)){
		if(line.size()){
            		long x=stoi(line);
			sum+=x;
		}
        	else{
        		v.push_back(sum);
        		ans=max(sum,ans);
			sum=0;
        	}
	}

	v.push_back(sum);
	ans=max(sum,ans);
	sort(v.begin(),v.end());
	int n=v.size();
	cout << (v[n-1]) << endl;
	cout << (v[n-1]+v[n-2]+v[n-3]) << endl;

}

 
