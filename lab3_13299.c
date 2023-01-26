#include <stdio.h>
int main ()
{
    int n, m, q, i, a, b, t, x;
    scanf("%d %d %d", &n, &m, &q);
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
    int c, d;
    int y[q];
    for (c = 0 ; c <= q - 1 ; c++){
        scanf("%d", &d);
        y[c] = d;                                                    
    }
    int e, f;
    for (e = 0 ; e <= q - 1 ; e++){
        while (y[e] != p[f]){
            f = f + 1;
        }
        if (e < q - 1){
            printf("%d ", f + 1);
        }
        else if (e = q - 1){
            printf("%d\n", f + 1);
        }
        f = 0;
    }
    return 0;
}