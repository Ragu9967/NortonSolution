Problem statement : get the data provided in stdin and store it in a file.

Here, i have read the input in blocks. Fixed buffer length has been initialized to 1024. 
So when we give the data via stdin, the program reads first n characters, say 1024 and store 
it in a file and read the next 1024 characters and store it in the file and 
the process continues till the program detects EOF signal.


The data is stored as a binary to support unicode characters.
Each write operation is checked if it is successful. If not then probably the user doesnt have enough space to write the data and the program ends.
During the first write operation, the file is created and the data is dumped into the file. From the next write operation, the data will 
just gets appended int the same file.

UPDATED CODE - 28/08/2020 (following are the changed made)
I have modified the code in a user friendly manner as we discussed.
Now at the start of the program, It asks for the user input to do one of the following operations:
1. Enter 0 to exit the program
2. Enter 1 to provide a file as a input (once this option is chosed, then it asks for 
a valid file name. It checks if the file is valid and reads the data from the file and 
dumps it in the output file. It accepts a bin file/text file/unicode text file/image file as input)
3. Enter any other key to get the input via console.

UPDATED CODE - 31/08/2020 (following are the changed made)
Moved the global variable fileName to define
So the program gets a input from the user, 
If its a stdin, then it calls a function,
Else if its a file input, it calls another function.

Both of them does pretty much the same operation, so i have made the changes so that both of the above cases calls the same funtion which takes
a FILE pointer argument. So now if argument is a stdin pointer it reads from console else from the file pointer pointing to a validated file.
