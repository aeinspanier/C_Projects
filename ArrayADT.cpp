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

int main(){

    //Initialize Array
    struct Array arr={{2,3,4,5,6}, 10, 5};
    printf("%d\n",Delete(&arr,4));
    Display(arr);

}
