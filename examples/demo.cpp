#include "../include/cpfuncs.hpp"
#include <utility>
#define std::fore for_each
#define range(x) x.begin(), x.end()

int main(){
    
    vec<int> nums = {12, 53, 63, 63, 4, 8, 84}; //define vector of integers called jums
    vec<int> final(nums.size()); // define new vector with the same length as jums

    std::transform(range(nums), final.begin(), [](int x){return x*2; }); //transform alternative to .math function with predefined "mult" argument

    auto nums_doubled = nums.math(mult, 2); // use of the .math function to return a vector where every element is multiplied by 2(achieves the same thing as transform in a smaller form)
    vp(final, " "); //print final (spaced by one each since " " was the argument entered)
    cout << "\n"; // clear a line

    vp(nums_doubled, " "); //print nums_doubled (spaced by one each since " " was the argument entered)

    string str = "dsjds asds , ds, ds,d,,d"; // create string named str
    auto split_str = split(str, ','); // creates string vector which contains substrings of str split at the commas since ',' was the selected delimiter
    cout << "----------------------------------------------\n";
    vp(split_str); //print split_str (printed on different line since "\n" is the default print spacer)
    
}
