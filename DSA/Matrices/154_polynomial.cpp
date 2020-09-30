//its simpler with ll

#include <bits/stdc++.h>
using namespace std;

struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int n;
    struct term *t;
};
void create(struct poly *p, int n)
{
    p->n = n;
    p->t = new term[n];
    cout << "Enter the coeff and exponents of terms respectively " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For " << i + 1 << " th term ";
        cin >> p->t[i].coeff >> p->t[i].exp;
    }
}
int evaluate(struct poly p, int x)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
    {
        sum += p.t[i].coeff * pow(x, p.t[i].exp);
    }
    return sum;
}
struct poly *addition(struct poly *p1, struct poly *p2)
{
    int i, j, k;
    struct poly *p3;
    p3 = new poly;
    p3->t = new term[p1->n + p2->n];
    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
        {
            cout << "p1 ";
            p3->t[k++] = p1->t[i++];
        }
        else if (p2->t[j].exp > p1->t[i].exp)
        {
            cout << "p2 ";
            p3->t[k++] = p2->t[j++];
        }
        else
        {
            cout << "p3 ";
            p3->t[k].exp = p1->t[i].exp;
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        p3->t[k++] = p3->t[i];
    for (; j < p2->n; j++)
        p3->t[k++] = p3->t[j];

    p3->n = k;
    return p3;
}
void display(struct poly p)
{
    cout << " [ ";
    cout << p.t[0].coeff << "x^" << p.t[0].exp;
    for (int i = 1; i < p.n; i++)
    {
        if (p.t[i].exp > 1)
            cout << " + " << p.t[i].coeff << "x^" << p.t[i].exp;
        else if (p.t[i].exp == 1)
            cout << " + " << p.t[i].coeff << "x";
        else if (p.t[i].exp == 0)
            cout << " + " << p.t[i].coeff;
    }
    cout << " ] ";
}
int main()
{
    int n, m;
    int x = 1;
    cout << "Enter the num of non-zero terms for first polynomial ";
    cin >> n;
    struct poly p1;
    create(&p1, n);
    cout << "First polynomial is ";
    display(p1);
    cout << endl;
    cout << "For x = " << x << ". The value of first polynomial is " << evaluate(p1, x) << endl;
    cout << endl;

    cout << "Enter the num of non-zero terms for second polynomial ";
    cin >> m;
    struct poly p2;
    create(&p2, m);
    cout << "Second polynomial is ";
    display(p2);
    cout << endl;
    cout << "For x = " << x << ". The value of second polynomial is " << evaluate(p2, x) << endl;
    cout << endl;

    struct poly *sum;
    sum = addition(&p1, &p2);
    cout << "Sum of Polynomials ";
    display(p1);
    cout << " & ";
    display(p2);
    cout << " is = ";
    display(*sum);
    cout << endl;
    return 0;
}