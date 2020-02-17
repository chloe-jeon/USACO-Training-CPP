/*
ID: your_id_here
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int numPeople;
    fin >> numPeople;
    string names[numPeople];
    int accounts[numPeople];
    for (int i = 0; i < numPeople; i++)
    {
        fin >> names[i];
        accounts[i] = 0;
    }
    for (int i = 0; i < numPeople; i++)
    {
        string person;
        int gift, numReceiver;
        fin >> person >> gift >> numReceiver;
        int pos1;
        for (pos1 = 0; pos1 < numPeople; pos1++)
        {
            int j;
            for (j = 0; j < names[pos1].length() && j < person.length(); j++)
            {
                if (names[pos1][j] != person[j])
                {
                    break;
                }
            }
            if (names[pos1].length() == person.length() && j == person.length())
            {
                break;
            }
        }
        if (numReceiver != 0)
        {
            accounts[pos1] = accounts[pos1] - gift + (gift % numReceiver);
        }
        for (int j = 0; j < numReceiver; j++)
        {
            string receiving;
            fin >> receiving;
            int pos2;
            for (pos2 = 0; pos2 < numPeople; pos2++)
            {
                int j;
                for (j = 0; j < names[pos2].length() && j < receiving.length(); j++)
                {
                    if (names[pos2][j] != receiving[j])
                    {
                        break;
                    }
                }
                if (names[pos2].length() == receiving.length() && j == receiving.length())
                {
                    break;
                }
            }
            if (numReceiver != 0)
            {
                accounts[pos2] = accounts[pos2] + (gift / numReceiver);
            }
        }
    }
    for (int i = 0; i < numPeople; i++)
    {
        fout << names[i] << " " << accounts[i] << endl;
    }
    return 0;
    /*int numPeople;
    cin >> numPeople;
    string names[numPeople];
    int accounts[numPeople];
    for (int i = 0; i < numPeople; i++)
    {
        cin >> names[i];
        accounts[i] = 0;
    }
    for (int i = 0; i < numPeople; i++)
    {
        string person;
        int gift, numReceiver;
        cin >> person >> gift >> numReceiver;
        int pos1;
        for (pos1 = 0; pos1 < numPeople; pos1++)
        {
            int j;
            for (j = 0; j < names[pos1].length() && j < person.length(); j++)
            {
                if (names[pos1][j] != person[j])
                {
                    break;
                }
            }
            if (names[pos1].length() == person.length() && j == person.length())
            {
                break;
            }
        }
        if (numReceiver != 0)
        {
            accounts[pos1] = accounts[pos1] - gift + (gift % numReceiver);
        }
        for (int j = 0; j < numReceiver; j++)
        {
            string receiving;
            cin >> receiving;
            int pos2;
            for (pos2 = 0; pos2 < numPeople; pos2++)
            {
                int j;
                for (j = 0; j < names[pos2].length() && j < receiving.length(); j++)
                {
                    if (names[pos2][j] != receiving[j])
                    {
                        break;
                    }
                }
                if (names[pos2].length() == receiving.length() && j == receiving.length())
                {
                    break;
                }
            }
            if (numReceiver != 0)
            {
                accounts[pos2] = accounts[pos2] + (gift / numReceiver);
            }
        }
    }
    for (int i = 0; i < numPeople; i++)
    {
        cout << names[i] << " " << accounts[i] << endl;
    }
    return 0;*/
}
