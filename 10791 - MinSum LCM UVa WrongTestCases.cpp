#include<bits/stdc++.h>
using namespace std;

bool prime[300005];
long long int p[300005];

int main()
{
    long long int i, j, T, ck, sq, n, pos, got, add;

    n = 100000;


    ///GENERATING PRIMES///
    for(i=2; i<=n; i++)
    {
        pos = i*2;
        prime[pos] = 1;
    }

    for(i=3; i<=n; i+=2)
    {
        for(j=i*i;j<=n;j+=i)
        {
            prime[j] = 1;
        }
    }

    j = 0;
    for(i=2; i<=n; i++)
    {
        if(prime[i]==0)
        {
            p[j] = i;
            j++;
        }
    }
    long long sz = j;


    ///LCM AND MINIMUM SUM///
    long long int sum = 1;
    int no = 1;
    while(cin>>T && T!=0)
    {
        sq = sqrt(T+1);

        n = T;
        add = 0;
        ck = 0;

        for(i=0; i<sz && p[i]<=T; i++)
        {
            got = 0, sum = 1;
            while(1)
            {
                if(T%p[i]==0)
                {
                    T = T/p[i];
                    sum = sum*p[i];
                    got=1;
                }
                else
                    break;
            }
            if(got == 1)
            {
                add = add + sum;
            }
        }

        if(add == 0 || sum == n)
            add = n+1;
///############################################     UVa submission accepted this code without this "else if" portion!
        else if(T != 1)                             ///TEST CASE 2000000014
            add = add+T;
///############################################
        cout<<"Case "<<no<<": "<<add<<endl;
        no++;
    }
    return 0;
}
