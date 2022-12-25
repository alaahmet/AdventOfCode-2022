#include <bits/stdc++.h>
using namespace std;
#define int long long
long long sum;
long long dp[22],dpsum[22];
void dfs(int x,int res,string ans){
    if(x==-1){
        if(res == sum){
            cout << ans << endl;
            exit(0);
        }
        return;
    }
    int val = 2*dpsum[x];
    if(val+res<sum)return;
    if(res-val>sum)return;
    dfs(x-1,res,ans+"0");
    dfs(x-1,res-dp[x],ans+"-");
    dfs(x-1,res-2*dp[x],ans+"=");
    dfs(x-1,res+dp[x],ans+"1");
    dfs(x-1,res+2*dp[x],ans+"2");
}
int32_t main() {
    freopen("input.txt","r",stdin);    
    int lines = 115;
    vector <int> v;
    sum = 0;
    for(int ij=0;ij<lines;ij++){
        string s;cin >> s;
        int res = 0;
        int ik = 1;
        for(int i = s.length()-1;i>=0;i--){
            if(s[i] == '-'){
                res = res - ik;
            }
            else if(s[i] == '='){
                res = res - ik*2;
            }
            else{
                res = res + (s[i]-'0')*ik;
            }
            ik = ik*5;
        }
        sum = sum + res;
    }

    dp[0] = 1 + 0LL;
    dpsum[0] = 1 + 0LL;
    for(int32_t i=1;i<22;i++){
        dp[i] = dp[i-1]*5;
        dpsum[i] = dpsum[i-1] + dp[i];
    }
    dfs(19,0,"");
}