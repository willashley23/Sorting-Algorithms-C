/**
*	@file Sorts.h
* @author Will Ashley
*	@date 2015.10.28
*	@Description:This contains all the sorting methods, a timer, a shuffler, and a function to create the user array. 
*	*/


#ifndef SORTS_H
#define SORTS_H
#include <random>
#include <chrono>
#include <ctime>
#include <iostream>
#include <cassert>
#include <functional>
#include "Test.h"

template <typename T>
class Sorts

{

  public:


    //@pre array created
    //@post uses buble sort to sort the array
    static void bubbleSort(T arr[], int size);

    //@pre array created
    //@post uses bogo sort to sort the array
    static void bogoSort(T arr[], int size);

    //@pre array created
    //@post uses insertion sort to sort the array
    static void insertionSort(T arr[], int size);

    //@pre array created
    //@post uses selection sort to sort the array
    static void selectionSort(T arr[], int size);

    //@array created
    //determines if the array is sorted
    static bool isSorted(T arr[], int size);

    //@pre none
    //@post shuffles random integers 
    static void shuffle(T arr[], int size, std::default_random_engine& generator);

    //@pre none
    //@post creates the user array
    static int* createTestArray(int size, int min, int max);

    //@none
    //@post calculates the time taken to sort by each method
    static double sortTimer(std::function<void(T[],int)>sort, T arr[], int size);
 

};
#include "Sorts.hpp"
#endif


