#include<iostream>

using namespace std;

class Search{

public:
    
    int 
    linear(int* array, int element, size_t size){

        int idx = 0;
        while(idx < size){
            if(array[idx] == element)
                return idx;
            idx++;
        }
        return -1;
    }

    int 
    binary(int* array, int element, size_t size){

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
};
