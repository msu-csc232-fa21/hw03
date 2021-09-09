/**
 * @file ArrayBag.h
 * @authors Created by Frank M. Carrano and Timothy M. Henry
 *          Modifications/updates by Jim Daehn <jdaehn@missouristate.edu>
 *          TODO: Add your name here
 * @brief Header file for an array-based implementation of the ADT bag.
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 * 
 */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY];      // Array of bag items
    int itemCount;                         // Current count of bag items
    int maxItems;                          // Max capacity of the bag

    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const ItemType &target) const;

    /**
     * @brief A recursive helper function called by toVector.
     * 
     * @param item_vector a vector to be populated with the contents of items
     * @param index an index into the items array
     */
    void addToVector(std::vector<ItemType>& item_vector, int index) const;
public:
    ArrayBag();

    // TODO: Part 3a - Declare overloaded constructor below

    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType &newEntry) override;
    bool remove(const ItemType &anEntry) override;
    
    // TODO: Part 2b - Declare the overloaded remove method below
    
    void clear() override;
    bool contains(const ItemType &anEntry) const override;
    int getFrequencyOf(const ItemType &anEntry) const override;
    std::vector<ItemType> toVector() const override;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
