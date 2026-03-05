#include "../include/cpfuncs.hpp"
#include std::string
#define fore for_each
#define range(x) x.begin(), x.end()

int main(){
  
  vec<int> nums = {10, 20, 40}; // define integer vector with values named nums
  vec<string> words = {"one", "two", "three"}; // define string vector with values named words
  words.addfront("six"); // add "six" to the beginning of the words vector
  nums.add(7); // add 7 to the end of the nums vector
  auto linked = link(nums, words, full); // implicitly define a vector pair ~(vector<pair<optional<T1>, optional<T2>>>)~ that will be as long as the longer of the two vectors and place empty spots with null values 
  opp(linked); // print out linked as ordered pairs in (val_1, val_2) format

  return 0;
}
