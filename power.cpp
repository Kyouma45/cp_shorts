int power(int a,int n)
{
    int k=a;
    if(n%2==0)      //for even power
    {
        for(int i=1;i<n/2;i++)
        {
            k*=k;
        }
        k*=k;
    }
    else
    {
        for (int i = 1; i < n / 2; i++)
        {
            k *= k;
        }
        k*=k;
        k*=a;
    }
    return k;
}

//O(logn)