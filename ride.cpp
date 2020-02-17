/*
ID: your_id_here
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    char A = 'A';
    int cometnum = 1, groupnum = 1;
    fin >> comet >> group;
    for (int i = 0; i < comet.length(); i++)
    {
        //cout << comet[i] - A + 1 << endl;
        cometnum = cometnum * (comet[i] - A + 1);
    }
    for (int i = 0; i < group.length(); i++)
    {
        groupnum = groupnum * (group[i] - A + 1);
    }
    if (cometnum % 47 == groupnum % 47)
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }
    return 0;
}
