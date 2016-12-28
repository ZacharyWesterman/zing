#pragma once
#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

namespace core
{
    ///Custom array class
    //This array is meant for storing objects with a moderate-to-large size.
    //It uses a vector of pointers rather than objects, to speed up resizing.
    //Thus, this class is not effective for small objects like chars.
    //(char pointer size > char size)
    template <typename T>
    class array
    {
    protected:
        std::vector<T> array_data;

    public:
        array() {}
        array(const array&);
        ~array() {}

        void clear();

        virtual int add(const T&);
        bool insert(const T&, uint);
        bool remove(uint);

        int size() const;

        T& at(const uint);
        const T& at(const uint) const;
        T& operator[](const uint);
        const T& operator[](const uint) const;

        ///Function to check if a given object is in the array
        //linear search (array is unsorted)
        //returns -1 if the object was not found,
        //returns the object's index if it was found
        virtual int find(const T& object) const
        {
            for (int i=0; i<(int)array_data.size(); i++)
                if (array_data.at(i) == object)
                    return i;

            return -1;
        }

        const array& operator=(const array& other)
        {
            clear();

            for (uint i=0; i<other.array_data.size(); i++)
                array_data.push_back(other.array_data.at(i));

            return *this;
        }

        bool operator==(const array& other) const
        {
            if (array_data.size() != other.array_data.size())
                return false;

            for (int i=0; i<(int)array_data.size(); i++)
                if (array_data.at(i) != other.array_data.at(i))
                    return false;

            return true;
        }

        bool is_valid(uint position) const
        {
            return (position < array_data.size());
        }
    };

    ///Copy constructor
    template <typename T>
    array<T>::array(const array<T>& other)
    {
        for (uint i=0; i<other.array_data.size(); i++)
            array_data.push_back(other.array_data.at(i));
    }


    ///Function to empty the array
    template <typename T>
    void array<T>::clear()
    {
        array_data.clear();
    }


    ///Function to append an object to the end of the array
    template <typename T>
    int array<T>::add(const T& object)
    {
        array_data.push_back(object);

        return (array_data.size() - 1);
    }


    ///Function to insert an object to the given index in the array
    //places the given object in that index(if valid), returning false if invalid index
    template <typename T>
    bool array<T>::insert(const T& object, uint index)
    {
        //if invalid index, return false
        if (index >= (int)array_data.size())
            return false;

        array_data.insert(array_data.begin() + index, object);

        return true;
    }


    ///Function to remove an object from the array
    //removes an object from the given index, returning false if invalid index
    template <typename T>
    bool array<T>::remove(uint index)
    {
        if ((index < 0) || (index >= array_data.size()))
            return false;

        array_data.erase(array_data.begin() + index);

        return true;
    }


    ///Return the number of objects in the array
    template <typename T>
    int array<T>::size() const
    {
        return (int)array_data.size();
    }

    ///Functions to get an object from the array, given an index
    //throw an exception if given an invalid index
    template <typename T>
    T& array<T>::at(uint index)
    {
        if (index >= array_data.size())
        {
            throw std::bad_alloc();
        }
        else
        {
            return array_data.at(index);
        }
    }

    template <typename T>
    const T& array<T>::at(uint index) const
    {
        if (index >= array_data.size())
        {
            throw std::bad_alloc();
        }
        else
        {
            return array_data.at(index);
        }
    }


    template <typename T>
    T& array<T>::operator[](uint index)
    {
        if (index >= array_data.size())
        {
            throw std::bad_alloc();
        }
        else
        {
            return array_data.at(index);
        }
    }

    template <typename T>
    const T& array<T>::operator[](uint index) const
    {
        if (index >= array_data.size())
        {
            throw std::bad_alloc();
        }
        else
        {
            return array_data.at(index);
        }
    }

}

#endif // ARRAY_H_INCLUDED
