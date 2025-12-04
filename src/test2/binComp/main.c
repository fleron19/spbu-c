#include <stdbool.h>
#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
//1 - first is greater, 2 - second is greater, 0 - equals
int cmp(bool *fi, bool *se)
{
    int s1 = sizeof(fi)/sizeof(bool);
    int s2 = sizeof(se)/sizeof(bool);
    int res = 0;
    for (int i = 0; i < min(s1, s2); i ++){
        if (fi[i] > se[i]){
            res = 1;
        }
        else if (fi[i] < se[i]){
            res = 2;
        }
    }
    if (s1 > s2){
        for (int i = min(s1, s2); i < s1; i ++){
            if (fi[i] == true){
                res = 1;
            }
        }
    }
    if (s2 > s1){
        for (int i = min(s1, s2); i < s2; i ++){
            if (se[i] == true){
                res = 2;
            }
        }
    }
    return res;
}

int main(void)
{
    //stroing bits in reversed order
    bool f[4] = {1, 0, 0, 0};
    bool s[4] = {1, 1, 0, 0};
    if (cmp(f, s) == 1){
        printf("first is greater\n");
    }
    else if (cmp(f, s) == 2){ 
        printf("second is greater\n");   
    }
    else{
        printf("first equals second");
    }

    bool f1[4] = {1, 1, 0, 0};
    bool s1[4] = {1, 1, 1, 0};
    if (cmp(f1, s1) == 1){
        printf("first is greater\n");
    }
    else if (cmp(f1, s1) == 2){ 
        printf("second is greater\n");   
    }
    else{
        printf("first equals second");
    }
}
