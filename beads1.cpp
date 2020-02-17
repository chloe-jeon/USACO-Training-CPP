/*
ID: phamils1
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
    //length = 6;
    length = 29;
    fin >> length >> necklace;
    //necklace = "wwwbbr";
    //necklace = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
    char backwardsN[length];
    int numLeft, numRight, totalBead;
    int maxBeads = 0, maxPos = 0;

    for (int i = 0; i < length; i++)
    {
        assert((length - i - 1) < length);
        backwardsN[length - i - 1] = necklace[i];
    }
    for (int i = 0; i < length; i++)
    {
        int reverse_i = (length - i) % length;
        char x = necklace[i], y = backwardsN[reverse_i];
        for (numRight = 0; numRight < length; numRight++)
        {
            if ((necklace[i] == 'w') && (necklace[(numRight + i) % length] != x) && (necklace[(numRight + i) % length] != 'w'))
            {
                //cout << "i: " << i << " x: " << x << "   ";
                if (x != 'w')
                    break;
                else
                {
                    x = necklace[(numRight + i) % length];
                }
            }
            else if (necklace[i] != 'w' && necklace[(numRight + i) % length] != x)
                if (necklace[(numRight + i) % length] != 'w')
                    break;
            //wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
            //cout << "1 loop done  i: " << i << endl;
        }
        //cout << "i = " << i << " numRight = " << numRight << "   ";

        for (numLeft = 0; numLeft < length; numLeft++)
        {
            if (numLeft + numRight == length)
                break;
            if (backwardsN[reverse_i] == 'w' && backwardsN[(numLeft + reverse_i) % length] != y && backwardsN[(numLeft + reverse_i) % length] != 'w')
            {
                //cout << "reverse_i: " << reverse_i << " y: " << y << "   ";
                if (y != 'w')
                    break;
                else
                {
                    y = backwardsN[(numLeft + reverse_i) % length];
                }
            }
            else if (backwardsN[reverse_i] != 'w' && backwardsN[(numLeft + reverse_i) % length] != y)
            {
                //cout << "else-if  reverse_i: " << reverse_i << " y: " << y << "   ";
                if (backwardsN[(numLeft + reverse_i) % length] != 'w')
                    break;
            }
            //cout << "1 loop done  reverse_i: " << reverse_i << "bN:" << backwardsN[reverse_i] << endl;
        }
        //cout << "i = " << i << " numLeft = " << numLeft << endl;

        totalBead = numLeft + numRight;
        if (totalBead > maxBeads)
        {
            maxBeads = totalBead;
            maxPos = i;
        }
    }
    fout << maxBeads << endl;
    return 0;
}
