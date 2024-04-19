#include <iostream>
using namespace std;
void Nhap(int **&a, int &m, int &n)
{
    cin >> m >> n;
    a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}
void Xuat(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << '\n';
    }
}
void Min_Arr(int **a, int m, int n)
{
    int MIN = a[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] < MIN)
                MIN = a[i][j];
    cout << "Gia tri nho nhat mang: " << MIN << '\n';
}
void Sum_Row(int **a, int m, int n)
{
    int *c = new int[m];
    for (int i = 0; i < m; i++)
    {
        c[i] = 0;
        for (int j = 0; j < n; j++)
            c[i] += a[i][j];
    }
    cout << "Tong cac phan tu tren moi dong:\n";
    for (int i = 0; i < m; i++)
        cout << "Dong " << i + 1 << ": " << c[i] << '\n';
    delete[] c;
}
void Min_Col(int **a, int m, int n)
{
    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = a[0][i];
        for (int j = 1; j < m; j++)
            if (a[j][i] < d[i])
                d[i] = a[j][i];
    }
    cout << "Gia tri nho nhat tren moi cot:\n";
    for (int i = 0; i < n; i++)
        cout << "Cot " << i + 1 << ": " << d[i] << '\n';
    delete[] d;
}
int main()
{
    int **a, m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    Min_Arr(a, m, n);
    Sum_Row(a, m, n);
    Min_Col(a, m, n);
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}