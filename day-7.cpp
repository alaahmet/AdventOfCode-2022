#include <bits/stdc++.h>
using namespace std;

struct dir{
	map <string,int> files;
	string name;
	vector <dir> next;
	struct dir* prev;
};

vector <int> sizes; // size of directories for part-2
int part1_answer;

int dfs(dir* cur){

	int sum  = 0;
	
	for(int i=0;i<(cur->next).size();i++){
		int ret = dfs(&(cur->next)[i]);
		sum += ret;
	}
	
	for(auto it = cur->files.begin();it!=cur->files.end();it++){
		sum += it->second;
	}
	
	if(sum<=1e5)part1_answer+=sum;
	sizes.push_back(sum);
	return sum;

}
int main() {

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	struct dir* root = new dir;
	root->prev = root;
	part1_answer = 0;
	string s;
	dir *cur = root;
	while(getline(cin,s)){
		if(s[0]=='$'){
			if(s[2]=='c'){
				if(s[5]=='/'){
					cur = root; // go to root
				}
				else if(s[5]=='.'){ // cd ..
					cur = cur->prev;
				}
				else{ // cd dir
					for(int i=0;i<(cur->next).size();i++){
						// searching for the directory
						if((((cur->next)[i]).name)==s.substr(5)){
							cur = &(cur->next[i]);
							break;
						}
					}
				}
			}
			else if(s[2]=='l'){// ls
				; // do nothing
			}
		}
		else if(s[0] != '$'){ // in ls mode
			if(s[0] == 'd'){// dir creation
				bool directory_exists = false;
				for(int i=0;i<(cur->next).size();i++){
					if(((cur->next[i]).name)==s.substr(4)){
						cur = &(cur->next[i]);
						directory_exists = true;
						break;
					}
				}
				// searched for the directory
				// if the directory doesn't exist, create it
				if(directory_exists == false){
					dir *newdir = new dir;
					newdir->name = s.substr(4);
					newdir->prev = cur;
					cur->next.push_back(*newdir);
				}
			}
			else{ // file creation
				int x = s.find(" ");
				int val = stoi(s.substr(0,x));
				string file_name = s.substr(x+1);
				cur->files[file_name] = val;
			}
		}
	}	

	int root_size = dfs(root);
	cout << part1_answer << endl;

	sort(sizes.begin(),sizes.end());
	int needed = 30000000-(70000000-root_size); 
	
	cout << *lower_bound(sizes.begin(),sizes.end(),needed) << endl;
}
 
 