/*
ID: your_id_here
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

#define MAX_FARMERS 5000

int StartEnd[2 * MAX_FARMERS];

int main()
{
    int farmers;
    farmers = 3;
    //cin >> farmers;
    //int starter[farmers], ender[farmers], firstStart = 10000000, lastEnd = 0;
    int starter[farmers] = {300, 700, 1500};
    int ender[farmers] = {1000, 1200, 2100};
    int firstStart = 10000000, lastEnd = 0;

    for (int i = 0; i < farmers; i++)
    {
        //cin >> starter[i] >> ender[i];
        if (firstStart > starter[i])
            firstStart = starter[i];
        if (lastEnd < ender[i])
            lastEnd = ender[i];
    }
    int milk[lastEnd];
    for (int i = 0; i < lastEnd; i++)
        milk[i] = 0;
    for (int i = 0; i < farmers; i++)
    {
        for (int j = 0; j <= lastEnd; j++)
        {
            if (j >= starter[i] && j <= ender[i])
                milk[j] = 1;
        }
    }
    int state = 0, prevState = 0, counter = 0;
    for (int time = firstStart; time <= lastEnd; time++)
    {
        for (int i = 0; i < farmers; i++)
        {
            if (time == starter[i])
                state++;
            if (time == ender[i])
                state--;
        }
        if (prevState != state)
        {
            StartEnd[counter] = time - firstStart;
            counter++;
        }
        prevState = state;
    }
    int maxWorking = 0, maxIdle = 0;
    for (int i = 0; i < MAX_FARMERS; i++)
    {
        int working = 0, idle = 0;
        if (i % 2 == 0)
        {
            working = StartEnd[i + 1] - StartEnd[i];
        }
        else
        {
            idle = StartEnd[i + 1] - StartEnd[i];
        }
        if (maxWorking < working)
            maxWorking = working;
        else if (maxIdle < idle)
            maxIdle = idle;
    }
    cout << maxWorking << " " << maxIdle << endl;
}
