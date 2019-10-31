// ssarray.h
// McKade Sorensen & Chenyi Ling
// Start 10/23/2019
// Finished 10/30/2019
//
// Header file for tssarray.cpp

#ifndef _SSARRAY_H_INCLUDED
#define _SSARRAY_H_INCLUDED

#include <cstddef>   //  For std::size_t
#include <algorithm> //  For std::max


//   ***********************************
//  *** TSSArray - Class Definition ***
// ***********************************

//   ***************************
//  *** TSSArray Invariants ***
// ***************************
// Generic container, with client-specified value type
// Invariants:
//      TODO: FINISH THIS PART
// Requirement on Types:
//      Val must be a copy ctor and a (non-throwing) dctor

template <typename Val>
class TSSArray{
public:
    using value_type =  Val;       //  Type of data being contained
    using size_type = std::size_t; //  Type of sizes & indices

    // Iterators: Random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

private:
    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

    size_type _capacity{}; //  Size of allocated array
    size_type _size;     //  Size of the array
    value_type * _data;  //  Pointer to the array

public:
    //   ********************
    //  *** Constructors ***
    // ********************
    // Default Ctor
    // Strong Guarantee
    explicit TSSArray(size_t size=0) : _capacity(std::max(size, size_type(DEFAULT_CAP))),
                                       _size(size),
                                       _data(new value_type[_capacity]){

    }

    //   ****************
    //  *** Big Five ***
    // ****************
    // Copy Ctor
    // Basic Guarantee
    TSSArray(const TSSArray & other) : _capacity(other._capacity),
                                       _data(new value_type[other._capacity]),
                                       _size(other.size()){
        try{
            std::copy(other.begin(),other.end(),this->begin());
        } catch(...){
            delete [] _data;
            throw;
        }
    }

    // Move Ctor
    // No-Throw Guarantee
    TSSArray(TSSArray && other) noexcept : _capacity(other._capacity),
                                           _data(other._data),
                                           _size(other.size()){
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    // Dctor
    // No-Throw Guarantee
    ~TSSArray(){
        delete [] _data;
    }
    // Copy Assignment
    // No-Throw Guarantee
    TSSArray & operator=(const TSSArray & rhs){
        TSSArray to_copy(rhs);
        swap(to_copy);
        return *this;
    }
    // Move Assignment
    TSSArray & operator=(TSSArray && rhs) noexcept{
        swap(rhs);
        return *this;
    }

    //   ******************************
    //  **** Overloaded operators ****
    // ******************************
    // Exception neutral
    value_type & operator[](size_type index) noexcept{
        return _data[index];
    }
    // Exception neutral
    const value_type & operator[](size_type index) const noexcept{
        return _data[index];
    }
public:
    //   ************************
    //  *** Member Functions ***
    // ************************
    // size
    // Exception neutral
    // No-Throw Guarantee
    size_type size() const noexcept{
        return _size;
    }

    // empty
    // Exception neutral
    // No-Throw Guarantee
    bool empty() const noexcept{
        return size() == 0;
    }

    // begin - non-const & const
    // Exception neutral
    // No-Throw Guarantee
    iterator begin() noexcept{
        return _data;
    }
    const_iterator begin() const noexcept{
        return _data;
    }

    // end - non-const & const
    // Exception neutral
    // No-Throw Guarantee
    iterator end() noexcept{
        return begin() + size();
    }
    const_iterator end() const noexcept{
        return begin() + size();
    }

    // resize
    // Exception neutral
    // Basic Guarantee
    // 0 <= _size <= _capacity
    void resize(size_type new_size){

        if(new_size <= _capacity){
            _size = new_size;
            return;
        }


        auto temp = {_capacity, _size, new_size};
        size_type new_capacity = 2*std::max(temp);
        value_type* new_data = new value_type[new_capacity];
        try{
            std::copy(this->begin(),this->end(), new_data);
        }catch(...){
            delete [] new_data;
            throw;
        }

        std::swap(_size, new_size);
        std::swap(_data, new_data);
        std::swap(_capacity, new_capacity);
    }

    // insert
    // Exception neutral
    // Basic Guarantee
    iterator insert(iterator pos, const value_type & item){
        // Resizing to add the new value
        auto itr = pos - begin();
        this->resize(this->size()+1);
        _data[this->size() - 1] = item;
        std::rotate(this->begin()+itr, this->end() -1, this->end());
        return this->begin() + itr;
    }

    // erase
    // Exception neutral
    // Basic Guarantee
    iterator erase(iterator pos){
        std::rotate(pos, pos + 1, this->end());
        this->resize(this->size() - 1);
        return pos;
    }
    // push_back
    // Exception neutral
    // Basic Guarantee
    void push_back(const value_type & item){
        insert(end(), item);
    }

    // pop_back
    // Exception neutral
    // Basic Guarantee
    void pop_back(){
        erase(end()-1);
    }

    // swap
    // Exception neutral
    // No-Throw Guarantee
    void swap(TSSArray & other) noexcept{
        std::swap(this->_size, other._size);
        std::swap(this->_capacity, other._capacity);
        std::swap(this->_data, other._data);
    }

};

#endif