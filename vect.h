/******** 
 * Filename: vectop.h
 * Author: Musa Abdul Hamid
 * Date: 10/14/26
 * Description: declaration of all function helpers.
 * note: gcc vectcalc.c vectop.c -o vectcalc
 ******/
typedef struct vect{
    char name; 
    double x; 
    double y; 
    double z; 
} vect; 


extern vect vector_array[10]; 

//vector operations
vect add(vect a, vect b, char name); 
vect sub(vect a, vect b, char name); 
vect smult(vect a, double scalar, char name); 

//add vect to vector_array
void add_vect(vect vector); 

int find_vect_index(char name); 
void find_vect(char name);
void clear_array(); 
void list(); 
void print_help(void); 