/*************************************************************************
        > File Name: sort.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Tue 18 Jun 2024 04:09:33 PM HKT
      > Describe:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <list>
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

using namespace std;

int *getrandData(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

template <typename T> 
void output(T *begin, T *end) {
    cout << "arr : ";
    for (T *p = begin; p < end; ++p) {
        cout << *p << " ";
    }
    cout << endl;
    return ;
}

namespace my {
template <typename iterator, typename _Compare>
void sort(iterator begin, iterator end, function<bool()> cmp) {

}
}

int main() {
    srand(time(0));
    #define MAX_N 10
    int *arr1 = getrandData(MAX_N);
    output(arr1, arr1 + MAX_N);
    sort(arr1, arr1 + MAX_N);
    output(arr1, arr1 + MAX_N);
    

    return 0;
}
