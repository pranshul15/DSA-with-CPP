#include <iostream>
using namespace std;

bool safe(int **array, int i, int j, int n)
{
    if (i < n && j < n && array[i][j] == 1)
    {
        return true;
    }
    return false;
}

void path(int **array, int i, int j, int n, int **solarr)
{
    solarr[i][j] = 1;
    if ((i == (n - 1)) and (j == (n - 1)))
    {
        return;
    }
    if (safe(array, i + 1, j, n))
    {
        path(array, i + 1, j, n, solarr);
    }
    if (safe(array, i, j + 1, n))
    {
        path(array, i, j + 1, n, solarr);
    }
    if ((safe(array, i + 1, j, n) == false) && (safe(array, i, j + 1, n == false)))
    {
        solarr[i][j] = 0;
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
    }

    int **solarr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solarr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solarr[i][j] = 0;
        }
    }
    path(array, 0, 0, n, solarr);

    return 0;
}