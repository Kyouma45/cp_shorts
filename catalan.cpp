 int findCatalan(int n)
    {
        const int MOD = 1000000007;
        vector<int> catalan(n + 1, 0);

        catalan[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                catalan[i] = (catalan[i] + (1LL * catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
            }
        }

        return catalan[n];
    }
