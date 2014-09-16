/*
    Quicksort        
        Main takes a list of comma delimited numbers 
            from a file and calls quicksort() on them,
            passing a pointer to an array of values and
            the length of the array.
            Main should also check the time before and 
            after the algorithm runs for bench testing
        quicksort() should accept an array of numbers and
            it's length, pick a pivot and go to work
            sorting using the following concepts:

            *Choice of pivot should be the median of the
            first, middle and last elements, with the middle 
            found using left + (right-left)/2 to avoid integer
            overflow.

            *quicksort() should divide the array include three
            classes: less than the pivot, equal to the pivot,
            and greater than the pivot, and then call itself 
            on the lowest array followed by calling itself
            on the highest.

        To Do:
            Should parse and sort float data
            Parsing should be done with strtof
            should malloc and realloc arrays as needed
            
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct timespec difftimes(struct timespec start, struct timespec end)
{
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

int pivot(int first, int last){
  //printf("\npivot %i %i\n",last,first);
  int middle = first + (last-first)/2;
  if(first < middle){
    if(first >= last)
      return first;
    else if(first < last)
      return last;
  }
  else{
    if(first < last)
      return first;
    else if(middle >= last)
      return middle;
  }
}

int* quicksort(int * unsorted, int unsorted_length){
  int i=0,l=0,m=0,r=0;
  size_t size = sizeof(int);
  int * sorted = calloc(unsorted_length,size);//trusting unsorted_length to be right.
  int * left = calloc(unsorted_length,size);//trusting unsorted_length to be right.
  int * right = calloc(unsorted_length,size);//trusting unsorted_length to be right.
  //printf("\nquick %i %i\n",unsorted[0],unsorted[unsorted_length-1]);
  int p = pivot(unsorted[0],unsorted[unsorted_length-1]);
  int c = 0; //iterators: forloop,left,middle,right,current value
  for(;i<unsorted_length;i++){
    c = unsorted[i]; //avoid reading into unsorted three times per loop.
    if(c<p){
      left[l]=c;
      l++;
    }
    else if(c>p){
      right[r]=c;
      r++;
    }
    else{//c==pivot
      m++;
    }

  }//ends for loop
  if(l>0)
    left = quicksort(left,l);
  if(r>0)
    right = quicksort(right,r);

  for(i=0;i<l;){
    sorted[i]=left[i];
    i++;
  }
  for(i=l;i<l+m;){
    sorted[i]=p;
    i++;
  }
  for(i=l+m;i<unsorted_length;i++)
    sorted[i]=right[i-(l+m)];
  free(sorted);
  free(left);
  free(right);
return sorted;
}

int main(void) {
  int ul = 1000;//maximum number of entries to sort.
  int* u = malloc(ul*sizeof(int));//unsorted
  int* s = malloc(ul*sizeof(int));//sorted
  int i;
  int c = 0;//iterators: outer loop,inner loop, current random number.

  struct timespec start; // time keeping
  struct timespec end; // time keeping
  struct timespec res;

  srand(time(NULL));
  for(i=0;i<ul;i++){
    u[i]=rand()%100;
    printf(" %i",u[i]);
    if(i%80==0)
      printf("\n");
  }
  printf("\n %i %i %i\n",ul,u[0],u[ul-1]);
  clock_gettime(CLOCK_REALTIME,&start);
  s = quicksort(u,ul);
  clock_gettime(CLOCK_REALTIME,&end);
  res = difftimes(start,end);
  printf("quicksort ran for %lld.%.9ld seconds\n", (long long)res.tv_sec, res.tv_nsec);
  for(i=0;i<ul;i++){
    printf(" %i",s[i]);
    if(i%80==0)
      printf("\n");
  }
  free(u);
  free(s);
  return 0;
}