#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&a, vector<int>&b,int d) {
    int n = a.size(); int m = b.size();

    int answer = 0;
    for(int i = 0;i < n;i++) {
        auto it = upper_bound(b.begin(),b.end(),a[i]);
        if(it != b.end()) {
            if(abs(a[i] - *it) <= d) continue;
        }
        if(it != b.begin()) {
            it = prev(it);
            if(abs(a[i] - *it) <= d) continue;
        }
        answer++;
    }
    return answer;
}

int main() {
    vector<int>a = {2,9};
    vector<int>b = {16,13,8};
    int d = 3;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    cout << check(a,b,d) << endl;
}

/*class C{
public:

int get_index(int x,int d){

if(d==0)  return x;

return (x/d);
}

int ComparatorValue(vector < int > & a,vector < int > & b,int d){

if(d<0) return a.size();

int m=a.size();
int n=b.size();
int h,i,x,index;

unordered_map<int,pair<int,int>>mymap;

for(i=0;i<n;i++){
    x=b[i];
    index=get_index(x,d);
    
    if(mymap.count(index)==0){
        mymap[index]={x,x};
    }
    else{
        mymap[index].first=min(mymap[index].first,x);
        mymap[index].second=max(mymap[index].second,x);
    }
}

int ret=0;
for(i=0;i<m;i++){
    x=a[i];
    index=get_index(x,d)-1;
    bool found=false;
    
    for(h=-1;h<=1;h++,index++){
        if(mymap.count(index)==0)continue;
        
        if(abs(mymap[index].first-x)<=d){found=true;break;}
        if(abs(mymap[index].second-x)<=d){found=true;break;}
    }
    if(!found)ret++;
}
return ret;
*/
