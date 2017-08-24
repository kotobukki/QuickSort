#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUF_SIZE 10
#define MAX_NUMS 20000000
int data[MAX_NUMS];
/*
func QuickSort(arr []int) {
    if len(arr) < 2 {
        return
    }
    rand.Seed(time.Now().Unix())
    pivotIndex := rand.Intn(len(arr))
    pivot := arr[pivotIndex]
    var i, j int = 1, len(arr) - 1
    // fmt.Println(i, j, pivot)
    arr[0], arr[pivotIndex] = arr[pivotIndex], arr[0]
    for i < j {
        for arr[i] < pivot && i < j {
            i++
        }
        for arr[j] >= pivot && i < j {
            j--
        }
        arr[i], arr[j] = arr[j], arr[i]
    }
    if arr[i] >= pivot {
        i--
    }
    arr[0], arr[i] = arr[i], arr[0]
    QuickSort(arr[:i])
    QuickSort(arr[i+1:])
}
*/
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
    // printf("%s\n", file);
    FILE *fp = fopen(file,"r");
    if(fp == NULL){
        perror("file not open");
    }
    while(fgets(buffer,MAX_BUF_SIZE,fp)!=NULL){
        // printf("No.%d:%d\n",i,atoi(buffer));
        arr[i] = atoi(buffer);
        i++;
    }
    fclose(fp);
    return i;
}

int cmp(const void * a,const void * b)  {  
    return (*(int*)a-*(int*)b);//a>b 返回正值  
}  

int main(){
    // printf("%d\n", count);
    for(int i=4;i<=12;i++){
        clock_t start, end;
        double duration;
        char path[50];
        sprintf(path,"./data/linux/unmap_time_%d.data",i);
        int count = readData(data, path);

        start = clock();
        qsort(data,count,sizeof(int),cmp);
        //QuickSort(data, 0, count-1, count);
        end = clock();

        duration = (double)(end - start) / CLOCKS_PER_SEC; 
        printf( "%d data: %f Seconds\n", count, duration);
        // for(int i=0;i<count;i++){
        //     printf("%d\n", data[i]);
        // }
    }
    
    return 0;
}