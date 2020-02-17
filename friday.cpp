/*
ID: your_id_here
PROG: friday
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

//January 1, 1900 is a Monday.
//all years have 365 days except for leap years.
//century years must be divisible by 400 to be a leap year, not 4.
//0-Sunday, 1-Monday, 2-Tuesday, 3-Wednesday, 4-Thursday, 5-Friday, 6-Saturday

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int year, numYears, dayOfWeek = 1;
    fin >> numYears;
    year = 1900;
    int dayCount[7], daysInMonth[12];
    for (int i = 0; i < 7; i++)
    {
        dayCount[i] = 0;
    }
    daysInMonth[0] = 31; daysInMonth[2] = 31; daysInMonth[3] = 30; daysInMonth[4] = 31; daysInMonth[5] = 30; daysInMonth[6] = 31;
    daysInMonth[7] = 31; daysInMonth[8] = 30; daysInMonth[9] = 31; daysInMonth[10] = 30; daysInMonth[11] = 31;
    for (int i = 0; i < numYears; i++)
    {
        daysInMonth[1] = 28;
        if ((year + i) % 400 == 0)
        {
            daysInMonth[1] = 29;
        }
        else if ((year + i) % 100 != 0 && (year + i) % 4 == 0)
        {
            daysInMonth[1] = 29;
        }
        for (int j = 0; j < 12; j++)
        {
            for (int date = 1; date <= daysInMonth[j]; date++)
            {
                int day = dayOfWeek % 7;
                if (date == 13)
                {
                    dayCount[day]++;//1 1 1  13 13 6 31 31 3
                }
                dayOfWeek++;
            }
        }
    }
    fout << dayCount[6] << " " << dayCount[0] << " " << dayCount[1] << " " << dayCount[2] << " ";
    fout << dayCount[3] << " " << dayCount[4] << " " << dayCount[5] << endl;
    /*for (int i = 0; i < 7; i++)
    {
        cout << dayCount[i] << " ";
    }*/
}
