#include <iostream>
#include <string.h>

using namespace std;

// a) Tách chuỗi thành các từ và đếm xem chuỗi có bao nhiêu từ; bao nhiêu từ bắt đầu bằng nguyên âm, phụ âm.
void caua(char *s)
{
    cout << "a)\nTach tu:\n";
    char str[500];
    strcpy(str, s);
    int d = 0;
    int ng_am = 0;
    char *token = strtok(str, " ");
    while (token)
    {
        d++;
        cout << token << '\n';
        if (token[0] == 'a' || token[0] + 32 == 'a' || token[0] == 'e' || token[0] + 32 == 'e' || token[0] == 'i' || token[0] + 32 == 'i' || token[0] == 'o' || token[0] + 32 == 'o' || token[0] == 'u' || token[0] + 32 == 'u')
            ng_am++;
        token = strtok(NULL, " ");
    }
    cout << "Chuoi co " << d << " tu; ";
    if (!ng_am)
        cout << d << " tu deu bat dau bang phu am\n";
    else if (ng_am == d)
        cout << d << " tu deu bat dau bang nguyen am\n";
    else
    {
        cout << ng_am << " tu bat dau bang nguyen am; ";
        cout << d - ng_am << " tu bat dau bang phu am\n";
    }
}
// b) Sắp xếp các từ trong chuỗi theo thứ tự giảm dần (theo thứ tự từ điển).
void caub(char *s)
{
    cout << "b) Sau sap xep: ";
    char *arr[100];
    char str[500];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int count = 0;
    while (token)
    {
        arr[count] = new char[10];
        strcpy(arr[count++], token);
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(arr[i], arr[j]) == -1)
            {
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    for (int i = 0; i < count; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    for (int i = 0; i < count; i++)
        delete[] arr[i];
}
// c) Đếm xem mỗi từ xuất hiện bao nhiêu lần
void cauc(char *s)
{
    cout << "c) ";
    char str[500];
    int check[100] = {};
    char *arr[100];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int n = 0;
    while (token)
    {
        arr[n] = new char[10];
        strcpy(arr[n++], token);
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            int d = 1;
            for (int j = i + 1; j < n; j++)
                if (strcmp(arr[i], arr[j]) == 0)
                {
                    d++;
                    check[j] = 1;
                }
            if (i)
                cout << ", ";
            cout << arr[i] << ": " << d;
        }
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
        delete[] arr[i];
}
// d) Tìm các từ có số lần xuất hiện lớn hơn hoặc bằng k (với k là số nguyên dương nhập từ bàn phím)
void caud(char *s)
{
    int k;
    cout << "d) Nhap k = ";
    cin >> k;
    cout << "Cac tu co so lan xuat hien lon hon bang " << k << " la: ";
    char str[500];
    int check[100] = {};
    char *arr[100];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int n = 0, kt = 1;
    while (token)
    {
        arr[n] = new char[10];
        strcpy(arr[n++], token);
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            int d = 1;
            for (int j = i + 1; j < n; j++)
                if (strcmp(arr[i], arr[j]) == 0)
                {
                    d++;
                    check[j] = 1;
                }
            if (d >= k)
            {
                if (kt)
                    kt = 0;
                else
                    cout << ", ";
                cout << arr[i];
            }
        }
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
        delete[] arr[i];
}
// e) Nhập vào một ký tự. Xóa tất cả các vị trí mà ký tự đó xuất hiện trong chuỗi.  (tác động trên chuỗi sau sắp xếp)
void caue(char *s)
{
    char *arr[100];
    char str[500];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int count = 0;
    while (token)
    {
        arr[count] = new char[10];
        strcpy(arr[count++], token);
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(arr[i], arr[j]) == -1)
            {
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    char ch;
    cout << "e) Nhap ki tu can xoa: ";
    cin >> ch;
    cout << "Chuoi sau khi xoa: ";
    for (int i = 0; i < count - 1; i++)
    {
        char *tmp = strchr(arr[i], ch);
        while (tmp)
        {
            strcpy(tmp, tmp + 1);
            tmp = strchr(arr[i], ch);
        }
        cout << arr[i] << ' ';
    }
    for (int i = 0; i < count; i++)
        delete[] arr[i];
}

int main()
{
    char s[500];
    gets(s);
    caua(s);
    caub(s);
    cauc(s);
    caud(s);
    caue(s);
    return 0;
}