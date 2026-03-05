#ifndef CPFUNCS_HPP
#define CPFUNCS_HPP

//#include <bits/stdc++.h>
#include <iostream>
#include <optional>
#include <algorithm>
#include <string>
#include <vector>   
#include <type_traits>
#include <map>
#include <sstream>
#include <utility>
#include <numeric>
#include <cmath>
#include <variant>
#include <cctype>
#include <cerrno>
#include <cstdlib>

using std::vector;
using std::string;
using std::map;
using std::pair;
using std::optional;
using std::stringstream;
using std::variant;
using std::cout;
using std::cin;
using std::endl;

#define cut "cut"
#define full "full"
#define total "sum"
#define avg "avg"
#define evens 'E'
#define odds 'O'
#define mod 'M'
#define div 'D'
#define mult 'mode'
#define ditch 'd'
#define keep 'k'
#define Trunc "trunc"
#define Round "round"
#define all(x) x.begin(), x.end()
using ll = long long;
using gen = std::variant<bool, long long, double, string, char>;
//using line = true;


template <typename T>
class vec : public vector<T>{
    public:
        using vector<T>::vector;
        void add(const T& val){
            this->push_back(val);
        }

        void addfront(const T& val){
            this->insert(this->begin(), val);
        }
        
        double math(string ret){
            if(ret == avg){
                double sum = accumulate(this->begin(), this->end(), 0.0);
                return sum / this->size();
            }
            else if(ret == total){
                double sum = accumulate(this->begin(), this->end(), 0.0);
                return sum;
            }
            return 0.0;
        }
        vector<T> math(char op){
            vector<T> vals;

            int mark;
            if(op == 'E') mark = 0;
            else if(op == 'O') mark = 1;

            for(int i=0; i<this->size(); i++){
                if((*this)[i]%2 == mark){
                    vals.push_back((*this)[i]);
                }
            }

            return vals;
        }
        vector<double> math(char mode, double num){
            vector<double> vals;
            if(mode == 'M'){
                for(int u=0; u<this->size(); u++){
                    if(fmod(static_cast<double>((*this)[u]), static_cast<double>(num)) == 0.0){
                        vals.push_back((*this)[u]);
                    }
                }
            }
            else if(mode == 'm'){
                for(int h=0; h<this->size(); h++){
                    vals.push_back((*this)[h]*num);
                }
            }
            else if(mode == 'D'){
                for(int h=0; h<this->size(); h++){
                    vals.push_back(static_cast<double>((*this)[h])/num);
                }
            }
            return vals;
        }
        vector<double> math(char mode, double num, const string& rund, int places){
            vector<double> vals;
            if(mode == 'D'){
                for(int h=0; h<this->size(); h++){
                    double vv = static_cast<double>((*this)[h])/num;

                    if(rund == "round"){
                        vals.push_back(round(vv * pow(10, places))/pow(10, places));
                    }
                    else if(rund == "trunc"){
                        vals.push_back(trunc(vv * pow(10.0, places)) / pow(10.0, places));
                    }

                }
            }
            return vals;
        }
        template <typename... Args>
        vector<T> filter(char rok, Args... rid){
            vector<T> vals;

            if(rok == 'd'){
                for(int y=0; y<this->size(); y++){
                    if((((*this)[y] == rid) || ...)){
                        continue;
                    }
                    vals.push_back((*this)[y]);
                }
            }
            else if(rok == 'k'){
                for(int j=0; j<this->size(); j++){
                    if((((*this)[j] == rid) || ...)){
                        vals.push_back((*this)[j]);
                    }
                }
            }
            return vals;
        }
        
    
        int bs(T target){
            int mini = 0, maxi = this->size()-1;

            while (mini <= maxi){
                int midi = mini + ((maxi - mini) / 2);

                if((*this)[midi] == target){
                    return midi;
                }
                else if((*this)[midi] < target){
                    mini = midi + 1;
                }
                else{
                    maxi = midi - 1;
                }
            }
            return -1;
        }

        
};


void in(gen& out, bool whole_line = false, const std::string& prompt = "") {
    if (!prompt.empty())
        std::cout << prompt;

    string line;

    
    if (whole_line) {
        std::getline(std::cin, line);
    } else {
        std::cin >> line;
    }

   
    size_t i = 0, j = line.size();
    while (i < j && std::isspace((unsigned char)line[i])) ++i;
    while (j > i && std::isspace((unsigned char)line[j - 1])) --j;
    line = line.substr(i, j - i);

    
    auto iequals = [](const std::string& a, const std::string& b) {
        if (a.size() != b.size()) return false;
        for (size_t k = 0; k < a.size(); ++k)
            if (std::tolower((unsigned char)a[k]) !=
                std::tolower((unsigned char)b[k]))
                return false;
        return true;
    };

    if (iequals(line, "true"))  { out = true;  return; }
    if (iequals(line, "false")) { out = false; return; }

 
    {
        errno = 0;
        char* end = nullptr;
        long long v = std::strtoll(line.c_str(), &end, 10);
        if (errno == 0 && end != line.c_str() && *end == '\0') {
            out = v;
            return;
        }
    }


    {
        errno = 0;
        char* end = nullptr;
        double v = std::strtod(line.c_str(), &end);
        if (errno == 0 && end != line.c_str() && *end == '\0') {
            out = v;
            return;
        }
    }
    
    out = line;
}

template <typename T, typename... Args>
std::vector<T> index_sum(const std::vector<T>& vals){

}

template <typename T>
//^defines a new 'T' placeholder which will work with any data type
void vp(const std::vector<T >& vals, string type = "\n"){ //defines a vector<T> parameter
    for(int i=0; i<vals.size(); i++){ //loops thru the list 

        cout << vals[i];
        if(i != vals.size()-1){
            cout << type;
        }

        //^prints values on diff lines by default
       
    }
    cout << endl;
}

template <typename type>
bool is_number(type){
    bool number;
    if(std::is_same<type, string>::value || std::is_same<type, char>::value){
        number = false;
    }
    else{
        number = true;
    }

    return number;
}

template <typename IN>
vector<IN> take(int rep){
    vector<IN> vals;
    for(int i=0; i<rep; i++){
        IN val;
        cin >> val;
        vals.push_back(val);
    }

    return vals;
}

//template <typename ST>
vector<string> split(const string& line, char delim){
    stringstream ss(line);
    vector<string> vals;
    string track;   

    while(getline(ss, track, delim)){
        vals.push_back(track);
    }

    return vals;
}

/*template <typename TS> 
vector<TS> splot(string line, char delim){
    vector<TS> vals;
    string hold;
    for(int i=0; i<line.size(); i++){
        int index;
        if()
            for(int u=0; u<line.size(); u++){
                if(line[u] == delim){
                    index = u;
                    break;
                }
            }

        hold = line.substr(i, index);

    }
    
}*/


int occur(string line, char target){
    int count = 0;
    for(int i=0; i<line.size(); i++){
        if(line[i] == target){
            count++;
        }
    }

    return count;
}


template <typename T1, typename T2> //creates 2 T placeholder variables to work with any data types
//this function will link two vectors into a vector pair.
//(ex): {1, 2, 3} & {"one", "two", "three"} linked will result in {{1, "one"}, {2, "two"}, {3, "three"}}
vector<pair<optional<T1>, optional<T2>>> link(const std::vector<T1>& v1, const std::vector<T2>& v2, string cutoff){
    //^- 3 parameters, (vector<T>, vector<T>, String)
    //first parameter: a vector that will be the first series of values
    //second parameter: a vector that will be the second series of values
    //third parameter: a string that indicates the length of the vector pair
    //third parameter: an argument of "cut", will result in the vector pair being as long as the shortest vector
    //third parameter: an argument of "full", will result in the vector pair being as long as the longest vector
    //third parameter: an argument of "full" will result in excess spots in the vector pair being replaced with null values
    
    int len = (cutoff == full) ? max(v1.size(), v2.size()) : min(v1.size(), v2.size());

    vector<pair<optional<T1>, optional<T2>>> vals(len);

    for(int i=0; i<len; i++){

        if(i < v1.size()){
            vals[i].first = v1[i];
        }
        if(i < v2.size()){
            vals[i].second = v2[i];
        }   
    }

    return vals;
}

template <typename key, typename val>
map<key, val> mapp(const std::vector<key>& v1, const std::vector<val>& v2){
    
    int len = min(v1.size(), v2.size());       
    map<key, val> vals;

    for(int i=0; i<len; i++){

        vals.insert({v1[i], v2[i]});
        
    }

    return vals;
}

template <typename f, typename s>
void opp(const vector<pair<optional<f>, optional<s>>>& vals) {
    for (auto &p : vals) {
        cout << "(";
        if (p.first) cout << *p.first;
        else cout << "NULLOPT";

        cout << ", ";

        if (p.second) cout << *p.second;
        else cout << "NULLOPT";

        cout << ")" << endl;
    }
}




#endif
