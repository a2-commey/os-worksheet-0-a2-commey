#include <stdio.h>      // for printf, FILE, fopen etc.
#include <string.h>     // for memcpy (used in swap)

// Task 1.3 — compare two arrays
int arrays_equal(int *a, int *b, int length) {
    if (a == NULL || b == NULL) return 0;        // make sure pointers are valid
    for (int i = 0; i < length; i++) {           // loop through each element
        if (a[i] != b[i]) return 0;              // if one pair differs, arrays are not equal
    }
    return 1;                                    // all values matched
}

// Task 3 — swap two values of any type
void swap(void *x, void *y, size_t size) {
    char temp[size];                             // temporary storage for a value
    memcpy(temp, x, size);                        // save x into temp
    memcpy(x, y, size);                           // copy y into x
    memcpy(y, temp, size);                        // copy saved x into y
}

// Task 4 — print a 2D array using pointer arithmetic
void print_array(int *arr, int width, int height) {
    printf("Task 4 output:\n");
    for (int r = 0; r < height; r++) {            // go through each row
        for (int c = 0; c < width; c++) {         // go through each column
            printf("%d ", *(arr + r * width + c)); // compute index manually using pointer math
        }
        printf("\n");                             // move to next row
    }
    printf("\n");
}

int main(void) {

    // Task 1.1 — pointer to a variable
    int n = 5;                                    // create a number
    int *ptr_to_n = &n;                           // pointer holds address of n
    (*ptr_to_n)++;                                // change n through the pointer
    printf("Task 1.1 → n = %d\n\n", n);           // print updated value


    // Task 1.2 — pointer to an array
    int arr[3] = {10, 30, 2000};                  // array of 3 integers
    int *p = arr;                                 // pointer to first element

    printf("Task 1.2 → array values:\n");
    for (int i = 0; i < 3; i++) {                 // loop over array
        printf("Value: %d, Address: %p\n",
               *(p + i),                          // get array value using pointer math
               (p + i));                          // print its memory address
    }
    printf("\n");


    // Task 1.3 — compare arrays
    int x[] = {1, 2, 3};                          // identical arrays
    int y[] = {1, 2, 3};
    int z[] = {1, 2, 4};                          // slightly different array

    printf("Task 1.3 → x vs y: %d\n", arrays_equal(x, y, 3)); // should be 1 (true)
    printf("Task 1.3 → x vs z: %d\n\n", arrays_equal(x, z, 3)); // should be 0 (false)


    // Task 2 — read numbers from a file and sum them
    FILE *file = fopen("foo.txt", "r");           // try opening foo.txt for reading
    if (!file) {                                  // check if file opened correctly
        printf("Error opening foo.txt\n");        // error message
        return 1;                                 // stop program
    }

    int num, sum = 0;                             // num stores each read number
    while (fscanf(file, "%d", &num) != EOF) {     // read until no more numbers
        sum += num;                               // add number to sum
    }
    fclose(file);                                 // close the file when done

    printf("Task 2 → sum = %d\n\n", sum);         // print final result


    // Task 3 — test the swap function
    int a = 10, b = 20;                           // two numbers to swap

    printf("Task 3 → before swap: a=%d, b=%d\n", a, b);
    swap(&a, &b, sizeof(int));                    // swap using our generic function
    printf("Task 3 → after  swap: a=%d, b=%d\n\n", a, b);


    // Task 4 — print a 2D array using pointer arithmetic
    int two_d[2][3] = {                           // 2 rows, 3 columns
        {1, 2, 3},
        {4, 5, 6}
    };

    print_array((int*)two_d, 3, 2);               // treat 2D array as 1D pointer


    // Task 5 
    return 0;                            
}
