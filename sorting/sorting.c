#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int* bubble_sort(int *src,int size){
    int *a = malloc(size * sizeof(int));
    memcpy(a, src, size * sizeof(int));
    for(int i =0;i<size;i++){ // also be written as :: for(int i=size;i>=0;i--)
        for(int j=1;j<size-i;j++){
            if(a[j-1]>a[j]){
                swap(&a[j-1],&a[j]);
            }
        }
    }
    return a;
}

int main(int v,char** c){
    int a[10] = {11,2,33,4,25,6,75,8,49,21};

    printf("\nBubble Sort:\t");
    int* b = bubble_sort(a,10);

    for(int i=0;i<10;i++){
        printf("%d ",b[i]);
    }
}

int* insertion_sort(int *src,int size){
    int *a = malloc(size * sizeof(int));
    memcpy(a, src, size * sizeof(int));
    for(int i = 1;i<size;i++){
        int key = a[i];
        int j= i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    return a;

}

int* selection_sort(int *src,int size){
    int *a = malloc(size * sizeof(int));
    memcpy(a, src, size * sizeof(int));
    for(int i =0;i<size;i++){
        // 1st elment in the iteration as min
        int min = i;
        for(int j = i+1;j<size;j++){
            // search for min from 1st +1 element last
            if(a[j]<a[min]){
                min = j;
            }
        }
        // swap min and 1st position
        swap(&a[min],&a[i]);
    }
    return a;
}


/** 
 * Below is implmentation of merge sort
 * */
void __merge__(int *a,int low,int mid, int high){
    
    int f_index,s_index,t_index;
    f_index = low;
    s_index = mid+1;
    
    int size_tmp = high-low+1;
    int tmp[size_tmp];
    t_index = 0;

    
    
    // copy by order
    while(f_index<=mid && s_index<=high){
        if(a[f_index]>a[s_index]){
            tmp[t_index++] = a[s_index++];
        }else{
            tmp[t_index++] = a[f_index++];
        }
    }
    
    //copy the remaining elements
    if(f_index>mid){
        for(int i=s_index;i<=high;i++){
            tmp[t_index++] = a[i];
        }
    }else{
        for(int i=f_index;i<=mid;i++){
            tmp[t_index++] = a[i];
        }
    }

    t_index = 0;
    for(int i=low;i<=high;i++){
        a[i]=tmp[t_index++];
    }
}

void a_merge_sort(int* a,int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        a_merge_sort(a,low,mid);
        a_merge_sort(a,mid+1,high);
        __merge__(a,low,mid,high);
    }
}

int* merge_sort(int *src,int size){
    //Creating a  copy for array
    int *a = malloc(size * sizeof(int));
    memcpy(a, src, size * sizeof(int));
    
    a_merge_sort(a,0,size-1);
    return a;
}

/**
 * Below is implemnetation of Quick sort
 * */

/* Here i choose a pivot as some mid value and based on that i start movie elments 
to left which are smaller and elments to righ which are bigger than pivot
*/
int partition(int *a,int low,int high,int pivot){
    while(low<=high){
        while(a[low]<pivot){
            low++;
        }
        while(a[high]>pivot){
            high--;
        }
        if(low<=high){
            swap(&a[low],&a[high]);
            low++;
            high--;
        }
    }
    return low;
}

// Here we just invoke quick sort
void a_quick_sort(int *a,int low,int high){
    if(low<high){
        int pivot = a[(low+high)/2];
        int index = partition(a,low,high,pivot);
        a_quick_sort(a,low,index-1);
        a_quick_sort(a,index,high);
    }
}

int* quick_sort(int *src,int size){
    //Creating a  copy for array
    int *a = malloc(size * sizeof(int));
    memcpy(a, src, size * sizeof(int));
    
    a_quick_sort(a,0,size-1);
    return a;
}



// int main(int v,char** c){
//     int a[10] = {11,2,33,4,25,6,75,8,49,21};
//     printf("\nInsertion Sort:\t");
//     int *b = insertion_sort(a,10);
//     for(int i =0;i<10;i++){
//         printf("%d ",b[i]);
//     }
    
//     printf("\nSelection Sort:\t");
//     b = selection_sort(a,10);
//     for(int i =0;i<10;i++){
//         printf("%d ",b[i]);
//     }

//     printf("\nBubble Sort:\t");
//     b = bubble_sort(a,10);
//     for(int i=0;i<10;i++){
//         printf("%d ",b[i]);
//     }

//     printf("\nMerge Sort: \t");
//     b = merge_sort(a,10);
//     for(int i=0;i<10;i++){
//         printf("%d ",b[i]);
//     }

//     int z[6]={40,20,60,30,50,10};
//     printf("\nQuick Sort:\t ");
//     b = quick_sort(z,6);
//     for(int i=0;i<6;i++){
//         printf("%d ",b[i]);
//     }

//     // printf("\nHeap Sort: \t");
//     // b = heap_sort(a,10);
// }