string dec_to_bin(ll n){
    string s="";
    for(int i=0;i<=32;i++){
        ll x=n&1;
        if(x==0){
            s+='0';
        }
        else{
            s+='1';
        }
        n=n>>1;
    }
    reverse(s.begin(),s.end());
    return s;
}

ll bin_to_dec(string s){
    reverse(s.begin(),s.end());
    ll x=1;
    ll num=0;
    for(ll i=0;i<s.size();i++){
        ll y=s[i]-'0';
        num+=x*y;
        x*=2;
    }
    return num;
}
