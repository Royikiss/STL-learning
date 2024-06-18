/*************************************************************************
        > File Name: sort.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Tue 18 Jun 2024 07:29:28 PM HKT
      > Describe:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <sstream>
#include <functional>

#define TEST_BEGINS(x) namespace x {
#define TEST_ENDS(x) } 

using namespace std;

TEST_BEGINS(my)

template<typename T, typename Func_T>
T __median(T first, T medium, T last, Func_T cmp) {
    if (cmp(medium, first)) std::swap(medium, first);
    if (cmp(last, medium)) std::swap(medium, last);
    return medium;
}

template<typename iterator>
void sort(iterator begin, iterator end) {
    sort(begin, end, std::less<decltype(*(begin))>());
    return ;
}

template<typename iterator, typename _Compare>
void sort(iterator begin, iterator end, 
          _Compare cmp) {
if (end - begin < 2) return;
iterator x = begin, y = end - 1;
typename std::remove_reference<decltype(*begin)>::type z = __median(*x, *(begin + (end - begin) / 2), *y, cmp);
do {
    while (cmp(*x, z)) x++;
    while (cmp(z, *y)) y--;
    if (x <= y) {
        std::swap(*x, *y);
        ++x, --y;
    }
} while (x <= y);
++y;
my::sort(begin, y, cmp);
my::sort(x, end, cmp);
}

TEST_ENDS(my)
