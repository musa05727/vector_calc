/******** 
 * Filename: vectop.c 
 * Author: Musa Abdul Hamid
 * Date: 10/14/26
 * Description: definition of all function helpers.
 * note: gcc vectcalc.c vectop.c -o vectcalc
 ******/
#include "vect.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#define ARRAY_LENGTH 10

vect vector_array[10] = {};
static int add_index = 0; 



vect add(vect a, vect b, char name){
    vect return_vector; 
    return_vector.name = name; 
    return_vector.x = a.x + b.x;
    return_vector.y = a.y + b.y; 
    return_vector.z = a.z + b.z; 

    return return_vector; 
}

vect sub(vect a, vect b, char name){
    vect return_vector; 
    return_vector.name = name; 
    return_vector.x = a.x - b.x;
    return_vector.y = a.y - b.y; 
    return_vector.z = a.z - b.z; 

    return return_vector; 
}

vect smult(vect a, double scalar, char name){
    vect return_vector; 
    return_vector.name = name; 
    return_vector.x = a.x * scalar; 
    return_vector.y = a.y * scalar; 
    return_vector.z = a.z * scalar; 

    return return_vector; 
}

void add_vect(vect vector){ 
    

    int index = find_vect_index(vector.name); 

    if (index != -1) {
        // Vector already exists
        vector_array[index] = vector;
        printf("%c = %.2f %.2f %.2f\n", vector_array[index].name, 
            vector_array[index].x, vector_array[index].y, vector_array[index].z); 
    }
    else if (add_index < ARRAY_LENGTH) {
        // New vector
        vector_array[add_index] = vector;
        printf("%c = %.2f %.2f %.2f\n", vector_array[add_index].name, 
            vector_array[add_index].x, vector_array[add_index].y, vector_array[add_index].z); 
        add_index++;
    }
    else {
        printf("No more room in array\n");
    }

 

}

int find_vect_index(char name){ 
    int index = -1; 
    for(int i = 0; i< ARRAY_LENGTH; i++){
        //vector found 
        if(vector_array[i].name == name){
            index = i; 
            break; 
        }
    }
    return index; 
}

void find_vect(char name){
    int index = -1; 
    for(int i = 0; i< ARRAY_LENGTH; i++){ 
        //vector found 
        if(vector_array[i].name == name){
            index = i; 
            break; 
        }
    }
    if(index != -1){
        printf("%c = %.2f %.2f %.2f\n", vector_array[index].name, 
            vector_array[index].x, vector_array[index].y,
            vector_array[index].z); 
    }else{
        printf("Error: Vector %c does not exist.\n", name); 
    }

}
void clear_array(){
    for(int i = 0; i<ARRAY_LENGTH; i++){
        vector_array[i].name = '\0'; 
        vector_array[i].x = 0; 
        vector_array[i].y = 0;
        vector_array[i].z = 0;
    }
    add_index = 0; 
}
void print_help(void) {
    printf("MiniMat - Vector Calculator\n");
    printf("Supports 3D vectors (maximum 10).\n\n");

    printf("Commands:\n");
    printf("\tquit\t\tExit program\n");
    printf("\tclear\t\tDelete all vectors\n");
    printf("\tlist\t\tDisplay stored vectors\n\n");

    printf("Operations:\n");
    printf("\ta = 1 2 3\tCreate/update vector\n");
    printf("\ta\t\tDisplay vector\n");
    printf("\ta + b\t\tVector addition\n");
    printf("\ta - b\t\tVector subtraction\n");
    printf("\ta * 2\t\tScalar multiplication\n");
    printf("\t2 * a\t\tScalar multiplication\n");
    printf("\tc = a + b\tStore operation result\n\n");

    printf("Notes:\n");
    printf("\tSeparate components with spaces or commas.\n");
    printf("\tUse spaces around operators.\n");
    printf("\tDecimal and negative values are supported.\n");
}

void list(){
    for(int i = 0; i<ARRAY_LENGTH; i++){
        if(vector_array[i].name != '\0'){
            printf("%c = %.2f %.2f %.2f\n", vector_array[i].name, 
            vector_array[i].x, vector_array[i].y,
            vector_array[i].z); 
        }else{
            break; 
        }
    }
}




