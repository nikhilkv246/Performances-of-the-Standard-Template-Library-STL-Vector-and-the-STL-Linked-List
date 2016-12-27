#include <iostream>
#include <iterator>
#include "SortedVector.h"
#include "algorithm"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/

void SortedVector :: prepend(int value)
{
    vector<int>::iterator p;
    p = data.begin();
    p = data.insert(p,value);
}

void SortedVector :: append(int value)
{
   data.push_back(value);
}

bool  SortedVector :: find(int value) const
{
    vector<int>::const_iterator it;
    it = std::find (data.begin(), data.end(), value);
    if (it != data.end())
    return true;
    else
    return false;
    
    
}

int SortedVector :: get_value(int i) const
{
    return data[i];
}

void SortedVector :: clear() 
{
    vector<int>::iterator it; 
    for (it = data.begin(); it != data.end(); )
    it = data.erase(it);
}

bool SortedVector::check()
{
    if (data.size() == 0) return true;

    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}
