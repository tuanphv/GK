#include <iostream>
#include <fstream>
#include <string.h>
FILE *fi = fopen("input.txt", "r");
FILE *fo = fopen("output.txt", "w");
using namespace std;
void Nhap(char **&s, int &n)
{
    s = new char *[50];
    char str[256];
    while (fgets(str, 256, fi))
    {
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = '\0';
        s[n] = new char[256];
        strcpy(s[n], str);
        n++;
    }
}
int so_tu(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int d = 0;
    while (token)
    {
        d++;
        token = strtok(NULL, " ");
    }
    return d;
}
void caub(char **s, int n)
{
    fprintf(fo, "b) ");
    for (int i = 0; i < n; i++)
    {
        if (i)
            fprintf(fo, ", ");
        fprintf(fo, "%d", so_tu(s[i]));
    }
    fprintf(fo, "\n");
}
void cauc(char **s, int n)
{
    char str[10];
    cin >> str;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        char *tmp = strstr(s[i], str);
        while (tmp)
        {
            d++;
            tmp = strstr(tmp + 1, str);
        }
    }
    fprintf(fo, "c) %d\n", d);
}
char *tu_dai_nhat(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    char *tmp = token;
    int d = strlen(token);
    while (token)
    {
        if (d < strlen(token))
        {
            d = strlen(token);
            tmp = token;
        }
        token = strtok(NULL, " ");
    }
    return tmp;
}
void caud(char **s, int n)
{
    fprintf(fo, "d) ");
    for (int i = 0; i < n; i++)
    {
        if (i)
            fprintf(fo, ", ");
        fprintf(fo, "%s", tu_dai_nhat(s[i]));
    }
    fprintf(fo, "\n");
}
void caue(char **s, int n)
{
    fprintf(fo, "e) ");
    char *tmp = s[1];
    for (int i = 0; i < n; i++)
        if (so_tu(tmp) < so_tu(s[i]))
            tmp = s[i];
    fprintf(fo, "%s", tmp);
}
int main()
{
    char **s;
    int n;
    Nhap(s, n);
    caub(s, n);
    cauc(s, n);
    caud(s, n);
    caue(s, n);
    for (int i = 0; i < n; i++)
        delete[] s[i];
    delete[] s;
    return 0;
}