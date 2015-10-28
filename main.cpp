
/**
*	@file main.cpp
* @author Will Ashley
*	@date 2015.10.28
*	@Description:main is the driver of the program. It prints a menu, records and stores user input, and outputs the sorted arrays
*	if necessitated by the user. 
*	*/


#include <iostream>
#include "Sorts.h"
#include "Test.h"


void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
      << "5) Run Tests\n"
			<< "Enter choice: ";
}

void printArray(int* arr, int size)

{

  std::string choice;
  std::cout<<"Do you want to print the unsorted array? (y/n): ";
  std::cin>>choice;
  if(choice=="y")
  {
  std::cout<<"Here is the unsorted array: ";  
  std::cout<<"[";
  for(int i=0; i<size; i++)
	{
		std::cout<<arr[i]<< " " ;
	}
  std::cout<<"]";
  }
}

void printSortedArray(int* arr, int size)
{

  std::string choice;
  std::cout<<"Do you want to print the sorted array? (y/n): ";
  std::cin>>choice;
  if(choice=="y")
  {
  std::cout<<"Here is the sorted array: ";  
  std::cout<<"[";
  for(int i=0; i<size; i++)
	{
		std::cout<<arr[i]<< " " ;
	}
  std::cout<<"]";
  }

}

int main()
{


int choice;
int items;
int max;
int min;
int time;
Test myTester(std::cout); 

while(choice!=0)
{

  printMenu();
  std::cin>>choice;

  if(choice==1)
  {
  
    std::cout<<"How many items do you want to sort?";
    std::cin>>items;
    std::cout<<"What is the max random value?";
    std::cin>>max;
    std::cout<<"What is the min random value?";
    std::cin>>min;
    int* UserArray = Sorts<int>::createTestArray(items, min, max);
    printArray(UserArray, items);
    std::cout<<"\nSorting with bubble Sort...";
    time=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, UserArray, items);
    printSortedArray(UserArray, items);    
  }
  
  else if(choice==2)
  {
    std::cout<<"How many items do you want to sort?";
    std::cin>>items;
    std::cout<<"What is the max random value?";
    std::cin>>max;
    std::cout<<"What is the min random value?";
    std::cin>>min;
    int* UserArray = Sorts<int>::createTestArray(items, min, max);
    printArray(UserArray, items);
    std::cout<<"\nSorting with Insertion Sort...";
    time=Sorts<int>::sortTimer(Sorts<int>::insertionSort, UserArray, items);
    printSortedArray(UserArray, items);
    
  }


  else if(choice==3)
  {
    std::cout<<"How many items do you want to sort?";
    std::cin>>items;
    std::cout<<"What is the max random value?";
    std::cin>>max;
    std::cout<<"What is the min random value?";
    std::cin>>min;
    int* UserArray = Sorts<int>::createTestArray(items, min, max);
    printArray(UserArray, items);
    Sorts<int>::selectionSort(UserArray, items);
    std::cout<<"\nSorting with selection Sort...";
    time=Sorts<int>::sortTimer(Sorts<int>::selectionSort, UserArray, items);
    printSortedArray(UserArray, items);
    

  }


  else if(choice==4)
  {
    std::cout<<"How many items do you want to sort?";
    std::cin>>items;
    std::cout<<"What is the max random value?";
    std::cin>>max;
    std::cout<<"What is the min random value?";
    std::cin>>min;
    int* UserArray = Sorts<int>::createTestArray(items, min, max);
    printArray(UserArray, items);
    Sorts<int>::bogoSort(UserArray, items);
    std::cout<<"\nSorting with bogo Sort...";
    printSortedArray(UserArray, items);
    

  }

  else if(choice==5)
  {
    myTester.runTests();
  }

  else if(choice==0)
  {
  std::cout<<"Thanks.";
  }

  else
  {
    std::cout<<"please enter a value bb";
  }
  


}



return(0);
}
