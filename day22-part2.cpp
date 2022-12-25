#include <bits/stdc++.h>
using namespace std;
string s[250];
int main(){
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
	pair <int,int> dir = {0,1}; // direction, right at the beginning
	int n = maxCol;
	pair <int,int> cur; // current
	for(int i=0;i<n;i++){
		if(s[0][i] == '.'){
			cur = {0,i};
			break;
		}
	}
	int i = cur.first;
	int j = cur.second;
	pair <int,int> down = {1,0};
	pair <int,int> up = {-1,0};
	pair <int,int> left = {0,-1};
	pair <int,int> right = {0,1};
	for(auto x:path){
		if(x == -1)
			dir = {-dir.second, dir.first};// L
		else if(x == -2)
			dir = {dir.second, -dir.first};// R
		else{
			while(x--){
				if(0<=i and i<=49 and 100<=j and j<=149){// 1
					if(i==49 and dir==down){
						int nextx = 50 + j - 100;
						int nexty = 99;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else if(i==0 and dir==up){
						int nextx = 199;
						int nexty = j - 100;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==149 and dir==right){
						int nextx = 100 + 49 - i;
						int nexty = 99;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else if(j==100 and dir==left){
						int nextx = i;
						int nexty = 99;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}
				else if(0<=i and i<=49 and 50<=j and j<=99){// 2
					if(i==49 and dir==down){
						int nextx = 50;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}
					else if(i==0 and dir==up){// 2->6
						int nextx = 150 + j - 50;
						int nexty = 0;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = right;
					}
					else if(j==99 and dir==right){
						int nextx = i;
						int nexty = 100;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = right;
					}
					else if(j==50 and dir==left){
						int nextx = 100 + 49 - i;
						int nexty = 0;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}
				else if(50<=i and i<=99 and 50<=j and j<=99){// 3
					if(i==99 and dir==down){
						int nextx = 100;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}
					else if(i==50 and dir==up){
						int nextx = 49;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==99 and dir==right){// 3 -> 1
						int nextx = 49;
						int nexty = 100 + i - 50;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==50 and dir==left){// 3 -> 5
						int nextx = 100;
						int nexty = 0 + i - 50;;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}	
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}
				else if(100<=i and i<=149 and 50<=j and j<=99){// 4
					if(i==149 and dir==down){// 4->6
						int nextx = 150 + j - 50;
						int nexty = 49;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else if(i==100 and dir==up){
						int nextx = 99;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==99 and dir==right){// 4 -> 1
						int nextx = 49 - (i - 100);
						int nexty = 149;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else if(j==50 and dir==left){// 4 -> 5
						int nextx = i;
						int nexty = 49;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = left;
					}
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}
				else if(100<=i and i<=149 and 0<=j and j<=49){// 5
					if(i==149 and dir==down){// 5 -> 6
						int nextx = 150;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}
					else if(i==100 and dir==up){// 5->3
						int nextx = 50 + j;
						int nexty = 50;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = right;
					}
					else if(j==99 and dir==right){// 5 -> 4
						int nextx = x;
						int nexty = 50;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = right;
					}
					else if(j==50 and dir==left){// 5 -> 2
						int nextx = 0 + 49 - (i - 100);
						int nexty = 50;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = right;
					}
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}
				else if(150<=i and i<=199 and 0<=j and j<=49){// 6
					if(i==199 and dir==down){// 6->1
						int nextx = j + 100;
						int nexty = 0;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}
					else if(i==150 and dir==up){ // 6->5
						int nextx = 149;
						int nexty = j;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==49 and dir==right){// 6 -> 4
						int nextx = 149;
						int nexty = 50 + (i - 150);
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = up;
					}
					else if(j==0 and dir==left){// 6 -> 2
						int nextx = 0;
						int nexty = 50 + (i - 150);
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
						dir = down;
					}
					else{
						int nextx = i + dir.first;
						int nexty = j + dir.second;
						if(s[nextx][nexty] == '#')break;
						i = nextx;
						j = nexty;
					}
				}

			}
		}
	}
	int x = i;
	int y = j;
	int facing;
	if(dir == make_pair(0,1))facing = 0;
	if(dir == make_pair(1,0))facing = 1;
	if(dir == make_pair(0,-1))facing = 2;
	if(dir == make_pair(-1,0))facing = 3;
	int ans = 1000*(x+1) + 4*(y+1) + facing;
	cout << ans << endl;
	cout << (x+1) << " " << (y+1) << endl;
}

// 126350 part-2
// 129339 part-1