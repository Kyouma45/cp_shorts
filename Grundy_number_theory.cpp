// A Function to calculate Mex of all
    // the values in that set.
    int calculateMex(set<int> Set)
    {
    	int Mex = 0;
    
    	while (Set.find(Mex)!=Set.end())
    		Mex++;
    	return (Mex);
    }

    // A function to Compute Grundy Number
    // of 'n'. Only this function varies
    // according to the game
    int calculateGrundy(int n,vector<int>pick)
    {
        int dp[n+1] = {0};
        for(int i=1;i<=n;i++)
        {
            // A Hash Table
    	    set<int> Set;
        	for(int j = 0; j < pick.size() ; j++){
        	    if(i-pick[j] >= 0)
        	        Set.insert(dp[i-pick[j]]);
        	}
        	dp[i]=calculateMex(Set);
        }
    	return dp[n];
    }
