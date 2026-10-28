# MiniMat - Vector Calculator
MiniMat is a 3D vector calculator that allows users to create, store, and manipulate vectors. It supports vector addition, subtraction, scalar multiplication, and loading and saving vectors to files.
# How to Compile and Run the Program 
Run 'make' to compile the program.<br>
./vectcalc to run start the program.

# Supported Commands and Operations 
 Command-line:<br> 
        1. -h    -- Displays information on how to use the program <br>
        
 Commands: <br>
        1. quit  -- Exit program <br>
        2. clear -- Delete all vectors <br>
        3. list  -- Display stored vectors <br>
        4. load  -- Load vectors from a file <br>
        5. save  -- Save vectors to a file <br>
        
 Operations: <br> 
        1. a = 1 2 3   -- Create/update vector <br>
        2. a           -- Display vector <br>
        3. a + b       --  Vector addition <br> 
        4. a - b       -- Vector subtraction <br> 
        5. a * 2       -- Scalar multiplication <br> 
        6. 2 * a       -- Scalar multiplication <br> 
        7. c = a + b   -- Store operation result <br> 

 Notes: <br> 
        Separate components with spaces or commas. <br> 
        Use spaces around operators. <br> 
        Decimal and negative values are supported <br> 
# Dynamic Memory
This program uses an array that is dynamically allocated using malloc. When the array becomes full, realloc is used to increase its capacity. When the user uses the quit or clear command, free() is used to release the allocated memory. 
