// followers.cpp
// McKade Sorensen & Chenyi Ling
// Start 11/30/2019
// Finished 10/30/2019

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// Gets a file name as an input from a user and returns that input
string get_file_name(){
    cout << "Please insert the name of file: ";
    string file_name;
    getline(cin, file_name);

    return file_name;
}

// Opens a file
ifstream open_file(){
    ifstream file;
    file.open(get_file_name());
    return file;
}

bool check_items(const string & data, const vector<string> & vec){
    for(auto item : vec) {
        if (item == data)
            return false;
    }
    return true;
}

map<string, vector<string>> read_file(){
    ifstream file = open_file();
    map<string, vector<string>> the_map;
    string last_data;
    if(file.is_open()) {
        string data;
        while (!file.eof()) {

            file >> data;
            if(the_map.empty()){
                vector<string> vec;
                the_map[data] = vec;
            } else {
                bool check;
                auto iter_key = the_map.find(data);

                if(iter_key == the_map.end()) {
                    vector<string> vec;
                    the_map[data] = vec;
                    if (last_data.empty()) {
                        last_data = data;
                        continue;
                    }
                    check = check_items(data, the_map[last_data]);
                } else {
                    check = check_items(data, the_map[last_data]);
                }
                if(!check)
                    continue;
                the_map[last_data].push_back(data);
                last_data = data;
            }
        }
        file.close();
    }
    return the_map;
}

void check_the_map(const map<string, vector<string>> & the_map){
    for(auto it : the_map){
        string x;
        sort(it.second.begin(), it.second.end());
        for(auto y : it.second){
            x = x + " " + y;
        }
        cout << it.first << ": " << x << endl;
    }
}

int amount_of_distinct_words(const map<string, vector<string>> & the_map){
    vector<string> vec;
    for(auto items : the_map){
        if(vec.empty()){
            vec.push_back(items.first);
        }
        if(check_items(items.first, vec))
            vec.push_back(items.first);
        for(auto item : items.second)
            if(check_items(item, vec))
                vec.push_back(item);
    }
    return vec.size();
}

int main() {
    auto the_map = read_file();
    cout << "Number of distinct words: " << amount_of_distinct_words(the_map) << "\n\n";
    check_the_map(the_map);
}
