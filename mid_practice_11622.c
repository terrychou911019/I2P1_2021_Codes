#include <stdio.h>
int main (){
    int T, m1 = 0, m2 = 0;
    char suit[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
    int num[13] = {0};
    
    char a[5][3];
    scanf("%d", &T);
    for (int i = 0 ; i < T ; i++){
        scanf("%s %s %s %s %s", a[0], a[1], a[2], a[3], a[4]);
        for (int i1 = 0 ; i1 < 5 ; i1++){
            for (int i2 = 0 ; i2 < 13 ; i2++){
               if (a[i1][0] == suit[i2]){
                   num[i2]++;
               } 
               
            }
        }
        for (int j = 0 ; j < 13 ; j++){
            if (num[j] == 3) m1 = 1;
        }
        for (int j1 = 0 ; j1 < 13 ; j1++){
            if (num[j1] == 2) m2 = 1;
        }
        if (m1 == 1 && m2 == 1) printf("YES\n");
        else printf("NO\n");
        m1 = 0;
        m2 = 0;
        for (int i3 = 0 ; i3 < 13 ; i3++){
            num[i3] = 0;
        }
    }
    return 0;
}