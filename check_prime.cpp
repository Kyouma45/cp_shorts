bool prime(int n)
{
    if(n==1)
        return 0;
    if(n%2==0||n%3==0)
        return 0;
    for(int i=5;i*i<n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
            return 0;
    }
    return 1;
}