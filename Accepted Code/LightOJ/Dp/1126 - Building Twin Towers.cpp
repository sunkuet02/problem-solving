/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ freopen("input.txt","r",stdin);
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mxx 100005
#define sz 10005
#define mod 1000000007
#define MAX 1000005
#define inf INT_MAX
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p)
{
    T f = 1 ;
    for(int i=1 ; i<=p ; i++) f*=base;
    return f;
}
template <typename T>  string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int setbit(int N,int pos)
{
    return N = N|(1<<pos);
}
int resetbit(int N, int pos)
{
    return N = N & ~(1<<pos) ;
}
bool checkbit(int N,int pos)
{
    return (bool) (N & (1<<pos ) ) ;
}
int noofsetbits(int N)
{
    return __builtin_popcount (N);
}
/*********************nCr**************************/
/*
int ncr[1005][1005];
int NCR()
{
    rep0(i,1003)
    {
        ncr[i][0] = 1;
    }
    rep1(i,1003)
    {
        rep1(j,1003)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %=mod;
        }
    }
}
*/

/****************************ExtendedEuclid&ModularInverse****/

pii extendedEuclid(LL a,LL b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
LL modularInverse(LL a,LL m)
{
    pii ret = extendedEuclid(a,m);
    return ( (ret.first % m) + m ) %m ;
}
/*********************temp_Definition *************************/
/*
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


  // Knight Moves
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};
*/

/****************************Implementation************************/

int height[55];
int dp[3][500005];
int n,sum;

int cal(int pos, int diff)
{
    if(pos == 0)
    {
        if(diff ==0)
        {
            return 0;
        }
        else
        {
            return -inf;
        }
    }

    int & ret = dp[pos][diff];
    if(ret !=-1) return ret;

    ret = max(cal(pos -1, diff + height[pos]) + height[pos] , cal(pos -1, abs(diff - height[pos]))+ height[pos]);

    ret = max(ret , cal(pos -1,diff));

    return ret;
}
int cal2()
{

    dp[0][0] = 0;
    int bound = 0;
    for(int pos = 1; pos<= n; pos++ )
    {

        for(int diff = 0 ; diff <= bound; diff ++ )
        {
            if( dp[ (pos + 1)%2 ][diff] >= 0 )
            {
                dp[pos%2][diff] = max(dp[pos%2][diff], dp[(pos+1)%2][diff] );


                if(abs(diff - height[pos])<=sum)
                {
                    dp[pos%2][ abs(diff - height[pos]) ] = max( dp[(pos+1)%2][diff] + height[pos] , dp[pos%2][ abs(diff - height[pos]) ] );
                }
                if(diff + height[pos] <= sum)
                {
                    dp[pos%2][diff + height[pos]] = max( dp[(pos+1)%2][diff] + height[pos],dp[pos%2][diff + height[pos]] );
                }
            }
        }

        bound += height[pos];
        bound = min(sum, bound);
    }


    return max(dp[0][0],dp[1][0]);
}
int main()
{
    int test;
    sc(test);
    rep(t,1,test)
    {
        mem(dp, -1);

        sc(n);
        sum = 0 ;
        rep(i,1,n)
        {
            sc(height[i]);
            sum += height[i];
        }
        sum >>=1;

        printf("Case %d: ",t);

        int ret = cal2();
        if(ret <= 0)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",ret/2);
        }
    }
}

