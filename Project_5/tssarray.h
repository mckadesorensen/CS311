// ssarray.h
// McKade Sorensen (Douglas)
// Start 10/23/2019
// Finished / /
//
// Header file for tssarray.cpp

#ifndef _SSARRAY_H_INCLUDED
#define _SSARRAY_H_INCLUDED

#include <cstddef>   //  For std::size_t
#include <algorithm> //  For std::max
#include <iostream>  //  Remove when Finished with project


//   ***********************************
//  *** TSSArray - Class Definition ***
// ***********************************

// TODO: ADD CLASS INVARIANTS
// TODO: PUT "EXCEPTION NEUTRAL" BEFORE EVERY FUNCTION

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

    size_type _capacity; //  Size of allocated array
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
    // Strong Guarantee
    TSSArray(const TSSArray & other) : _data(new value_type[other.size()]),
                                       _size(other.size()){
        for(size_type i = 0; i != _size; ++i)
            _data[i] = other[i];
    }

    // Move Ctor
    // No-Throw Guarantee
    TSSArray(TSSArray && other) noexcept : _data(other._data),
                                           _size(other.size()){
        other._data = nullptr;
    }

    // Dctor
    // No-Throw Guarantee
    ~TSSArray(){
        delete [] _data;
    }
    // Copy Assignment
    TSSArray & operator=(const TSSArray & rhs) {
        TSSArray to_copy(rhs);
        swap(to_copy);
        return *this;
    }
    // Move Assignment
    TSSArray & operator=(TSSArray && rhs) noexcept {
        swap(rhs);
        return *this;
    }

    //   ******************************
    //  **** Overloaded operators ****
    // ******************************
    value_type & operator[](size_type index) noexcept{
        return _data[index];
    }
    const value_type & operator[](size_type index) const noexcept{
        return _data[index];
    }
public:
    //   ************************
    //  *** Member Functions ***
    // ************************
    // size
    // No-Throw Guarantee
    size_type size() const noexcept{
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept{
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept{
        return _data;
    }
    const_iterator begin() const noexcept{
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept{
        return begin() + size();
    }
    const_iterator end() const noexcept{
        return begin() + size();
    }

    // resize
    // ??? Guarantee
    // 0 <= _size <= _capacity
    void resize(size_type new_size){
            if( new_size > _capacity)
                _capacity = new_size * 2;
            _size = new_size;
            value_type * new_data = new value_type[_size];
            new_data = _data;
    }

    // insert
    // ??? Guarantee
    iterator insert(iterator pos, const value_type & item){
        // Resizing to add the new value
        this->resize(this->_size+1);
        std::rotate(this->begin(), pos-1, this->end());
        this->push_back(item);
        std::rotate(this->begin(), pos-1, this->end());
        // TODo: Need to return a location incase we made it larger

        return nullptr;
    }

    // erase
    // ??? Guarantee
    iterator erase(iterator pos){
        std::rotate(this->begin(), pos-1,this->end());
        this->pop_back();
        std::rotate(this->begin(), pos-1, this->end());
        return pos;
    }

    // push_back
    // ??? Guarantee
    void push_back(const value_type & item){
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back(){
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(TSSArray & other) noexcept{
        std::swap(this->_size, other._size);
        std::swap(this->_capacity, other._capacity);
        std::swap(this->_data, other._data);
    }

};

#endif