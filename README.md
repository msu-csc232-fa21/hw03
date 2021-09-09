# HW03 - Capture the Ceryneian Hind

Driven mad by CSC131, the Student smashed their laptop.

After recovering their sanity, the Student deeply regretted their actions; they were purified by Chair of the CS Department, then traveled to Cheek 209 to inquire how they could atone for their actions. The Executive Assistant and Oracle of Delphi, advised them to go to Cheek 61M and serve its occupant, Jim Daehn, for one semester, performing whatever labors Jim might set upon them; in return, they would be rewarded with immortality, or at least forward movement in their curriculum.

The Student despaired at this, loathing to serve a man whom they knew to be far inferior to themselves, yet fearing to oppose the Chair. Eventually, they placed themselves at Jim's disposal.

Jim originally ordered the Student to perform ten labors. The Student accomplished these tasks, but Jim refused to recognize two: the slaying of the [Lernaean Hydra](https://en.wikipedia.org/wiki/Labours_of_Hercules#Second:_Lernaean_Hydra), as the Students' GA had helped them; and the cleansing of the [Augeas](https://en.wikipedia.org/wiki/Labours_of_Hercules#Fifth:_Augean_stables), because the Student accepted payment for the labor.

Jim set two more tasks (fetching the [Golden Apples of Hesperides](https://en.wikipedia.org/wiki/Labours_of_Hercules#Eleventh:_Golden_Apples_of_the_Hesperides) and capturing [Cerberus](https://en.wikipedia.org/wiki/Labours_of_Hercules#Twelfth:_Cerberus)), which the Student also performed, bringing the total number of tasks to twelve.

Having slain the Nemean Lion and the Lernaean Hydra, the Student is now prepared to [Capture the Ceryneian Hind](https://en.wikipedia.org/wiki/Labours_of_Hercules#Third:_Ceryneian_Hind), a creature so fast it could outrun an arrow...

<p><a href="https://upload.wikimedia.org/wikipedia/commons/thumb/4/42/Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg/800px-Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/42/Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg/800px-Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg" height="480" width="430"></a></p>

## ADTs: Updating the ArrayBag

_Note: This assignment is related to the Exercises 6, 8 and 9 of Chapter 3 found in **Data Abstraction and Problem-Solving with C++**, seventh edition, by Carrano & Henry. See [our disclaimer below](#disclaimer--fair-use-statement)._

This assignment is primarily meant to give the student experience in modifying existing classes, i.e., with more experience with the concept of inheritance. Along the way, the student also gains more experience with recursion.

## Objectives

In this assignment you

* modify the implementation of one of the methods in the `ArrayBag` class
* Update the `BagInterface` (and its `ArrayBag` implementation) by
  * adding a new method that removes a random entry in the bag
  * adding a new constructor

Upon successful completion of this assignment, the student will implement the following exercises:

* **Exercise 6**: Write a recursive array-based implementation of the method `toVector`
* **Exercise 8**: Specify and define a method for `ArrayBag` that removes a random entry from the bag
* **Exercise 9**: Add a constructor to the class `ArrayBag` that creates a bag from a given array of entries

These three exercises will be tackled by modifying the `BagInterface` and `ArrayBag` specifications and implementations.

## Background Reading

Before you tackle this assignment, it is advised that you read and understand the following in Carrano & Henry:

* **Appendix A** Review of C++ Fundamentals
* **Appendix B** Important Themes in Programming
* **Chapter 1** Data Abstraction: The Walls
* **C++ Interlude 1** C++ Classes (in particular, C1.4 - Inheritance)
* **Chapter 2** Recursion: The Mirrors
* **Chapter 3** Array-based Implementations

If you have not read these chapters, do it now!

## C++ Concepts Overview

As we have seen, inheritance is a form of code reuse. Here, we will reuse much of the code already written in the `ArrayBag`. We will _update_ this class by modifying one of its  methods, writing a new method that that will be added to the `BagInterface`, and _overloading_ the class constructor.

This small and simple exercise actually entails three important concepts:

1. **Inheritance** - reusing existing code and _adding_ to that code base
2. **Overloading** operations - providing another operation with the same name but a different signature
3. **Overriding** operations - providing a new implementation of an _existing_ operation

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/czFGVsNb), clone this repository. Once cloned, create a new branch named `develop` within which to do your work. Ultimately, you will create a pull request that seeks to merge your `develop` branch into your `trunk` branch.

To create your new branch and push it to GitHub, issue the following `git` commands (in either a GitBash window, Ubuntu terminal or via your IDE that supports git operations):

```bash
git checkout -b develop
git push -u origin develop
```

**NOTE**: The `-b` switch on the original `checkout` and the `-u origin develop` is required only the _first_ time you push your branch to GitHub. All subsequent pushes are done by merely typing

```bash
git push
```

Once your branch has been pushed to GitHub and you have pushed some changes that you have committed on your branch, you are ready to create a pull request. When creating this pull request, be sure to request that you seek to merge changes in your `develop` branch _into_ your `trunk` branch.

You can create this pull request anytime after you've pushed a commit to your `develop` branch. If you find that you have additional commits to push to GitHub, there is no need to create another pull request; the existing one is automatically with your latest pushes.

If you're using Microsoft Visual Code, you can open your source repository from with GitBash using the command:

```bash
code .
```

Don't forget the trailing period `.` for it specifies to code that you want to open the current directory.

## Tasks

This assignment requires three basic tasks:

1. Provide a different implementation of the `toVector()` operation inherited from `BagInterface`
2. Update the `BagInterface` by adding a new operation that removes a random entry in the bag
3. Overload the `ArrayBag` constructor by providing a new constructor that takes an array of items that is used to create a new `ArrayBag`

Before you begin, be sure you have thoroughly read through the aforementioned [Background Reading](#background-reading).

Additional preliminary steps you may want to take:

1. Take a look around this repository.
   1. Note how the code is organized. Notice that all header files are located in an [include](include) folder and all the implementation files are located in the [src](src) folder.
   2. **Unit tests** are located in yet another folder named [test](test). Please note: Unless told otherwise, **never** modify the contents of this folder. These unit tests are executed to determine the degree to which you have successfully completed your assignment.
2. Study the [CMakeLists.txt](CMakeLists.txt) file. What do you suppose is the purpose of this file? _Don't worry too much if you don't understand this file; we will discuss it and how its used by a program named `cmake`.
3. Jot down anything that you don't understand.

### Part 1: Modifying an existing operation

In Part 1 of this assignment you will provide a _different implementation_ of the `toVector` operation. Your new implementation will use recursion to create a vector of the items contained in the bag. Recall, recursive functions require some parameter that will help drive repeated execution towards reaching the base case. Thus, the existing `toVector()` operation inherited from the `BagInterface` cannot serve as a recursive function (it doesn't have any parameters, so there's no way to drive you towards a base case case).

In these scenarios, one often defines a _private_ helper member function that acts recursively. This helper member function is called initially from within the existing _public_ member function. For example, take a look at the definition of `toVector()` found in [src/ArrayBag.cpp](src/ArrayBag.cpp). It looks like this:

```c++
template <typename ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    addToVector(bagContents, 0);
    return bagContents;
} // end toVector
```

The second statement in the body of the function, `addToVector(bagContents, 0)` is the initial call of the recursive helper function. A vector (named `bagContents`) is passed by reference to the `addToVector()` method. The second argument passed to the `addToVector()` method (0, in this initial call), is the starting index of the array whose contents are (recursively) added to the vector with each (recursive) call. The recursive calls whenever that second parameter is less than the number of items in the bag.

When you have completed this part, toggle the macro `FINISHED_PART_1` found in [include/csc232.h](include/csc232.h) from `FALSE` to `TRUE` and run the test target to verify you have successfully implemented the `toVector` operation correctly.

Your task then, in Part 1, is to implement this helper function. Open the array bag implementation file [src/ArrayBag.cpp](src/ArrayBag.cpp) and look for the `TODO: Part 1 - Implement me...` line found in the (essentially) empty body of this helper method. Replace that `TODO` comment with your (recursive) implementation of this member function.

When you're ready to test your implementation, toggle the macro `FINISHED_PART_1` found in [include/csc232.h](include/csc232.h) from `FALSE` to `TRUE` and run the `hw03-tests` target.

After you have finished modifying this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (the output, where it occurred, has been ommitted for clarity).

```bash
git add src/ArrayBag.cpp
git add include/csc232.h
git commit -m"HW03 - Completed Part 1."
git push
```

### Part 2: Expanding the Bag Interface

In Part 2 of this assignment you will _modify_ both the `BagInterface` and `ArrayBag` classes by adding a new operation that removes a random entry from the bag. That is, we are expanding the API of the `BagInterface`. Since `ArrayBag` implements this interface, it will have to provide an implementation for this new method it inherits from the `BagInteface`. Doing this will require three steps:

1. Add a new pure virtual method to the `BagInterface` specification (header) file ([include/BagInterface.h](include/BagInterface.h)).
2. Add a new member function declaration to the `ArrayBag` specification (header) file ([include/ArrayBag.h](include/ArrayBag.h)).
3. Add a new member function definition to the `ArrayBag` implementation (source) file ([src/ArrayBag.cpp](src/ArrayBag.cpp)).

#### Updating the Bag Interface ADT

As mentioned above, the first step is to expand the current `BagInterface` API by adding a new pure virtual function declaration to [include/BagInterface.h](include/BagInterface.h). Open this file and locate the Doxygen comments that guide your effort here:

```c++
    /**
     * @brief TODO: Part 2a - Declare a new pure virtual member function named
     *        remove that has a return type of ItemType and no parameters.
     * 
     * @return A randomly removed item from this bag.
     */
```

Just below these comments, add your pure virtual function declaration. Note: the name of this function is expected to begin with a lowercase letter.

After you have modified this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (again the output, where it occurred, has been ommitted for clarity).

```bash
git add include/BagInterface.h
git commit -m"HW03 - Completed Part 2a."
git push
```

#### Updating the ArrayBag Specification

Now that the `BagInterface` has a new pure virtual method declared in it, the `ArrayBag` specification similarly needs updating. Locate the comment:

```c++
// TODO: Part 2b - Declare the overloaded remove method below
```

in the [include/ArrayBag.h](include/ArrayBag.h) header file.

Replace that comment with the appropriate override statement. Use the other methods as your guide for how to declare this method as an `override`.

After you have modified this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (again the output, where it occurred, has been ommitted for clarity).

```bash
git add include/ArrayBag.h
git commit -m"HW03 - Completed Part 2b."
git push
```

#### Updating the ArrayBag Implementation

Now that you've "promised" to override an inherited method, it's time to live up to your obligations. Locate the comment:

```c++
// TODO: Part 2c - Implement the overloaded remove method below
```

in the [src/ArrayBag.cpp](src/ArrayBag.cpp) source file.

Replace that comment with your implementation of this new member function. This will be fairly similar to the existing `remove` method, differing only in which item is removed. In the existing (original) `remove` method, you had a parameter -- the item to locate, and if found -- that specifies which item to remove. This new version of `remove` no longer has a parameter; you'll be removing a random item from the array. Thus, in essence what you need to do is generate a random index somewhere in the range of 0 to the number of items that are currently in your bag. That randomly generated index will be the item to remove. Finally, one other significant difference between this version and the existing version of `remove` is that you are actually returning the item that was randomly selected for removal. Recall, the original `remove` method simply return a `bool` value related to the success or failure of said removal.

C++ contains libraries to help you with generating (pseudo) random integers in a range of values. See, for example, [cppreference.com](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution).

Borrowing from that page, the following lines of code can be used to generate a random integer from `LOWER_BOUNDARY_VALUE` to `UPPER_BOUNDARY_VALUE` (inclusive).

```c++
std::random_device rd;  // Will be used to obtain a seed for the random number engine
std::mt19937 gen{rd()}; // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib{LOWER_BOUNDRY_VALUE, UPPER_BOUNDRY_VALUE};
```

Take a moment to think about what these boundary values are for this particular implementation.

When you're ready to test your implementation, toggle the macro `FINISHED_PART_2` found in [include/csc232.h](include/csc232.h) from `FALSE` to `TRUE` and re-run the `hw03-tests` target.

After you have finished modifying this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (again the output, where it occurred, has been ommitted for clarity).

```bash
git add src/ArrayBag.cpp
git add include/csc232.h
git commit -m"HW03 - Completed Part 2c."
git push
```

### Part 3: Overloading class constructor

In Part 3 of this assignment you will _overload_ the constructor of the `ArrayBag` class.

In the [include/ArrayBag.h](include/ArrayBag.h) header file, locate the comment:

```c++
// TODO: Part 3a - Declare overloaded constructor below
```

Replace that comment with the declaration of another constructor. In this case, it is considered an "initializing" constructor because we're passing in some parameters that are used to initialize the state of the new created `ArrayBag` object. In this overloaded constructor, we'll need to pass in two parameters:

1. An array of `ItemType` that contains a collection of items used to initialize this `ArrayBag`.
2. An integer that represents the size of the array (because of course, arrays don't know their own size).

After you have finished modifying this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (again the output, where it occurred, has been ommitted for clarity).

```bash
git add include/ArrayBag.h
git commit -m"HW03 - Completed Part 3a."
git push
```

Next, locate the comment:

```c++
// TODO: Part 3b - Implement overloaded constructor
```

in the [src/ArrayBag.cpp](src/ArrayBag.cpp) implementation source file.

Replace that comment with your implementation of this overloaded constructor. Note: you should still use the initialization list as shown in the default constructor implementation, albeit `itemCount` won't be 0 this time; it'll be value of your array size parameter passed to this constructor.

In addition to initializing the `ArrayBag` attributes with the appropriate initialization list, you must also copy the items in the passed-in array into the newly constructed `ArrayBag` attribute (`items`); this is done in the body of this constructor.

When you're ready to test your implementation, toggle the macro `FINISHED_PART_3` found in [include/csc232.h](include/csc232.h) from `FALSE` to `TRUE` and re-run the `hw03-tests` target.

After you have finished modifying this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (again the output, where it occurred, has been ommitted for clarity).

```bash
git add src/ArrayBag.cpp
git add include/csc232.h
git commit -m"HW03 - Completed Part 3b."
git push
```

As a final step, log onto GitHub and make sure that your pull request has all your commits. If it doesn't, make a final commit and/or push your last commit to GitHub. Also, make sure that `professordaehn`, `lakshmidivyavaddineni` and `SunandaGuha` are listed as a Reviewers on your pull request. (It may be that only `professordaehn` is listed; if that is the case, manually add the GA usernames too. While you're at it, assign the pull request to yourself.)

## Submission Details

As usual, prior to submitting your assignment to Blackboard, be sure that you have committed and pushed your final changes to GitHub. If you have not done so already, create a **pull request** that seeks to merge your `develop` branch into your `trunk` branch.  Submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a **Text Submission** (and _not_ as a comment) in Blackboard. **Please note**: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted.

Finally, be sure that you **do not merge your pull request until it has been approved by one of the assigned reviewers**.

### Due Date

Your Blackboard submission is due by 23:59 Wednesday, 15 September 2021.

### Grading Rubric

This assignment is worth **5 points**.

Criteria          | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                                 |
------------------|------------------------------|-------------------------------------|-------------------------------------|---------------------------------------------------------|
Pull Request (20%)| Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted                |
Code Style (20%)  | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present          |
Correctness^ (60%)| All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass                    |

^ _The Catch2 Test unit runner, if appropriate, will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this lab will be penalized 1 point meaning the grading starts at 4 (out of 5 total possible) points.
* In the second 24 hour period following the due date, this lab will be penalized 2 points meaning the grading starts at 3 (out of 5 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 5 possible points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not have been specifically authorized by the copyright owner. This material is available in an effort to explain issues relevant to the course or to illustrate the use and benefits of an educational tool. The material contained in this repository is distributed without profit for research and educational purposes. Only small portions of the original work are being used and those could not be used to easily duplicate the original work.

This constitute a 'fair use' of any such copyrighted material (referenced and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this repository for purposes that go beyond 'fair use', you must obtain expressed permission from the copyright owner.
