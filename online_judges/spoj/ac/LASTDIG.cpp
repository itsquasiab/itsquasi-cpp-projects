#include <stdio.h>
int main()
{
    int t, a;
    long long b;
    int d[10][4] = {
        {0}, {1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}};
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &a, &b);
        if (b == 0)
        {
            puts("1");
            continue;
        }
        a %= 10;
        if (a < 2 || a == 5 || a == 6)
            printf("%d\n", a);
        else
            printf("%d\n", d[a][(b - 1) % (a == 4 || a == 9 ? 2 : 4)]);
    }
}