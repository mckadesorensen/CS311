// McKade Sorensen & Chenyi Ling
#ifndef _DP6_H_INCLUDED
#define _DP6_H_INCLUDED

#include <cstddef>      // For std::size_t
#include <memory>       // For std::unique_ptr
#include <iostream>
#include "llnode2.h"

template<typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head){

    unique_ptr<LLNode2<ValType>> next, newHead;
    next = std::move(nullptr);

    while(head){
        next = std::move(head->_next);
        head->_next = std::move(newHead);
        newHead = std::move(head);
        head = std::move(next);
    }
    head = std::move(newHead);
}


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
    } kvPair;
public:
    std::unique_ptr<LLNode2<KVPair>> _head;

public:
    // ********************
    // *** Constructors ***
    // ********************
    LLMap(): _head(){}
    // Big Five
    ~LLMap(){}
    LLMap(const LLMap & other) = delete;
    LLMap & operator=(const LLMap & other) = delete;
    LLMap(LLMap && other) = delete;
    LLMap & operator=(LLMap && other) = delete;

public:
    // ************************
    // *** Member Functions ***
    // ************************
    const size_type size() const{
        auto ptr = _head.get();
        size_type count = 0;
        while(ptr != nullptr){
            ++count;
            ptr = ptr->_next.get();
        }
        return count;
    }

    bool empty() const{
        return !_head;
    }

    data_type * find(key_type key){
        auto ptr = _head.get();
        while(ptr != nullptr){
            if(ptr->_data.key == key) {
                return &(ptr->_data.data);
            }
            ptr = ptr->_next.get();
        }
        return nullptr;
    }


    const data_type * find(key_type key) const{
        auto ptr = _head.get();
        while(ptr != nullptr){
            if(ptr->_data.key == key) {
                return &(ptr->_data.data);
            }
            ptr = ptr->_next.get();
        }
        return nullptr;
    }


    void insert(key_type key, data_type data) {
        auto ptr = _head.get();
        auto trail_ptr = nullptr;
        while (ptr != nullptr) {
            if (key == ptr->_data.key) {
                ptr->_data.data = data;
                return;
            }
            ptr = ptr->_next.get();
        }
        KVPair pair;
        pair.data = data;
        pair.key = key;
        _head = make_unique<LLNode2<KVPair>>(pair, _head);

    }
    void erase(key_type key){
        auto ptr = _head.get();
        auto tail_ptr = _head.get();
        while(ptr != nullptr){
            if(ptr->_data.key == key){
                tail_ptr->_next = std::move(ptr->_next);
                ptr->_next = nullptr;
            }
            tail_ptr = std::move(ptr);
            ptr = ptr->_next.get();

        }
    }
    template<typename F>
    void traverse(F) {
        auto ptr = _head.get();
        while(ptr != nullptr){
//            F(ptr->_data)
            ptr = ptr->_next.get();
        }
    }

};

#endif