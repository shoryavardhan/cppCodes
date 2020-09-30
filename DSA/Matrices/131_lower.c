#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A;
    int n;
};
void sets(struct matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[(i * (i + 1) / 2) + j - 1] = x;
    }
}
void get(struct matrix m, int i, int j)
{
    if (i >= j)
    {
        printf("%d \n", m.A[(i * (i + 1) / 2) + j - 1]);
    }
    else
    {
        printf("0\n");
    }
}
void display(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", m.A[(i * (i + 1) / 2) + j - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    printf("Enter Dimension ");
    scanf("%d", &m.n);
    int len = ((m.n) * (m.n + 1)) / 2;
    m.A = (int *)malloc(len * sizeof(int));
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                sets(&m, i, j, 1);
        }
    }
    // get(m, 3, 3);
    // get(m, 4, 5);
    display(m);
    return 0;
}
