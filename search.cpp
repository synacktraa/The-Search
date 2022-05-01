#include<iostream>

using namespace std;

class Search{

public:
    
    // Best Case Time Complexity: O(1)
    // Worst Case Time Complexity: O(n)
    int Linear(int* array, int element, size_t size){

        int idx = 0;
        while(idx < size){
            if(array[idx] == element)
                return idx;
            idx++;
        }
        return -1;
    }

    // Average Case Time Complexity: O(log(n))
    // Worst Case Time Complexity: O(n)
    int Binary(int* array, int element, size_t size){

        int low = 0, high = size-1, mid;

        while(low <= high){
            mid = (low+high)/2;
            if(element == array[mid])
                return mid;
            else if (element < array[mid])
                high = --mid;
            else 
                low = ++mid;
        }
        return -1;
    }

    // Average Case Time Complexity: O(log(log(n)))
    // Worst Case Time Complexity: O(n) [values increase exponentially] 
    int Interpolation(int* array, int element, size_t size) {

        int low = 0, high = size-1, mid, probe;

        while(element >=array[low] && element <= array[high] && low <= high){
            probe = low + (high-low) * (element-array[low]) / (array[high]-array[low]);
            cout << "probe: " << probe << endl;
            if(element == array[probe])
                return probe;
            else if (element < array[probe])
                high = --probe;
            else 
                low = ++probe;
        }
        return -1;
    }
};
