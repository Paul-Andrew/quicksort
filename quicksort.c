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
*/

include 



int main(void) {
    int random = malloc(sizeof(int));
    int random_length = 1;
    int sorted = malloc(sizeof(int));
    int random_length = 1;
    float time;
    FILE *file;
    char letter;
//load file
    file - fopen("data.txt", "r");//data should be a single line of 
//read file into array
    while (EOF != fscanf(file, "%i",letter)){
        random_length++;
        realloc(random,sizeof(int)*(random_length));
        random[random_lenght] = letter
    }
    fclose(file);
//time in
    
//call quicksort
    sorted = quicksort(random,random_length);//needs to pass a pointer, not an array
//time out
//print result
    printf("Results:\n");
    for(i=0;i < sizeof(sorted);){
        for(j=0;j<5;j++){
            printf(" %i,",sorted[i]);
            i++;
        }
        printf("\n");
    }
    printf("Ran for: %f seconds.\n",time);

    free(random);
    free(sorted);
    return 0;
}


int[] quicksort(int unsorted int unsorted_length){//needs a pointer to return
    int less = malloc(sizeof(int));
    int less_length = 1;
    int more = malloc(sizeof(int));
    int more_length = 1;
    int equal = malloc(sizeof(int));
    int equal=length = 1;
    int sorted = malloc(sizeof(int));
    int sorted_length = 1;
    int sorted_less = malloc(sizeof(int));
    int 
    int sorted_more = malloc(sizeof(int));
    int center;
    int sorted_size;
    int c;
    p = pivot(unsorted[0],unsorted[unsorted_length - 1]);
    center = unsorted[p];
    for(i=0; i < unsorted_length; i++){
        if(unsorted[i] > center){
            less_length++;
            realloc(less,sizeof(int)*less_length);
            less[less_length] = unsorted[i];
        }
        else if(unsorted[i] == center){
            equal_length++;
            realloc(equal,sizeof(int)*equal_length);
            equal[equal_length] = unsorted[i];
            e++;
        }else {
            more_length++;
            realloc(more,sizeof(int)*more_length);
            more[more_length] = unsorted[i];
        }
    }
    sorted_less = quicksort(less, less_length);//should pass pointer, not array 
    sorted_more = quicksort(more, more_length);

    for(i=0;i < sizeof(sorted_less);i++){
        sorted[i]=sorted_less[i];
        c=i;
    }
    for(i=c; i < (sizeof(equal)+c);i++){
        sorted(i) = equal[i-c];
    }
    for(i=0;i < sizeof(sorted_more);i++){
        sorted[c+i]=sorted_more[i];
    }
    sorted_size = sizeof(sorted)

    free(less);
    free(more);
    free(equal);
    free(sorted);
    free(sorted_more);
    free(sorted_less);
return sorted_size;
}

int pivot(int first int last){
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
