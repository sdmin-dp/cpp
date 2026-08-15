#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> dq;
void solve(){
    cin>>n;
    ll sum=0,cnt=0;
    for(ll i=1;sum<n;i*=3){
        sum+=i;
        cnt++;
    }
    cout<<cnt<<el;

    // 将n转换为平衡三进制
    vector<ll> digits;
    ll temp = n;
    while(temp > 0){
        ll k = temp % 3;
        temp /= 3;
        digits.push_back(k);
    }
    
    // 处理进位，将2转换为-1并进位
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] == 2){
            digits[i] = -1;
            if(i + 1 < digits.size()){
                digits[i + 1]++;
            } else {
                digits.push_back(1);
            }
        } else if(digits[i] == 3){
            digits[i] = 0;
            if(i + 1 < digits.size()){
                digits[i + 1]++;
            } else {
                digits.push_back(1);
            }
        }
    }
    
    // 处理可能的连续进位
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] == 2){
            digits[i] = -1;
            if(i + 1 < digits.size()){
                digits[i + 1]++;
            } else {
                digits.push_back(1);
            }
            i--; // 重新检查当前位
        } else if(digits[i] == 3){
            digits[i] = 0;
            if(i + 1 < digits.size()){
                digits[i + 1]++;
            } else {
                digits.push_back(1);
            }
            i--; // 重新检查当前位
        }
    }
    
    // 输出左边砝码（物品放在右边，需要平衡的砝码）
    bool first = true;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] == 1){
            if(!first) cout << " ";
            cout << (ll)pow(3, i);
            first = false;
        }
    }
    if(first) cout << "0"; // 如果没有左边砝码
    cout << el;
    
    // 输出右边砝码（与物品同边的砝码）
    first = true;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] == -1){
            if(!first) cout << " ";
            cout << (ll)pow(3, i);
            first = false;
        }
    }
    if(first) cout << "0"; // 如果没有右边砝码
    cout << el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}