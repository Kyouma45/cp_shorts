//sieve of Eratosthenes
int prime_range(int l,int r)
{
    vector<bool> arr(n+1,1);
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i*i<r;i++)
    {
        if(arr[i])
        {
            for(int t=i+i;t<=r;t+=i)
            {
                arr[t]=0;
            }
        }
    }
    int count=0;
    for(int i=l;i<=r;i++)
    {
        if(arr[i])
            count++;
    }
    return count;
}