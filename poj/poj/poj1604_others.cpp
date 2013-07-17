#include <cstdio>
using namespace std;

const int ff [10] = {1, 1, 2, 6, 4, 4, 4, 8, 4, 6};

int f (int n)
{
    if (n < 5) return ff [n];
    int t = ff [n % 10] * 6 % 10;
    for (int i = 1, r = n / 5 % 4; i <= r; i ++)
    {
        if (t == 2 || t == 6) t += 10;
        t /= 2;
    }
    return f (n / 5) * t % 10;
}

int main ()
{
    int n;
    for(n=0; n<=10000; n++){
        printf ("%5d -> %d\n", n, f (n));
    }
    return 0;
}