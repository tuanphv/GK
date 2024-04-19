#include <iostream>
using namespace std;
int cau_a(int n)
{
    if (n <= 1)
        return 1;
    int Xn = 0;
    for (int i = 0; i < n; i++)
        Xn += (n - i) * cau_a(i);
    return Xn;
}
int cau_b(int n)
{
    if (n <= 1)
        return 1;
    int *F = new int[n + 1]();
    F[0] = F[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            F[i] += (i - j) * F[j];
    int Xn = F[n];
    delete[] F;
    return Xn;
}
int main()
{
    for (int i = 0; i < 25; i++)
        cout << cau_a(i) << ' ';
    cout << endl;
    for (int i = 0; i < 20; i++)
        cout << cau_b(i) << ' ';
    return 0;
}