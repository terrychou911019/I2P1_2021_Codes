#include <stdio.h>
#include <string.h>
int main()
{
    int b, k = 0, n = 0;
    char A[5], B[15];
    scanf("%s", A);
    scanf("%d", &b);
    for (int i1 = 1; i1 <= b; i1++)
    {
        k = 0;
        scanf("%s", B);
        switch (strlen(A))
        {
        case 1:
            for (int i2 = 0; i2 < strlen(B); i2++)
            {
                if (A[0] == B[i2])
                    k = k + 1;
            }
            break;
        case 2:
            for (int i2 = 0; i2 <strlen(B)-1; i2++)
            {
                if (A[0] == B[i2] && A[1] == B[i2 + 1])
                    k = k + 1;
            }
            break;
        case 3:
            for (int i2 = 0; i2 <strlen(B)-2; i2++)
            {
                if (A[0] == B[i2] && A[1] == B[i2 + 1] && A[2] == B[i2 + 2])
                    k = k + 1;
            }
            break;
        case 4:
            for (int i2 = 0; i2 <strlen(B)-3; i2++)
            {
                if (A[0] == B[i2] && A[1] == B[i2 + 1] && A[2] == B[i2 + 2] && A[3] == B[i2 + 3])
                    k = k + 1;
            }
            break;
        }
        if (k > n)
            n = k;
    }
    printf("%d", n);
    return 0;
}