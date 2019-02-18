#include "max_salary.h"

int best_arr = 0;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int countDigits(int n) 
{ 
    return floor(log10(n)+1); 
}

int add_two(int a, int b){
	int n = a*pow(10,countDigits(b)) + b;
	return n;
}

int concatenate_array(int *arr, int size){
	int num = 0;
	for(int i=0; i<size; i++){
		num = add_two(num, arr[i]);
	}
	return num;
}

// Generating permutation using Heap Algorithm 
void heap_permutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then do something with the obtained permutation   
    if (size == 1) 
    { 
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
	int curr_num = concatenate_array(a, n);
	if(curr_num > best_arr){
		best_arr = curr_num;
	}      
	//printf("%d\n", best_arr);        
	return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a,size-1,n); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		}			
    } 
} 
  
/*Code to test permutations
int main() { 
    int a[] = {17, 9, 173, 3}; 
    int n = sizeof a/sizeof a[0]; 
    heap_permutation(a, n, n); 
    printf("%d\n", best_arr);
    return 0; 
}*/ 
