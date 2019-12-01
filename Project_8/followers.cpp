// followers.cpp
// McKade Sorensen & Chenyi Ling
// Start 11/30/2019
// Finished 12/1/2019

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
// Does not throw
string get_file_name(){
    cout << "Please insert the name of file: ";
    string file_name;
    getline(cin, file_name);

    return file_name;
}


// Opens a file
// throws - TODO: Check to see if it throws for sure
ifstream open_file(){
    ifstream file;
    file.open(get_file_name());
    return file;
}


// Checks each item within a vec against data. If data == any item in vec returns false
// otherwise it returns true.
// Does not throw
// Pre:
//  None
bool check_items(const string & data, const vector<string> & vec){
    for(auto & item : vec) {
        if (item == data)
            return false;
    }
    return true;
}


// Reads the file and and places unique words in a map as a key with all the words
// that follow it as the value stored in a vector.
// TODO: Figure out if it throws or not
map<string, vector<string>> read_file(){
    ifstream file = open_file();
    map<string, vector<string>> the_map;
    string last_data;

    if(file.is_open()) {
        string data;
        while (!file.eof()) {

            file >> data;
            if(the_map.empty()){                        // If the map is empty, create new key, and value.
                vector<string> vec;
                the_map[data] = vec;
            } else {
                bool check;
                auto iter_key = the_map.find(data);     // Check to see if the data exists

                if(iter_key == the_map.end()) {         // If data doesn't exist add it as a key
                    vector<string> vec;
                    the_map[data] = vec;
                    if (last_data.empty()) {            // If data isn't defined yet, define it and continue
                        last_data = data;
                        continue;
                    }
                    check = check_items(data, the_map[last_data]);  // Make sure data isn't stored in the keys vector
                } else {
                    check = check_items(data, the_map[last_data]);  // Make sure data isn't stored in the keys vector
                }
                if(!check)      // If data was already stored continue with out adding another copy
                    continue;
                the_map[last_data].push_back(data);
                last_data = data;
            }
        }
        file.close();
    }
    return the_map;
}


// Sorts and formats each keys vector and prints the output.
// Throws - TODO: Check to see if it actually throws
// Pre:
//  None
void output_the_map(const map<string, vector<string>> & the_map){
    for(auto it : the_map){                        // Loop through each key to sort and format them
        string x;
        sort(it.second.begin(), it.second.end());  // Sort each keys values
        for(auto & y : it.second){                 // Format sorted vector
            x += " " + y;
        }
        cout << it.first << ": " << x << endl;
    }
}


// Returns the amount of distinct words within a map
// TODO: Figure out if it throws or not
// Pre:
//  None
int amount_of_distinct_words(const map<string, vector<string>> & the_map){
    vector<string> vec;
    for(auto & items : the_map){
        if(vec.empty()){                   // If vec is empty add first element
            vec.push_back(items.first);
        }

        if(check_items(items.first, vec))   // Checks the key and adds it if needed
            vec.push_back(items.first);

        for(auto & item : items.second)     // Checks the values stored with the key, adds them if needed
            if(check_items(item, vec))
                vec.push_back(item);
    }
    return vec.size();
}


// TODO: Figure out if you need to add if this function throws or not
int main() {
    auto the_map = read_file();
    cout << "Number of distinct words: " << amount_of_distinct_words(the_map) << "\n\n";
    output_the_map(the_map);
}
