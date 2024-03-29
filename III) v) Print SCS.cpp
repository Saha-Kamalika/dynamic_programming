#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
void LCS(string a,string b){
    memset(t,-1,sizeof(t));
    int m=a.length();
    int n=b.length();
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
}
string printSCS(string a,string b){
    LCS(a,b);
    int i=a.length();
    int j=b.length();
    string s="";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            }
            else{
                s.push_back(a[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        s.push_back(a[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(b[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string a="geek";
    string b="eke";
    string ans=printSCS(a,b);
    cout<<ans<<endl;
}
