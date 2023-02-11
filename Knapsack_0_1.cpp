class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int W, int wt[], int val[], int n,vector<vector<int>>dp){
        if(W==0 || n==0)
       return 0;
       if(dp[n][W]!=-1)
       return dp[n][W];
       if(wt[n-1]<=W)
        return dp[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       else
        return dp[n][W]=knapSack(W,wt,val,n-1);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return helper(W,wt,val,n,dp);
    }
};







class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
       }
       }
       return dp[n][W];
    }
};