#include <stdio.h>

struct matrix
{
    int A[10];
    int n;
};
void sets(struct matrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i - 1] = x;
    }
}
void get(struct matrix m, int i, int j)
{
    if (i == j)
    {
        printf("%d \n",m.A[i - 1]);
    }
    else{
        printf("0 ");
    }
}
void display(struct matrix m){
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i==j){
                printf("%d ",m.A[i-1]);
            }
            else{
                printf("0 ");
            }
        }
    printf("\n");
    }
}
int main()
{
    struct matrix m;
    sets(&m, 1, 1, 1);
    sets(&m, 2, 2, 2);
    sets(&m, 3, 3, 3);
    sets(&m, 4, 4, 4);
    sets(&m, 5, 5, 5);
    sets(&m, 6, 6, 6);
    get(m,3,3);
    get(m,4,5);
    display(m);
    return 0;
}