#include <bits/stdc++.h>
using namespace std;
string s[250];
int main() {
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int lines = 200;
	int maxCol = 150;
	// int lines = 12;
	// int maxCol = 16;
	for(int i = 0; i<lines;i++){
		getline(cin, s[i]);
		int needed = maxCol - s[i].length();
		for(int j=0; j < needed; j++){
			s[i] += '@'; // stands for non-initialized elements
		}
		int idx = min(s[i].find('.'), s[i].find('#'));
		for(int j = 0; j < idx; j++){
			s[i][j] = '@';
		}
	}
	string str;
	cin >> str;
	// L: -1
	// R: -2
	vector <int> path;
	string res = "";
	assert(str[0] != 'L' and str[0] != 'R');
	assert(str[str.length()-1] != 'L' and str[str.length()-1] != 'R');
	for(int i=0;i<str.length();i++){
		if(str[i] == 'L'){
			path.push_back(stoi(res));
			res = "";			
			path.push_back(-1);
		}
		else if(str[i] == 'R'){
			path.push_back(stoi(res));
			res = "";
			path.push_back(-2);
		}
		else{
			res += str[i];
		}
	}
	path.push_back(stoi(res));
	pair <int,int> dir = {0,1}; // direction
	int n = maxCol;
	pair <int,int> cur; // current
	for(int i=0;i<n;i++){
		if(s[0][i] == '.'){
			cur = {0,i};
			break;
		}
	}
	for(auto x:path){
		// cout << dir.first << " " << dir.second << " " << x << endl;
		if(x == -1)
			dir = {-dir.second, dir.first};// L
		else if(x == -2)
			dir = {dir.second, -dir.first};// R
		else{
			pair <int,int> last = cur;
			while(x--){
				int ax = (cur.first + dir.first + lines) % lines;
				// cout << ax << endl;
				int bx = (cur.second + dir.second + n) % n;
				if(s[ax][bx] == '@'){
					x++;
					cur = {ax,bx};
				}
				else if(s[ax][bx] == '#')break;
				else if(s[ax][bx] == '.'){
					last = {ax,bx};
					cur = {ax,bx};
				}
			}
			cur = last;
		}
	}
	int x = cur.first;
	int y = cur.second;
	int facing;
	if(dir == make_pair(0,1))facing = 0;
	if(dir == make_pair(1,0))facing = 1;
	if(dir == make_pair(0,-1))facing = 2;
	if(dir == make_pair(-1,0))facing = 3;
	int ans = 1000*(x+1) + 4*(y+1) + facing;
	cout << ans << endl;
	cout << (x+1) << " " << (y+1) << endl;
}

// 126350