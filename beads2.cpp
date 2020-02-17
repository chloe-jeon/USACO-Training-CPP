/*
ID: your_id_here
PROG: beads
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int length;
    string necklace;
    fin >> length >> necklace;
    char backwardsN[length];
    int counter[length];
    for (int i = 0; i < length; i++)
    {
        assert((length - i - 1) < length);
        backwardsN[length - i - 1] = necklace[i];
    }
    for (int i = 0; i < length; i++)
    {
        char x = necklace[i], y = backwardsN[i];
        for (counter[i] = 0; counter[i] < length; counter[i]++)
        {
            if (necklace[i] == 'w' && necklace[counter[i]] != x)
            {
                if (x != 'w')
                    break;
                else
                {
                    x == necklace[counter[i]];
                }
            }
            else if (necklace[i] != 'w' && necklace[counter[i]] != x)
                if (necklace[counter[i]] != 'w')
                    break;
            //wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
        }
        cout << "i = " << i << " counter[i] = " << counter[i] << "   ";
        for (int j = 0; (j < length) && (counter[i] < length); j++)
        {
            if (backwardsN[i] == 'w' && backwardsN[counter[i]] != y)
            {
                if (y != 'w')
                    break;
                else
                {
                    y == backwardsN[counter[i]];
                }
            }
            else if (backwardsN[i] != 'w' && backwardsN[counter[i]] != y)
                if (backwardsN[counter[i]] != 'w')
                    break;
            counter[i]++;
        }
        cout << "i = " << i << " counter[i] = " << counter[i] << endl;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (counter[j] < counter[j + 1])
            {
                int x = counter[j + 1];
                counter[j + 1] = counter[j];
                counter[j] = x;
            }
        }
    }
    fout << counter[0] << endl;
    return 0;
}
