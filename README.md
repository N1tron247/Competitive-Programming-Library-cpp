# Competitive-Programming-Library-cpp

Personal library I made to speed up solving competitive programming problems and algorithm development/testing.

## Features 
- 'vec<T>': shorthand wrapper around 'std::vector'
- quick and efficient filtering of vectors
- binary search helper function
- diverse primitive input parsing
- string and vector manipulation utlities
- link vectors into a vector pair or a hashmap with the choice of null values for uneven vector lengths or a shortest length cuttof
- fast and customizable printing
- check data types
- split strings using a delimiter
- analyze element frequency in a vector and extract important values such as an element average
- quick rounding and truncating to custom decimal places

## Examples 
```cpp
#include "../include/cpfuncs.hpp"

int main() {
    vec<int> nums = {1,2,3,4,5,6};

    auto even_numbers = nums.math(evens);
    vp(evens, " ");
}
  
