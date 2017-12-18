#include <iostream>
using namespace std;

void merge(int *arr, int lo, int mid, int hi){
	int *A = arr+lo;
	int lb = mid- lo; int *B = new int[lb];
	// copy A to B
	int i = 0;
	for(i; i<lb; i++)
		A[i] = B[i];
	int lc = hi - mid; int *C = arr + mid;
	int r=0, j=0, k=0;
	for(r,j,k;(j<lb) || (k<lc);){
		if( (j<lb) && ((k>=lc) || (B[j]<=C[k])) ) A[r++] = B[j++];
		if( (k<lc) && ((j>=lb) || (C[k]<=B[j])) ) A[r++] = B[j++];
	}
	delete[] B;
}

void mergeSort(int *arr, int lo, int hi){
	if((hi-lo)<2) return;
	int mid = (hi+lo)>>1;
	mergeSort(arr, lo, mid);
	mergeSort(arr+mid, mid, hi);
	merge(arr, lo, mid, hi);
}

/*
match string by force
version 1
*/
int matchByForceV1(char *P, char *T){
	size_t n = strlen(T), i = 0;
	size_t m = strlen(P), j = 0;
	while(i < n && j < m){
		if(T[i] == P[j]) {i++; j++;}
		else {i = i-j+1; j = 0;}
	}

	return i - j;
}

/*
match string by force
version 2
*/

int matchByForceV2(char *P, char *T){
	size_t n = strlen(T), i = 0;
	size_t m = strlen(P), j = 0;

	for(i; i < n-m+1; i++){
		for(j; j<m; j++){
			if(P[j] != T[i]) break;
		}
		if(m <= j) break;
	}

	return i;
}

int * buildNext(char *P){
	size_t m = strlen(P), j = 0;
	int *N = new int[m];
	int t = N[0] = -1;
	while(j < m-1){
		if(0 > t || P[j] == P[t]){
			t++; j++;
			N[j] = P[j] != P[t] ? t : N[t];
		} else{
			t = N[t];
		}
	}
	return N;
}

int matchByKMP(char *P, char *T){
	int *next = buildNext(P);
	size_t n = strlen(T), i = 0;
	size_t m = strlen(P), j = 0;
	while(i < n && j < m){
		if(0 > j || T[i] == P[j]) {i++; j++;}
		else{
			j = next[j];
		}
	}
	delete[] next;
	return i - j;
}

void reverse(char *str){
	char *end = str;
	char tmp;
	if(str){
		while(*end)
			++end;
	}
	--end;
	while(str < end){
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
	
}


int main(int argc, char const *argv[])
{
	int arr[] = {2,3,6,1,0,8};
	mergeSort(arr, 0, 6);
	// int i=0;
	// for (i; i < 6; ++i)
	// {
	// 	cout<<arr[i]<<endl;
	// }
	return 0;
}









