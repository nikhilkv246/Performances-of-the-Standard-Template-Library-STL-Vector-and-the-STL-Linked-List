#include <iostream>
#include <iterator>
#include "SortedList.h"
#include "algorithm"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/

void SortedList :: prepend(int value)
{
    list<int>::iterator p;
    p = data.begin();
    p = data.insert(p,value);
}

void SortedList :: append(int value)
{
   data.push_back(value);
}


bool  SortedList :: find(int value) const
{
    list<int>::const_iterator it;
    it = std :: find (data.begin(), data.end(), value);
    if (it != data.end())
    return true;
    else
    return false;
    
    /*for(it = data.begin(); it != data.end();it++)
    {
        if(*it == value)
        return true;
    }
    
    return false;*/
    
}

int SortedList :: get_value(int i) const
{
    
    int s = data.size()/2;
    if(i<s)
    {
        list<int>::const_iterator it; 
        it=data.begin();
        for(int x =0; x<i ;x++)
        it++;
        return *it;
    }
    else if(i>s)
    {
        list<int>::const_reverse_iterator it; 
        it=data.rbegin();
        for(int x = data.size(); x>i+1 ;x--)
        it++;
        return *it;
    }
}


void SortedList :: clear() 
{
    list<int>::iterator it; 
    for (it = data.begin(); it != data.end(); )
    it = data.erase(it);
}

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}
