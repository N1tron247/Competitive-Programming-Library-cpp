#include "cpfuncs.hpp"
#include <utility>
#define fore for_each
#define range(x) x.begin(), x.end()

int main(){
    /*vec<int> nums = {10, 20, 40};
    vec<string> words = {"one", "two", "three"};
    words.front("six");
    nums.add(7);
    auto linked = link(nums, words, full);
    //opp(linked);

    words.add("six-seven");

    auto mapped = mapp(nums, words);
    //cout << mapped[5] << endl;
    double got = nums.math(total);
    //cout << "nums sum: " << got << endl;
    //auto splot = split("f-f-f-fs-s-g-hsa-fd-s", '-');

    vec<int> jums = {12, 53, 63, 63, 4, 8, 84};

    //cout << jums.math(avg) << endl;

    //vp(jums, "\n"); 
    auto jgf = jums.math(evens);
    //cout << jgf[0] << endl;
    vp(jgf, "\n");
    cout << endl;
    auto jum = jums.math(div, 3.0, Round, 3);
    vp(jum, " ");
    cout << endl;
    auto humd = jums.filter(keep, 8, 63, 12);

    auto fun = [](int a) -> bool {
        return a == 8 || a == 63 || a == 12;
    };


    jums.erase(remove_if(all(jums),fun),jums.end());

    vp(humd, " ");

    string word = "23, 5, fdf, 353";

    auto g = split(word, ',');
    vp(g, " ");*/
    vec<int> jums = {12, 53, 63, 63, 4, 8, 84};
    vec<int> final(jums.size());

    transform(range(jums), final.begin(), [](int x){return x*2; });

    //vp(final);

    string str = "dsjds asds , ds, ds,d,,d";
    auto splat = split(str, ',');
    vp(splat);
    


 

}
