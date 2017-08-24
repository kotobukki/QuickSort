#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUF_SIZE 10
#define MAX_NUMS 20000000
int data[MAX_NUMS];

void swap(int* arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void QuickSort(int* arr, int start, int end, int n){
    if(n < 2){
        return;
    }
    srand(time(0));
    int pivotIndex = start+rand()%n;
    int pivot = arr[pivotIndex];
    int i = start+1;
    int j = end;
    swap(arr,start,pivotIndex);
    while(i<j){
        while(arr[i] < pivot && i<j) i++;
        while(arr[j] >= pivot && i<j) j--;
        swap(arr,i,j);
    }
    if(arr[i] >= pivot){i--;}
    swap(arr,start,i);
    QuickSort(arr,start, i-1, i-start);
    QuickSort(arr, i+1, end, end-i);
}


int readData(int * arr, char *file){
    char buffer[MAX_BUF_SIZE];
    int i = 0;
    FILE *fp = fopen(file,"r");
    if(fp == NULL){
        perror("file not open");
    }
    while(fgets(buffer,MAX_BUF_SIZE,fp)!=NULL){
        arr[i] = atoi(buffer);
        i++;
    }
    fclose(fp);
    return i;
}

int cmp(const void * a,const void * b)  {  
    return (*(int*)a-*(int*)b); 
}  

int main(){
    for(int i=4;i<=12;i++){
        clock_t start, end;
        double duration;
        char path[50];
        int count = readData(data, path);
        start = clock();
        qsort(data,count,sizeof(int),cmp);
        end = clock();

        duration = (double)(end - start) / CLOCKS_PER_SEC; 
        printf( "%d data: %f Seconds\n", count, duration);

    }
    
    return 0;
}
