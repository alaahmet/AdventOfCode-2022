#include <bits/stdc++.h>
using namespace std;
#define int long long
struct monkey{
	string left;
	string right;
	bool isNumber;
	char op;
	int number;
};
map <string,monkey> m;
map <string,int> coming;
int dfs(string x){
	if(m[x].isNumber == true){
		coming[x] = m[x].number;
		return m[x].number;
	}

	int l = dfs(m[x].left);
	int r = dfs(m[x].right);
	int res = 0;

	switch(m[x].op){
	case '+':
		res = l + r;
		break;
	case '-':
		res = l - r;
		break;
	case '*':
		res = l * r;
		break;
	case '/':
		res = l / r;
		break;
	}

	coming[x] = res;
	return res;
}
void go(string x,int val){
	if(x == "humn"){
		cout << val << endl;
		exit(0);
	}
	else if(m[x].isNumber == true){
		return;
	}
	int l = coming[m[x].left];
	int r = 0;
	switch(m[x].op){
	case '+':
		r = val - l;
		break;
	case '-':
		r = l - val;
		break;
	case '*':
		r = val / max(1LL,l);
		break;
	case '/':
		r = l / max(1LL,val);
		break;
	}
	go(m[x].right,r);
	r = coming[m[x].right];
	l = 0;
	switch(m[x].op){
	case '+':
		l = val - r;
		break;
	case '-':
		l = val + r;
		break;
	case '*':
		l = val / max(1LL,r);
		break;
	case '/':
		l = val * r;
		break;
	}
	go(m[x].left,l);
	return;
}
int32_t main() {
	freopen("input.txt","r",stdin);
	string input;
	while(getline(cin,input)){
		stringstream sstream{input};
		string name;
		sstream >> name;
		name = name.substr(0,name.length()-1);
		int number;
		string left,right;
		sstream >> left;
		char op;
		bool isNumber;
		if(left[0]>='0' and left[0]<='9'){
			number = stoi(left);
			isNumber = true;
			
		}
		else{
			sstream >> op >> right;
			isNumber = false;
		}
		monkey monk = {left,right,isNumber,op,number};
		m[name] = monk;
	}
	dfs("root");
	string left  = m["root"].left;
	string right = m["root"].right;
	go(left,coming[right]);
	go(right,coming[left]);
}
