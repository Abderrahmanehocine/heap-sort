#include <stdio.h>

void swap(int *n1, int *n2){
   int n = *n1;
   *n1 = *n2;
   *n2 = n;
}

void create_heap(int *list, int size){
   int index, parent, child;
   for(index=1 ; index<size ; index++){
      child = index;
      while(1){
         parent = (index%2 == 0)? (index/2)-1 : index/2;
         check:
         if(list[parent] < list[child])
            swap(&list[parent],&list[child]);
         else 
            break;
         if(parent == 0)
            break;
         child = parent;
         parent = (parent%2 == 0)? (parent/2)-1 : parent/2;
         goto check;
      }
   }
}

void delete_heap(int *list, int size){
   int last;
   for(last = --size ; last > 0; last--){
      swap(&list[0],&list[last]);
      create_heap(list,last);
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
   create_heap(numbers,sizeof(numbers)/sizeof(numbers[0]));
   delete_heap(numbers,sizeof(numbers)/sizeof(numbers[0]));
   for(i=0 ; i<num ; i++)
      printf("%d ", numbers[i]);
   printf("\n");
   return 0;
}
