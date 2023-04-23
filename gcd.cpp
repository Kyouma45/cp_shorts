//euclidean algoritnm
int gcd(int a,int b)    //iterative
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
//time:O(a+b)
//space:O(1)

int gcd(int a,int b)    //recurssive
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//time:O(log(a+b))
