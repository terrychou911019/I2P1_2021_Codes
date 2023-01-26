#include <stdio.h>
int main ()
{
    int n, m, i, a, b, t, x;
    scanf("%d %d", &n, &m);
    int p[n];
    x = 0;
    while ( x <= n - 1 )
    {
        p[x] = x + 1;
        x = x + 1;
    }
    i = 1;
    while ( i <= m )
    {
        scanf("%d %d", &a, &b);
        t = p[a-1];
        p[a-1] = p[b-1]; 
        p[b-1] = t;
        i = i + 1;
    }
    int q = 1;
    int r;
    while ( q <= n )
    {   
        r = 0;
        while ( q != p[r] )
        {
            r = r + 1;
        }
        if ( q < n )
        {
            printf("%d ", r + 1 );
        }
        else
        {
            printf("%d\n", r + 1 );
        }
        q = q + 1;
    }
    return 0;
}