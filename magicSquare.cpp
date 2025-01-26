#include <bits/stdc++.h>
using namespace std;
void magic(int n) // creating a magic square of size n, where n is odd
{
    const int MaxSize = 51; // maximum sqr size
    int square[MaxSize][MaxSize];
    if (n > (MaxSize) || (n < 1))
    {
        cerr << "Error!... n is out of range" << endl;
        return;
    }
    else if (!(n % 2))
    {
        cerr << "Error! .. n is even" << endl;
        return;
    }
    // if n is odd coxeter's rule can be used
    for (int i = 0; i < n; i++) // initialize sqr to 0
        for (int j = 0; j < n; j++)
            square[i][j] = 0;
    square[0][(n - 1) / 2] = 1; // middle of first row
    int key = 2;
    int i = 0;
    int j = (n - 1) / 2;
    while (key <= n * n)
    {

        int k = (i - 1 + n) % n; // Move up (wrap around)
        int l = (j - 1 + n) % n; // Move left (wrap around)
        if ((square[k][l]) != 0)
        {
            i = (i + 1) % n; // square occupied , move down
        }
        else
        { // suare k and l is unoccupied
            i = k;
            j = l;

            square[i][j] = key;
            key++;
        }
    }
    cout << "Magic Square of size" << n << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;
    magic(n);
    return 0;
}
