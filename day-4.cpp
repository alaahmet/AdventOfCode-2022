#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // removed dashes and commas with a text editor

    int mx = 1000; // #of lines in the input
    int part1 = 0;
    int part2 = 0;
    for(int i=0;i<mx;++i){
        
        int a,b,c,d;cin >> a >> b >> c >> d;

        if(a<=c and b>=d)++part1;
        else if(c<=a and b<=d)part1++;

        if(b<c)++part2;
        else if(d<a)++part2;

    }
    
    cout << part1 << endl;
    cout << 1000-part2 << endl;

}