#include <stdio.h>

void swap(int *n1, int *n2){
   int n = *n1;
   *n1 = *n2;
   *n2 = n;
}

void heapify(int *list, int size){
    int i, parent, left_child, right_child;
    for(i=size-1 ; i>=0 ; i--){
        parent = i;
        again:
        left_child = (parent*2)+1;
        right_child = (parent*2)+2;
        if(left_child > size-1)
            continue;
        if(right_child > size-1){
            if(list[left_child] > list[parent])
                swap(&list[left_child],&list[parent]);
            continue;
        }
        if(list[left_child] > list[right_child] && list[left_child] > list[parent])
            swap(&list[left_child],&list[parent]);
        else if(list[right_child] > list[left_child] && list[right_child] > list[parent])
            swap(&list[right_child],&list[parent]);
        parent = left_child;
        goto again;
    }
}

void delete_heap(int *list, int size){
   int last;
   for(last = --size ; last > 0; last--){
      swap(&list[0],&list[last]);
      heapify(list,last);
   }
}

int main(int argc, char **argv){
   int num;
   printf("Enter number of the numbers in the list: ");
   scanf("%d",&num);
   int numbers[num];
   int i;
   printf("Enter the numbers one by one\n\n");
   for(i=0 ; i<num ; i++){
       printf("Enter number: ");
       scanf("%d",&numbers[i]);
   }
   heapify(numbers,sizeof(numbers)/sizeof(numbers[0]));
   delete_heap(numbers,sizeof(numbers)/sizeof(numbers[0]));
   for(i=0 ; i<num ; i++)
      printf("%d ", numbers[i]);
   printf("\n");
   return 0;
}
