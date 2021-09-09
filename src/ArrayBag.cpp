/**
 * @file ArrayBag.cpp
 * @authors Created by Frank M. Carrano and Timothy M. Henry
 *          Modifications/updates by Jim Daehn <jdaehn@missouristate.edu>
 *          TODO: Add your name here
 * @brief Implementation file for the class ArrayBag.
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 * 
 */

#include "ArrayBag.h"
#include <cstddef>

template <typename ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount{0}, maxItems{DEFAULT_CAPACITY}
{
} // end default constructor

// TODO: Part 3b - Implement overloaded constructor


template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
} // end getCurrentSize

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
} // end isEmpty

template <typename ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    } // end if

    return hasRoomToAdd;
} // end add

template <typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    } // end if

    return canRemoveItem;
} // end remove

// TODO: Part 2c - Implement the overloaded remove method below


template <typename ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
} // end clear

template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const
{
    int frequency = 0;
    int curIndex = 0; // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        } // end if

        curIndex++; // Increment to next entry
    }               // end while

    return frequency;
} // end getFrequencyOf

template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &anEntry) const
{
    return getIndexOf(anEntry) > -1;
} // end contains

// private
template <typename ItemType>
void ArrayBag<ItemType>::addToVector(std::vector<ItemType> &item_vector, int index) const
{
    // TODO: Part 1 - Implement me...
} // end addToVector

template <typename ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    addToVector(bagContents, 0);
    return bagContents;
} // end toVector

// private
template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        } // end if
    }     // end while

    return result;
} // end getIndexOf
