class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string a,string b){
        if (a==b) return true;
        if (a.length()!=b.length()) return false;
        if (a.length()==1) return false;

        string key=a+' '+b;
        if (mp.find(key)!=mp.end()) return mp[key];

        int n=a.length();
        bool flag=false;
        for(int i=1;i<n;i++) {
            if ((solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i))) ||
                (solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i, n-i), b.substr(0,n-i)))) {
                flag=true;
                break;
            }
        }
        return mp[key]=flag; 
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1.length()==0 && s2.length()==0) return true;
        return solve(s1,s2);
    }
};
