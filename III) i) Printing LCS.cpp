#include<bits/stdc++.h>
using namespace std;

void LCS(string x, string y, int m, int n, int t[][100]){
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
}

string printLCS(string x, string y){
    int m = x.length();
    int n = y.length();
    int t[100][100]; // Assuming a maximum size for the array
    LCS(x, y, m, n, t);
    int i = m;
    int j = n;
    string s = "";
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";
    string ans = printLCS(x, y);
    cout << ans << endl;
}
