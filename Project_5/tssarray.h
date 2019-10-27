// ssarray.h
// McKade Sorensen (Douglas)
// Start 10/23/2019
// Finished / /
//
// Header file for tssarray.cpp

#ifndef _SSARRAY_H_INCLUDED
#define _SSARRAY_H_INCLUDED

#include <cstddef> //  For std::size_t
#include <algorithm> //  For std::max


//   ***********************************
//  *** TSSArray - Class Definition ***
// ***********************************

// TODO: ADD CLASS INVARIANTS
// TODO: PUT "EXCEPTION NEUTRAL" BEFORE EVERY FUNCTION

template <typename T>
class TSSArray{
public:
    using value_type =  T; //  Type of data being contained
    using size_type = std::size_t; // TODO: Add a comment here

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
    // Copy Ctor
    // Strong Guarantee
    TSSArray(const TSSArray & other);

    // Move Ctor
    // No-Throw Guarantee
    TSSArray(TSSArray && other) noexcept;

    // Dctor
    // No-Throw Guarantee
    ~TSSArray(){
        delete [] _data;
    }

    //   ******************************
    //  **** Overloaded operators ****
    // ******************************
    TSSArray & operator=(const TSSArray & rhs);

    TSSArray & operator=(TSSArray && rhs) noexcept;

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
    void resize(size_type newsize);

    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item);

    // erase
    // ??? Guarantee
    iterator erase(iterator pos);

    // push_back
    // ??? Guarantee
    void push_back(value_type item){
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back(){
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(TSSArray & other) noexcept;

};

#endif