class Solution {
public:
int N,M,K;

int mod = (int)(1e9+7);
    int solve(int idx, int maxi , int cost , vector<vector<vector<int>>> &dp)
    {
        if(idx == N)
        {
            if(cost == K)
                return 1;
            return 0;
        }
        if(dp[idx][maxi+1][cost] != -1)
            return dp[idx][maxi+1][cost];

        int result = 0;
        for(int i =  1; i<= M ;i++)
        {
            if(i>maxi)
            {
            result += solve(idx+1, i , cost+1,dp);
            result %= mod;
            }
            else
            {
            result += solve(idx+1 , maxi , cost,dp);
            result %= mod;
            }
        }
        
        return dp[idx][maxi+1][cost] = result;

    }
    int numOfArrays(int n, int m, int k) 
    {
        N=n;
        M= m;
        K=k;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+2, vector<int>(n+1, -1)));
        
       return solve(0,-1,0,dp);
    }
};
