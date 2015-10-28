/**
*	@file Sorts.hpp
* @author Will Ashley
*	@date 2015.10.28
*	@Description:This contains all the sorting methods, a timer, a shuffler, and a function to create the user array. 
*	*/


template<typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{

  for(int i=0; i<size-1; i++)
  {
    if(arr[i]>arr[i+1])
      return(false);
  }

return(true);

}

//SORT TIMER
template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
  //Declarations-------------------------------
std::chrono::system_clock::time_point start;
std::chrono::system_clock::time_point end;
std::chrono::duration<double> elapsed;


//Timing something-------------------------
start = std::chrono::system_clock::now();

sort(arr,size);

end = std::chrono::system_clock::now();
elapsed = (end - start);
std::cout << "\n" << size << " numbers were sorted in "<< elapsed.count() << " seconds\n";
}

//SHUFFLE 
template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{	
	int temparr;
	int temp;

	std::uniform_int_distribution<int> distribution(0, size-1);

	for(int i=0;i<size;i++)
	{
		temp=distribution(generator);
		arr[i]=arr[temp];
		arr[temparr]=temp;
	} 		
		
}


//INSERTION
template<typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{

int a;

	for(int i = 1; i < size; i++)
	{
		a=i;
		while(a>0 && arr[a-1]>arr[a])
		{
			int tempArr=arr[a];
			arr[a]=arr[a-1];
			arr[a-1]=tempArr;
			a--;
		}
	}   
  


assert( Sorts<T>::isSorted(arr, size) );



}


//BOGO
template<typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{

 std::default_random_engine generator;
	
	while(!isSorted(arr, size)) 
		  shuffle(arr, size, generator); 	
  
	assert(Sorts<T>::isSorted(arr, size));

}


//SELECTION
template<typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{

for(int i=0;i<size-1;i++)
	{
		int smallest=arr[i];
		int subIndex=i;  
		
		for(int j=i;j<size-1;j++)
		{


			if(j!=size-1)
			{

				if(arr[j+1]<smallest)
				{
					  smallest=arr[j+1];
				  	subIndex=j+1;
				}
			}
		}
		
		arr[subIndex]=arr[i];
		arr[i]=smallest;


		}
	assert(Sorts<T>::isSorted(arr, size));


}



//BUBBLE 
template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{

  std::string choice;
  
  while(!isSorted(arr,size)){
 
    for(int i=0;i<size-1;i++)
    {
    	if(arr[i]>arr[i+1])
    	{
	    	int temp=arr[i];
	    	arr[i]=arr[i+1];
	    	arr[i+1]=temp;
    	}

    }
  }


assert( Sorts<T>::isSorted(arr, size) );

  

}


template<typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{

    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min,max);

    int* userArray = new int[size];
    for(int i=0; i<size-1; i++)
    {
      userArray[i]=distribution(generator);
    }

    return(userArray);
}








