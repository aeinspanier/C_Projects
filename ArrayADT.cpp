#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){

    printf("elements are\n");
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);

}

void Append(struct Array *arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int idx, int x){
    if(idx>=0 && idx<=arr->length){
        for(int i=arr->length;i>idx;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[idx] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int idx){
    int x=0;
    
    if(idx>=0 && idx<=arr->length){
        x=arr->A[idx];

        for(int i=idx;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return x;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y=temp;
}

int LinearSearch(struct Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h){
        mid = (l+h)/2;
        if(key==a[mid]){
            return mid;
        }else if(key<a[mid]){
            return RBinSearch(a,l,mid-1,key);
        }else{
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int Get(struct Array arr, int idx){
    if(idx >= 0 && idx<arr.length){
        return arr.A[idx];
    }
    return -1;
}

void Set(struct Array *arr, int idx, int key){
    if(idx>=0 && idx<arr->length){
        arr->A[idx]=key;
    }
}

int Max(struct Array arr){
    int max=arr.A[0];

    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}


int Min(struct Array arr){
    int min=arr.A[0];

    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum=0;

    for(int i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

int main(){

    //Initialize Array
    struct Array arr={{2,3,14,4,5,6}, 10, 5};
    printf("%f\n", Avg(arr));
    //Set(&arr, 0, 15);
    Display(arr);

}
