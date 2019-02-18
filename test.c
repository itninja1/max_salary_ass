#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_salary.h"
#include "max_salary_greedy.c"

void short_test (int size){
	int numbers[size];        
	printf("Enter the numbers \n");
	printf("The total number of digits should be less than or equal to 9 \n");
	for (int i = 0; i < size; i++){
	        scanf("%d", &numbers[i]);
	}
	best_arr = 0;
	heap_permutation(numbers, size, size);
	int result2 = greedy(numbers, size);
	printf("Maximum Number: result1=%d, result2=%d\n", best_arr, result2);
	if(best_arr == result2){
		printf("Good, the two algorithms return the same value\n");
	}else{
		printf("Wrong, the two algorithms return different values\n");
	}
}

void stress_test(int length){
  srand(time(NULL));   // Initialization, should only be called once.
  int max_num = (int)(pow(10, 9/length)+0.5);
  while (1) {
    int *a = malloc(length*sizeof(int));
    for (int i=0; i<length; i++){
          a[i] = 1+rand()%(max_num-1);   //Because the integer has a limited size and only positive  
    }
	  
    print_array(a, length);
    best_arr = 0;
    heap_permutation(a, length, length);
    int result2 = greedy(a, length);
    
    if (best_arr==result2){
      	printf("OK\n");
    }else {
      	printf("Wrong answer: correct=%d, got instead=%d\n", best_arr, result2);
	exit(0);
    }
    free(a);
  }  
}

int main(int argc, char **argv ){
  if (argc < 3){
    printf("To run: test <1> <lenght of array>\n or test <2> <length of array>\n");
    return 0;
   }
   
   int mode = atoi(argv[1]);
   
   if (mode == 1){
	   if (argc < 3){
			printf("To run: test <1> <lenght>\n");
			return 0;
	   }
	   int length = atoi(argv[2]);
	   short_test(length);
	   return 0;
   }
   
   int size = atoi(argv[2]);
   if(size>=10){
	printf("Please use a size of maximum 9");
	return 0;
   }
   stress_test(size);
   
   return 0;
  
}
