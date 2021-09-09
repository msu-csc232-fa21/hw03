/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file     hw01-test.cpp
 * @authors  Jim Daehn <jdaehn@missouristate.edu>
 * @brief    HW03 Unit test implementation -- DO NOT MODIFY THIS FILE!!!
 */

#define CATCH_CONFIG_MAIN // Tell Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "csc232.h"
#include "BagInterface.h"
#include "ArrayBag.h"

#if FINISHED_PART_1
SCENARIO("Testing the array bag recursive toVector implementation", "part1")
{
    GIVEN("An empty bag of integers")
    {
        BagInterface<int> *bag = new ArrayBag<int>{};

        WHEN("we see how many items it contains")
        {
            REQUIRE(bag != nullptr);
            int num_items{bag->getCurrentSize()};

            THEN("we find it contains no items")
            {
                REQUIRE(num_items == 0);
            }
        }

        WHEN("we see if it is empty")
        {
            REQUIRE(bag != nullptr);
            bool is_empty{bag->isEmpty()};

            THEN("we find it is indeed initially empty")
            {
                REQUIRE(is_empty);
            }
        }

        WHEN("we add an item to an empty bag")
        {
            REQUIRE(bag != nullptr);
            int item{42};
            int previous_size{bag->getCurrentSize()};
            bool is_added{bag->add(item)};

            THEN("it contains that one additional item")
            {
                int current_size{bag->getCurrentSize()};
                REQUIRE(is_added);
                REQUIRE(current_size == previous_size + 1);
                REQUIRE(bag->contains(item));

                AND_WHEN("we remove that item")
                {
                    bool is_removed{bag->remove(item)};
                    THEN("it no longer contains any items")
                    {
                        current_size = bag->getCurrentSize();
                        REQUIRE(current_size == previous_size);
                        REQUIRE_FALSE(bag->contains(item));
                    }
                }
            }
        }

        WHEN("we add an item to a full bag")
        {
            for (int item{0}; item < 6; ++item)
            {
                bag->add(item);
            }
            REQUIRE(bag->getCurrentSize() == 6);
            bool is_added{bag->add(7)};

            THEN("we find we couldn't add it and the size hasn't changed")
            {
                REQUIRE_FALSE(is_added);
                REQUIRE(bag->getCurrentSize() == 6);
                std::vector<int> contents = bag->toVector();
                std::vector<int> expected_contents{0, 1, 2, 3, 4, 5};
                for (int item{0}; item < 6; ++item)
                {
                    REQUIRE(contents.at(item) == expected_contents.at(item));
                    REQUIRE(bag->getFrequencyOf(item) == 1);
                }
            }

            AND_WHEN("we clear the bag")
            {
                bag->clear();

                THEN("the bag is empty")
                {
                    REQUIRE(bag->isEmpty());
                }
            }
        }
    }
}
#endif

#if FINISHED_PART_2
SCENARIO("Testing the overloaded remove method", "part2")
{
    GIVEN("An an array bag with several items")
    {
        BagInterface<std::string> *bag{new ArrayBag<std::string>{}};
        REQUIRE(bag != nullptr);
        bag->add("CSC232");
        bag->add("-");
        bag->add("Data Structures");
        bag->add(",");
        bag->add("Fall, 2021");
        REQUIRE(bag->getCurrentSize() == 5);
        REQUIRE_FALSE(bag->isEmpty());

        WHEN("we remove a random item")
        {
            int original_size{bag->getCurrentSize()};
            std::string item{bag->remove()};

            THEN("one of the items has been removed")
            {
                int current_size{bag->getCurrentSize()};
                REQUIRE(current_size == original_size - 1);
                bool item_existed{item == std::string{"CSC232"} ||
                                  item == std::string{"-"} ||
                                  item == std::string{"Data Structures"} ||
                                  item == std::string{","} ||
                                  item == std::string{"Fall, 2021"}};
                REQUIRE(item_existed);
            }
        }
    }
}
#endif

#if FINISHED_PART_3
SCENARIO("Testing the overloaded constructor", "part3")
{
    GIVEN("Items to put into a new bag")
    {
        std::pair<int, int> coordinates[] = {std::make_pair(-1, 2), std::make_pair(0, 0), std::make_pair(1, 2)};
        int expected_size{3};

        WHEN("we create a bag of these items")
        {
            BagInterface<std::pair<int, int>>* bag = new ArrayBag<std::pair<int, int>>{coordinates, 3};

            THEN("the bag contains all these items")
            {
                REQUIRE(bag->getCurrentSize() == expected_size);
                for (int index{0}; index < expected_size; ++index)
                {
                    REQUIRE(bag->contains(coordinates[index]));
                }
            }
        }
    }
}
#endif
