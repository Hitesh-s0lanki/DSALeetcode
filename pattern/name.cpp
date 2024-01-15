#include <iostream>
#include <string>
using namespace std;

void spaceLine(int n)
{
    for (int i = 0; i < 1; i++)
    {
        cout << "  ";
    }
}
void printK(int i, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        if ((i <= n / 2 && (j + i) % (n - 2) == 0) || j == 0 || (i > n / 2 && (i - j - 1) % (n - 2) == 0))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printS(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || i == n - 1 || i == 5 / 2 || (i < n / 2 && j == 0) || (i >= n / 2 && j == n - 1))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printH(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || j == n - 1 || i == n / 2)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printE(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || i == n - 1 || i == n / 2 || j == 0)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printT(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || j == n / 2)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
    spaceLine(n);
}
void printJ(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || j == n / 2 || (j <= n / 2 && i == n - 1) || (i > n / 2 && j == 0))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
    spaceLine(n);
}
void printI(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || i == n - 1 || j == n / 2)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printA(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if ((i > n / 2 && (j == 0 || j == n - 1)) || i == n / 2 || j == (n / 2 + i) || j == (n / 2 - i))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printL(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || i == n - 1)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printP(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || j == 0 || i == n / 2 || (i < n / 2 && j == n - 1))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printR(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0 || j == 0 || i == n / 2 || (i < n / 2 && j == n - 1) || (i > n / 2 && (i - j - 1) % (n - 2) == 0))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printN(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || j == n - 1 || (j - i) % (n - 1) == 0)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printY(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if ((i > n / 2 && j == n / 2) || (i <= n / 2 && ((j - i) == 0 || (j + i) == n - 1)))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printO(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || j == n - 1 || i == 0 || i == n - 1)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printV(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if ((i <= n / 2 && (j == 0 || j == n - 1)) || (i > n / 2 && (j - (i - (n / 2)) == 0 || j + (i - n / 2) == n - 1)))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printU(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || j == n - 1 || i == n - 1)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printM(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if ((i <= n / 2 && ((j - i) == 0 || (j + i) == n - 1)) || j == 0 || j == n - 1)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printB(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j != n - 1 && (i == 0 || i == n / 2 || i == n - 1) || j == 0 || (j == n - 1 && i != 0 && i != n / 2 && i != n - 1))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printC(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || i == 0 || i == n - 1)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printD(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if ((j != n - 1 && (j == 0 || i == 0 || i == n - 1)) || (j == n - 1 && i != 0 && i != n - 1))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printG(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || i == 0 || i == n - 1 || (i >= n / 2 && ((j >= n / 2 && i == n / 2) || (j == n - 1))))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printF(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || i == 0 || i == n / 2)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}
void printW(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || j == n - 1 || (i >= n / 2 && (j + (i - (n / 2)) == n / 2 || j - (i - (n / 2)) == n / 2)))
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
}

void printLetter(char letter, int i, int n)
{
    switch (letter)
    {
    case 'A':
        printA(i, n);
        break;
    case 'B':
        printB(i, n);
        break;
    case 'C':
        printC(i, n);
        break;
    case 'D':
        printD(i, n);
        break;
    case 'E':
        printE(i, n);
        break;
    case 'F':
        printF(i, n);
        break;
    case 'G':
        printG(i, n);
        break;
    case 'H':
        printH(i, n);
        break;
    case 'I':
        printI(i, n);
        break;
    case 'J':
        printJ(i, n);
        break;
    case 'K':
        printK(i, n);
        break;
    case 'L':
        printL(i, n);
        break;
    case 'M':
        printM(i, n);
        break;
    case 'N':
        printN(i, n);
        break;
    case 'O':
        printO(i, n);
        break;
    case 'P':
        printP(i, n);
        break;
    case 'R':
        printR(i, n);
        break;
    case 'S':
        printS(i, n);
        break;
    case 'T':
        printT(i, n);
        break;
    case 'U':
        printU(i, n);
        break;
    case 'V':
        printV(i, n);
        break;
    case 'W':
        printW(i, n);
        break;
    default:
        spaceLine(n);
    }
    spaceLine(n); // Assuming this adds spacing after each letter
}

int main()
{

    int n = 5;
    string name;
    cout << "Enter the Text : ";
    getline(cin, name);

    cout << name << endl;

    for (int i = 0; i < n; i++)
    {
        for (char j : name)
        {
            if (j >= 'a' && j <= 'z')
            {
                printLetter(j - 32, i, n);
            }
            else if (j >= 'A' || j <= 'Z')
            {
                printLetter(j, i, n);
            }
        }
        cout << endl;
    }
}
