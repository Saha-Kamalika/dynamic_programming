class Solution{
public:
    unordered_map<string,int> mp;
    int solve(string S,int i,int j,bool isTrue){
        if(i>j) return false;
        if(i==j){
            if(isTrue==true) return S[i]=='T';
            else return S[i]=='F';
        }
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        if(mp.find(temp)!=mp.end()) return mp[temp];
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lT=solve(S,i,k-1,true);
            int lF=solve(S,i,k-1,false);
            int rT=solve(S,k+1,j,true);
            int rF=solve(S,k+1,j,false);
            if(S[k]=='&'){
                if(isTrue==true) ans=ans+lT*rT;
                else ans=ans+(lF*rT)+(lT*rF)+(lF*rF);
            }
            else if(S[k]=='|'){
                if(isTrue==true) ans=ans+(lT*rT)+(lF*rT)+(lT*rF);
                else ans=ans+(lF*rF);
            }
            else if(S[k]=='^'){
                if(isTrue==true) ans=ans+(lT*rF)+(lF*rT);
                else ans=ans+(lF*rF)+(lT*rT);
            }
        }
        mp[temp]=ans%1003;
        return mp[temp];
    }
    int countWays(int N, string S){
        mp.clear();
        return solve(S,0,N-1,true);
    }
};
