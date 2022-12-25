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
int dfs(string x){
	if(m[x].isNumber == true){
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
	return res;
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
	cout << dfs("root") << endl;

}
