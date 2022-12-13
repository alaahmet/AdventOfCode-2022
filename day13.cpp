#include <bits/stdc++.h>
using namespace std;

struct item{
	bool is_item;
	vector <item> inner_items;
	int value;
	friend bool operator <(item left,item right);
};

item from_sstream(stringstream& sstream){
	item obj;
	if(sstream.peek() == '['){ // start creating the item
		obj.is_item = true;
		obj.inner_items = {};
		char ch;
		sstream >> ch; // inputting '['
		bool remove_comma = false;
		// [1,2,[3,4]]
		while(sstream.peek() != ']'){
			if(remove_comma)// omitting the comma only for the first element of the item
				sstream>>ch;
			item inner_item = from_sstream(sstream);
			obj.inner_items.push_back(inner_item);
			remove_comma = true;
		}
		sstream >> ch; // ']' end of the item
	}
	else{
		obj.is_item = false;
		sstream >> obj.value;
	}
	return obj;
}

int right_order(item left,item right){
	if(!left.is_item && !right.is_item){
		if(left.value < right.value)
			return 1;
		else if(left.value > right.value)
			return -1;
		else if(left.value == right.value)
			return 0;
	}
	else if(left.is_item && right.is_item){
		int i = 0;
		int len = min(left.inner_items.size(),right.inner_items.size());
		while(i<len){
			int comp = right_order(left.inner_items[i],right.inner_items[i]);
			if(comp!=0)
				return comp;
			i++;
		}
		// first i elements of right and left are same
		if(left.inner_items.size() < right.inner_items.size())
			return 1;
		else if(left.inner_items.size() > right.inner_items.size())
			return -1;
		else if(left.inner_items.size() == right.inner_items.size())
			return 0;
	}
	else if(!left.is_item && right.is_item){
		item inner_item;
		inner_item.is_item = false;
		inner_item.value = left.value;

		left.is_item = true;
		left.inner_items.push_back(inner_item);
		return right_order(left,right);
	}
	else if(left.is_item && !right.is_item){
		item inner_item;
		inner_item.is_item = false;
		inner_item.value = right.value;
		
		right.is_item = true;
		right.inner_items.push_back(inner_item);
		return right_order(left,right);
	}

	return 0; // never reaches here

}

bool operator<(item left, item right) {
    return right_order(left, right) == 1;
}

int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int index = 1;
	int sum = 0;
	string line1;
	string line2;
	vector <item> v;

	while(cin >> line1 >> line2){
		stringstream left_stream = stringstream(line1);
		item left = from_sstream(left_stream);
		stringstream right_stream = stringstream(line2);
		item right = from_sstream(right_stream);
		if(right_order(left,right) == 1){
			sum+=index;
		}
		v.push_back(left);
		v.push_back(right);
		index++;
	}

	cout << "Part1: "  << sum << endl; // part1

	item x1,x2;
	x1 = {true,{{false,{},2}},-1};
	x2 = {true,{{false,{},6}},-1};
	v.insert(v.end(),{x1,x2});
	
	sort(v.begin(),v.end());

	int ans = 1;
	for(int i = 0; i<v.size();i++){
		if(v[i].is_item == true and v[i].value==-1){
			ans *= (i+1);
		}
	}

	cout << "Part2: " << ans << endl; // part2
}
 

