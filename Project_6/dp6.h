// McKade Sorensen & Chenyi Ling
#ifndef _DP6_H_INCLUDED
#define _DP6_H_INCLUDED

#include <cstddef>      // For std::size_t
#include <memory>       // For std::unique_ptr
#include <utility>      // For std::pair
#include "llnode2.h"

template<typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head){

}
//    auto newHead;
//    while(head){
//        newHead = head;
//        head = head->_next;
//    }
//    head = newHead;


template<typename KeyType, typename DataType>
class LLMap{
public:
    using key_type = KeyType;   // Type of Key being used
    using data_type = DataType; // Type of Data being contained
    using size_type = std::size_t;

private:
    struct KVPair{
        key_type key;
        data_type data;
    };
public:
    std::unique_ptr<LLNode2<KVPair>> _ptr;

public:
    // ********************
    // *** Constructors ***
    // ********************
    LLMap(): _ptr(){
    }
    // Big Five
    ~LLMap(){
    }
    LLMap(const LLMap & other) = delete;
    LLMap & operator=(const LLMap & other) = delete;
    LLMap(LLMap && other) = delete;
    LLMap & operator=(LLMap && other) = delete;

public:
    // ************************
    // *** Member Functions ***
    // ************************
    size_type size() const{
        return 1;
    }
    bool empty() const{
        return true;
    }
    data_type * find(key_type key){
        return nullptr;
    }
    data_type * find(key_type key) const{
        return nullptr;
    }
    void insert(key_type key, data_type var){

    }
    void erase(key_type key){

    }
    template<typename F>
    void traverse(F) {
    }

};

#endif