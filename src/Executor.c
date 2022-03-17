#include <stdio.h>
#include <stdlib.h>

int get_iteration_no(int rand) {
    // upper bound = 100 exclusive
    // lower bound = 50 inclusive
    return ((rand % (100 - 50) + 50));
}


int get_arr_size(int rand) {
    // upper bound = 150 exclusive
    // lower bound = 100 inclusive
    return ((rand % (150 - 100)) + 100);
}


char get_arr_val(int rand) {
    // upper bound = 90 inclusive
    // lower bound = 65 inclusive
    // change value into a char
    int num = ((rand % (91 - 65)) + 65);
    char character = (char)num;
    return character;
}

float ratio(char *arr, int size, int *maxCountPointer) {
    // declare variables to find ratio
    int vowels = 0;
    int consonants = 0;
    float ratios;

    // check each element and see if its a vowel or not
    for(int i = 0; i < size; i++){
        // if its a vowel then increment
        if(arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U'){
            vowels += 1;
        }
        // increment consonats
        else{
            consonants += 1;
        }
        // check which iteration of arrays has more vowels
        if( vowels > *maxCountPointer){
            *maxCountPointer = vowels;
        }
    }
    // return the ratio
    ratios = (float)vowels/(float)consonants;
    return ratios;
}

double get_running_ratio() {
    //initialize variables
    int maxCount = 0;
    int maxIteration = 0;
    float ratio_of_vowels = 0;
    double avg_of_vowels = 0;

    // use rand() to compute #of allocated arrays
    // using get_iteration_no() then print
    int iterate = get_iteration_no(rand());
    printf("[Executor]: Number of iterations is %d\n", iterate);

    char* char_array;
    // use a for loop for steps 3-8
    // at the end of the loop print total number of iterations
    for(int i = 0; i < iterate; i++){
        
        // create an array of size get_arr_size()
        // now malloc() for each array created
        int arr_size = get_arr_size(rand());
        char_array = malloc(arr_size);
 
        // step 4
        // then populate each element using get_arr_val()
        // using a for loop
        for(int j = 0; j < arr_size; j++){
            char_array[j] = get_arr_val(rand());
        }
        
        // step 5
        // make a copy of maxCount then call ratio()
        // pass it array, size of array, and address of maxCount
        int copy_maxCount = maxCount;
        ratio_of_vowels += ratio(char_array, arr_size, &maxCount);

        // step 6
        // if the copy_MaxCount < maxCount
        // then change maxIteration to current iteration
        if(copy_maxCount < maxCount){
            maxIteration = i + 1;
        }
        // free malloc since its done
        free(char_array);
    }
    // step 7
    // obtain average of ratio
    avg_of_vowels = ratio_of_vowels / iterate;

    // step 8 print maxIteration number with maxCount
    // return ratio to Starter.c
    printf("[Executor]: Iteration with maximum vowel count is %d\n", maxIteration);
    return avg_of_vowels;    
}