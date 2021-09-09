# HW03 - Capture the Ceryneian Hind

Driven mad by CSC131, the Student smashed their laptop.

After recovering their sanity, the Student deeply regretted their actions; they were purified by Chair of the CS Department, then traveled to Cheek 209 to inquire how they could atone for their actions. The Executive Assistant and Oracle of Delphi, advised them to go to Cheek 61M and serve its occupant, Jim Daehn, for one semester, performing whatever labors Jim might set upon them; in return, they would be rewarded with immortality, or at least forward movement in their curriculum.

The Student despaired at this, loathing to serve a man whom they knew to be far inferior to themselves, yet fearing to oppose the Chair. Eventually, they placed themselves at Jim's disposal.

Jim originally ordered the Student to perform ten labors. The Student accomplished these tasks, but Jim refused to recognize two: the slaying of the [Lernaean Hydra](https://en.wikipedia.org/wiki/Labours_of_Hercules#Second:_Lernaean_Hydra), as the Students' GA had helped them; and the cleansing of the [Augeas](https://en.wikipedia.org/wiki/Labours_of_Hercules#Fifth:_Augean_stables), because the Student accepted payment for the labor.

Jim set two more tasks (fetching the [Golden Apples of Hesperides](https://en.wikipedia.org/wiki/Labours_of_Hercules#Eleventh:_Golden_Apples_of_the_Hesperides) and capturing [Cerberus](https://en.wikipedia.org/wiki/Labours_of_Hercules#Twelfth:_Cerberus)), which the Student also performed, bringing the total number of tasks to twelve.

Having slain the Nemean Lion and the Lernaean Hydra, the Student is now prepared to [Capture the Ceryneian Hind](https://en.wikipedia.org/wiki/Labours_of_Hercules#Third:_Ceryneian_Hind), a creature so fast it could outrun an arrow...

<p><a href="https://upload.wikimedia.org/wikipedia/commons/thumb/4/42/Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg/800px-Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/42/Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg/800px-Lucas_Cranach_d.%C3%84._-_Herkules_und_die_Hirschkuh_der_Diana_%28Herzog_Anton_Ulrich-Museum%29.jpg" height="480" width="430"></a></p>

## ADTs: Extending the ArrayBag

_Note: This assignment is related to the Exercises 6, 8 and 9 of Chapter 3 found in **Data Abstraction and Problem-Solving with C++**, seventh edition, by Carrano & Henry. See [our disclaimer below](#disclaimer--fair-use-statement)._

This assignment is primarily meant to give the student experience in extending an existing class, i.e., with more experience with the concept of inheritance. Along the way, the student also gains more experience with recursion.

## Objectives

In this assignment you

* override an existing method of the `ArrayBag`
* extend the `ArrayBag` by
  * adding a new method that removes a random entry in the bag
  * adding a new constructor

Upon successful completion of this assignment, the student will implement the following exercises:

* **Exercise 6**: Write a recursive array-based implementation of the method `toVector`
* **Exercise 8**: Specify and define a method for `ArrayBag` that removes a random entry from the bag
* **Exercise 9**: Add a constructor to the class `ArrayBag` that creates a bag from a given array of entries

These three exercises will be tackled by extending the `ArrayBag` into a new class named `ExtendedArrayBag`.

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

As we have seen, inheritance is a form of code reuse. Here, we will reuse much of the code already written in the `ArrayBag`. We will _extend_ this class by overriding one of its inherited methods, writing a new method that isn't a part of the `BagInterface`, and _overloading_ the class constructor.

Consider the class hierarchy we have already, and the modification we'll make to it:

```c++
template <typename ItemType>
class ArrayBag : public BagInterface<ItemType> 
{
private:
   // details omitted for brevity
public:
   ArrayBag( ItemType items[] ); // an overloaded constructor
   // remaining details omitted for brevity
};
```

Next, we'll _extend_ this `ArrayBag` into a new class named `ExtendedArrayBag`:

```c++
template <typename ItemType>
class ExtendedArrayBag : public ArrayBag<ItemType>
{
public:
   bool RemoveRandomEntry( ); // a new extension of the ArrayBag
   std::vector<ItemType> toVector() const override; // an overridden operation
};
```

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

1. Override the `toVector()` operation inherited from `ArrayBag`
2. Extend the `ArrayBag` by adding a new operation that removes a random entry in the bag
3. Overload the `ArrayBag` constructor by providing a new constructor that takes an array of items that is used to create a new `ArrayBag`

Before you begin, be sure you have thoroughly read through the aforementioned [Background Reading](#background-reading).

Additional preliminary steps you may want to take:

1. Take a look around this repository.
   1. Note how the code is organized. Notice that all header files are located in an [include](include) folder and all the implementation files are located in the [src](src) folder.
   2. **Unit tests** are located in yet another folder named [test](test). Please note: Unless told otherwise, **never** modify the contents of this folder. These unit tests are executed to determine the degree to which you have successfully completed your assignment.
2. Study the [CMakeLists.txt](CMakeLists.txt) file. What do you suppose is the purpose of this file? _Don't worry too much if you don't understand this file; we will discuss it and how its used by a program named `cmake`.
3. Jot down anything that you don't understand.

### Part 1: Overriding an existing operation

In Part 1 of this assignment you will override the `toVector` operation inherited from the `ArrayBag` class.

#### Implementation Notes: A new implementation of an existing function

<!-- Be sure to thoroughly comment your code. Use the `javadoc`-style Doxygen comments to provide a brief description of the function, its parameters, return values and pre and post conditions.

After you have modoified this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (the output, where it occurred, has been ommitted for clarity).

```bash
git add include/csc232.h
git commit -m"HW02 - Initial import of Ackermann function."
git push
```

As a final step, log onto GitHub and make sure that your pull request has all your commits. If it doesn't, make a final commit and/or push your last commit to GitHub. Also, make sure that `professordaehn`, `lakshmidivyavaddineni` and `SunandaGuha` are listed as a Reviewers on your pull request. (It may be that only `professordaehn` is listed; if that is the case, manually add the GA usernames too. While you're at it, assign the pull request to yourself.) -->

### Part 2: Extending a class

In Part 2 of this assignment you will _extend_ the `ArrayBag` class by adding a new operation that removes a random entry from the bag.

#### Implementation Notes: Random number generators

TO DO: Discuss generating random numbers in some range (to select a random index in the array for item removal).

### Part 3: Overloading class constructor

In Part 3 of this assignment you will _overload_ the constructor of an existing class (`ArrayBag`).

#### Implementation Notes: Initializing constructors

TO DO: Discuss how to copy the contents of array into newly constructed object.

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
