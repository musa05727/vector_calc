/******** 
 * Filename: vectcalc.c 
 * Author: Musa Abdul Hamid
 * Date: 10/14/26
 * Description: MATLAB-like calculator 
 * note: gcc vectcalc.c vectop.c -o vectcalc
 ******/
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include "vect.h"
#include <stdbool.h>
#include <ctype.h>
vect* vector_array; 
int main(int argc, char* argv[]){ 

    char user_input[150]; 
    char *token_one; 
    char *token_two; 
    char *token_three; 
    char *token_four; 
    char *token_five; 


    if(argc > 1){
        if(strcmp(argv[1], "-h") == 0){
            print_help(); 
        }
    }else{
        vector_array = init_array(); 
        if(vector_array == NULL){
            printf("Memory allocation failed\n"); 
            return 1; 
        }
        while(1){
            printf("minimat> ");  
        

            fgets(user_input, sizeof(user_input), stdin);
            //replaces \n with null terminator 
            user_input[strcspn(user_input, "\n")] = '\0';
            
            
            //if user enters quit, the loop breaks
            if(strcmp(user_input, "quit") == 0)
            {
                free(vector_array); 
                break; 
            
            }
            
            

            token_one = strtok(user_input, " ,"); 
            token_two = strtok(NULL, " ,"); 
            token_three = strtok(NULL, " ,"); 
            token_four = strtok(NULL, " ,"); 
            token_five = strtok(NULL, " ,");
            //if user doesn't enter anything continue 
            if(token_one == NULL){
                continue;
            }

            //if user enters clear, clear the array.
            if(token_one != NULL && strcmp(token_one, "clear") == 0){
                clear_array(); 
            }else if(token_one != NULL && strcmp(token_one, "list") == 0){
                list(); //lists the vectors in the array
            }else if(token_one != NULL && strcmp(token_one, "load") == 0){
                //need to check for incorrect formatted csv
                if(token_two != NULL){
                    load_file(token_two);
                } 
            }else if(token_one != NULL && strcmp(token_one, "save") == 0){
                if(token_two != NULL){
                    save_file(token_two);
                }
            }else if(token_two != NULL && strcmp(token_two, "=") == 0){
                //vector addition
                if(token_four != NULL && strcmp(token_four, "+") == 0){
                int index_vect_one; 
                int index_vect_two; 
                if(token_three != NULL && token_five != NULL){
                    index_vect_one = find_vect_index(token_three[0]); 
                    index_vect_two = find_vect_index(token_five[0]);
                }
                //if vect_one and vect_two exists
                if(index_vect_one != -1 && index_vect_two != -1){
                    vect first = vector_array[index_vect_one];
                
                    vect second = vector_array[index_vect_two];

                    vect result = add(first, second, token_one[0]); 
                    add_vect(result);

                }else{
                    printf("Need two defined vectors for vector addition\n");
                }
                
                //vector subtraction
                }else if(token_four != NULL && strcmp(token_four, "-") == 0){
                    int index_vect_one; 
                    int index_vect_two; 
                    if(token_three != NULL && token_five != NULL){
                        index_vect_one = find_vect_index(token_three[0]); 
                        index_vect_two = find_vect_index(token_five[0]);
                    }
                    //if vector_one and vector_two exists
                    if(index_vect_one != -1 && index_vect_two != -1){
                        vect first = vector_array[index_vect_one];
                    
                        vect second = vector_array[index_vect_two];

                        vect result = sub(first, second, token_one[0]); 
                        add_vect(result);
                    }else{
                        printf("Need two defined vectors for vector subtraction\n");
                    }
                
                //scalar mult
                }else if(token_four != NULL && strcmp(token_four, "*") == 0){
                    //if token_three is a letter
                    if(isalpha(token_three[0])){
                        int index_vect_one = find_vect_index(token_three[0]);
                        if(index_vect_one != -1){
                            double scalar = atof(token_five); 
                            vect first = vector_array[index_vect_one];
                            vect result = smult(first, scalar, token_one[0]); 
                            add_vect(result);
                        }else{
                            printf("Need one defined vector for scalar multiplication\n"); 
                        }
                        
                    }else{
                        int index_vect_one = find_vect_index(token_five[0]);
                        if(index_vect_one != -1){
                            double scalar = atof(token_three); 
                            vect first = vector_array[index_vect_one];
                            vect result = smult(first, scalar, token_one[0]); 
                            add_vect(result);
                        }else{
                            printf("Need one defined vector for scalar multiplication\n"); 
                        }
                        
                    }

                } else {
                    double x = 0 ; 
                    double y = 0;
                    double z = 0; 
                    char *endptr; 
                    bool valid = true; 
                    if(token_three == NULL){
                        valid = false; 
                    }
                    if(token_three != NULL){
                        x = strtod(token_three, &endptr); 
                        if(endptr == token_three || *endptr != '\0'){
                            valid = false; 
                        }
                    }
                    if (token_four != NULL){
                        y = strtod(token_four, &endptr); 
                        if(endptr == token_four || *endptr != '\0'){
                            valid = false; 
                        }
                    }

                    if (token_five != NULL){
                        z = strtod(token_five, &endptr); 
                        if(endptr == token_five || *endptr != '\0'){
                            valid = false; 
                        }
                    }
                    
                    if (strlen(token_one) != 1 ||
                        !isalpha((unsigned char)token_one[0])) {
                        printf("Error: Name must be a single letter.\n");
                    }
                    else if (!valid) {
                        printf("Error: Invalid vector components.\n");
                    }
                    else {
                        vect vector = {
                            .name = token_one[0],
                            .x = x,
                            .y = y,
                            .z = z
                        };

                        add_vect(vector);
                    }
                    

                }
                
            }else if(token_two != NULL && strcmp(token_two, "=") != 0){
                //vect addition without saving to a variable. 
                if(strcmp(token_two, "+") == 0){
                    int index_vect_one = find_vect_index(token_one[0]); 
                    int index_vect_two = find_vect_index(token_three[0]);
                    if(index_vect_one != -1 && index_vect_two != -1){
                        vect first = vector_array[index_vect_one];
                    
                        vect second = vector_array[index_vect_two];

                        vect result = add(first, second, 'r'); 
                        printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z); 
                    }else{
                        printf("Need two defined vectors for addition\n"); 
                    } 

                //vect sub without saving to a variable. 
                }else if(strcmp(token_two, "-") == 0){
                    int index_vect_one = find_vect_index(token_one[0]); 
                    int index_vect_two = find_vect_index(token_three[0]);
                    if(index_vect_one != -1 && index_vect_two != -1){
                        vect first = vector_array[index_vect_one];
                    
                        vect second = vector_array[index_vect_two];

                        vect result = sub(first, second, 'r'); 
                        printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z); 
                    }else{
                        printf("Need two defined vectors for subtraction\n"); 
                    } 
                //scalar mult without saving to a variable. 
                }else if(strcmp(token_two, "*") == 0){
                    //if token_one is a letter
                    if(isalpha(token_one[0])){
                        int index_vect_one = find_vect_index(token_one[0]); 
                        if(index_vect_one != -1){
                            double scalar = atof(token_three); 
                            vect first = vector_array[index_vect_one];
                            vect result = smult(first, scalar, 'r');
                            printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);  
                        }else{
                            printf("Need one defined vector for scalar multiplication\n"); 
                        }

                    }else{
                        int index_vect_one = find_vect_index(token_three[0]); 
                        if(index_vect_one != -1){
                            double scalar = atof(token_one); 
                            vect first = vector_array[index_vect_one];
                            vect result = smult(first, scalar, 'r'); 
                            printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z); 
                        }else{
                            printf("Need one defined vector for scalar multiplication\n"); 
                        }
                    }
                }

            }else{
                if(strlen(token_one) != 1){
                    printf("Vector name must be a single character.\n");
                }else{
                    //finds vect and prints the name of vect and its components
                    find_vect(token_one[0]);
                } 
            }

        }
    }
    
    

    return 0; 

}