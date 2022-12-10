#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string inp;
	string s = "";
	queue <int > q;
	int cyc = -1;
	long long ans = 0;
	int reg = 1;
	while (getline(cin, inp)) {
		cyc++;
		if(cyc>=40){
    		cout << endl;
    		cyc = cyc%40;
    	}
		int find = inp.find(" ");
		string op = inp.substr(0,find);
		if(op[0]=='n')
			q.push(1e9);
		else{
			int val = stoi(inp.substr(find));
			q.push(1e9);
			q.push(val);
   		}
   		int x = q.front();
   		q.pop();
   		
   		if(cyc<reg-1 or cyc>reg+1)cout<<".";
   		else cout<<"#";
   		if(x==1e9);
   		else reg += x;
    }
    while(!q.empty()){
    	++cyc;
    	if(cyc>=40){
    		cout << endl;
    		cyc = cyc%40;
    	}
    	int x = q.front();
   		q.pop();
   		if(cyc<reg-1 or cyc>reg+1)cout<<".";
   		else cout<<"#";
   		if(x==1e9);
   		else reg += x;
    }

    cout << s << endl;
}