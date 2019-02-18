#include "max_salary.h"

int min(int num1, int num2){
	if (num1 >= num2) {
		return num2;
	}
	else{
		return num1;
	}
}

int countDigits(int n) 
{
	if(n == 0){
		return 1;
	}
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

int is_better(int num1, int num2){
	int dig1 = countDigits(num1);
	int dig2 = countDigits(num2);
	int digits = min(dig1, dig2);
	if(num1 == num2){
		return 0;
	}
	for(int i=0; i<digits; i++){
		int a = (int)(pow(10,dig1-1-i)+0.5);
		int b = (int)(pow(10,dig2-1-i)+0.5);//Works regardless of compiler, could cause error otherwise
		if(num1/a > num2/b){
			return 0;
		}
		if(num1/a < num2/b){
			return 1;
		}
	}//After this the first n digits will be equal. so I compare the next digit of the longest number to the first digit of the short one to know which one should be first.
	if (dig1 > dig2){
		num1 = num1-(num2*pow(10, dig1-dig2));
		dig1 = countDigits(num1);
	}
	else{
		num2 = num2-(num1*pow(10, dig2-dig1));
		dig2 = countDigits(num2);
	}
	is_better(num1, num2);
}


int greedy(int array[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(!is_better(array[i],array[j])){
				SWAP(array[i],array[j]);
			}
		}
	}
	int best_arr = concatenate_array(array, size);
	return best_arr;
}





/*Code to test permutations
int main() { 
    int a[] = {17, 9, 173, 3}; 
    int n = sizeof a/sizeof a[0]; 
    int result = greedy(a, n); 
    printf("%d\n", result);
    return 0; 
}*/
