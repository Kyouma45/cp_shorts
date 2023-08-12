unsigned long long factorial(int n)
{
    if(n == 0)
          return 1;
    int i = n;
    unsigned long long fact = 1;
    while (i--) {
        fact = fact * i;
    }
    return fact;
}
#will work for n<=19
