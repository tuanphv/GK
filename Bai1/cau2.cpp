#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

FILE *fi = fopen("input.txt", "r");
FILE *fo = fopen("output.txt", "w");

void caua(int *&a, int &n)
{
    fscanf(fi, "%d", &n);
    a = new int[n];
    for (int i = 0; i < n; i++)
        fscanf(fi, "%d", a + i);
}
int Is_Prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void caub(int *a, int n)
{
    float ave = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (Is_Prime(a[i]))
        {
            ave += a[i];
            count++;
        }
    ave /= count;
    fprintf(fo, "b) %.1f\n", ave);
}
void cauc(int *a, int n)
{
    fprintf(fo, "c)");
    for (int i = 0; i < n; i++)
        if (!Is_Prime(a[i]))
            fprintf(fo, " %d", a[i]);
    fprintf(fo, "\n");
}
void caud(int *a, int n)
{
    int ans = a[0];
    for (int i = 1; i < n; i++)
        ans = a[i] > ans ? a[i] : ans;
    int i = sqrt(ans);
    if (i * i != ans)
        ans = (i + 1) * (i + 1);
    fprintf(fo, "d) %d", ans);
}
int main()
{
    int *a, n;
    caua(a, n);
    caub(a, n);
    cauc(a, n);
    caud(a, n);
    fclose(fi);
    fclose(fo);
    return 0;
}