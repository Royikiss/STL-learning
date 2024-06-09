/*************************************************************************
        > File Name: vector.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Sat 08 Jun 2024 09:55:34 PM HKT
      > Describe:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <list>
#include <system_error>
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

namespace my {

template <typename T>
class vector {
typedef T * iterator; 
public :
    vector(size_t size = 2) : __size(size) {
        data = (T *)malloc(sizeof(T) * __size);
        _Finish = data + __size;
        _M_pos = data;
    }
    vector(const vector )




private :
    size_t __size;
    T *data;
    T *_M_pos, *_Finish;
};
}

int main() {
    #define MAX_N 10
    srand(time(0));

    my::vector<int> v1;

    for (int i = 1; i <= MAX_N; ++i) {
        v1.push_back(rand() % 100);
    }
    
    for (auto x : v1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    

    return 0;
}
