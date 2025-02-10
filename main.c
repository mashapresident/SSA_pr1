#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int choose_array_type();
float* create_1d_array(int size);
float** create_2d_array(int rows, int cols);
void fill_random_values_1d(float* array, int size);
void fill_random_values_2d(float** array, int rows, int cols);
void show_array_1d(float* array, int size);
void show_array_2d(float** array, int rows, int cols);
void find_indexes_1d(float* array, int size);
void find_indexes_2d(float** array, int rows, int cols);


int main() {
    int type = choose_array_type();
    if (type == 0) {
        printf("Invalid choice.\n");
        return 1;
    }
    else if (type == 1) {
        int size;
        printf("Enter the size of the 1D array: ");
        scanf("%d", &size);
        float* arr = create_1d_array(size);
        fill_random_values_1d(arr, size);
        show_array_1d(arr, size);
        find_indexes_1d(arr, size);
        free(arr);
    } else {
        int rows, cols;
        printf("Enter the number of rows and columns for the 2D array: ");
        scanf("%d %d", &rows, &cols);
        
        float** arr = create_2d_array(rows, cols);
        fill_random_values_2d(arr, rows, cols);
        show_array_2d(arr, rows, cols);
        find_indexes_2d(arr, rows, cols);
        
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
    }
    return 0;
}

int choose_array_type() {
    int respond;
    printf("Welcome to the super useful program!\n");
    printf("Now you have to choose the type of array I am going to fill with random float numbers\n");
    printf("1D array or 2D array -> [1/2]: ");
    scanf("%d", &respond);
    
    if (respond != 1 && respond != 2) {
        return 0;
    }
    
    return respond;
}

float* create_1d_array(int size) {
    float* arr = (float*)malloc(size * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  
    }
    return arr;
}

float** create_2d_array(int rows, int cols) {
    float** array = (float**)malloc(rows * sizeof(float*));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  
    }
    for (int i = 0; i < rows; i++) {
        array[i] = (float*)malloc(cols * sizeof(float));
        if (array[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1); 
        }
    }
    return array;
}

void fill_random_values_1d(float* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = (float)rand() / RAND_MAX * 10; 
    }
}

void fill_random_values_2d(float** array, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = (float)rand() / RAND_MAX * 10;  
        }
    }
}

void show_array_1d(float* array, int size){
    printf("1D Array values:\n");
        for (int i = 0; i < size; i++) {
            printf("%.3f ", array[i]);
        }
        printf("\n");
}

void show_array_2d(float** array, int rows, int cols){
    printf("2D Array values:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%.3f ", array[i][j]);
            }
            printf("\n");
        }
}

void find_indexes_1d(float* array, int size){
    float target;
    printf("Enter float number to find out its position -> ");
    scanf("%f", &target);
    int found = 0;
    float epsilon = 0.005; 
    for (int i = 0; i < size; i++) {
        if (fabs(array[i] - target) < epsilon) {
            printf("Found %.3f at index %d\n", target, i);
            found++;
        }
    }
    if (!found) {
        printf("Number %.3f not found in the array.\n", target);
    }
    else{
        printf("Total amount - %d\n", found);
    }
}
void find_indexes_2d(float** array, int rows, int cols){
    float target;
    printf("Enter float number to find out its position -> ");
    scanf("%f", &target);

    int found = 0;
    float epsilon = 0.005;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(array[i][j] - target) < epsilon) { 
                printf("Found %.3f at index (%d, %d)\n", target, i, j);
                found++;
            }
        }
    }
    if (!found) {
        printf("Number %.3f not found in the 2D array.\n", target);
    }
    else{
        printf("Total amount - %d\n", found);
    }
}
