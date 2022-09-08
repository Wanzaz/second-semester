/*
Files in C
	-File is sequence of bytes
	-Editing is done in memory and then overrewritten in disk - uneditable
	-Windows end of row = \n = 2 bytes
	-Linux, Mac end of row = only 1 byte 
*/

#include <stdlib.h>
#include <stdio.h>


int main() {

	// Creating File Pointers
	FILE *file;
	char ch;
	file = fopen("file1.txt", "r"); // open file
	//w = destructive opening
	// a = set head at the end of file to append
	//r+, a+, w+ 

	if (file == NULL) return -1; // check if the file is open 

	// After every reading from file we have to check what we read
	printf("content of this file are: \n");
	while (!feof(file)) {
        ch = fgetc(file);
        printf("%c", ch);
    }
	/* err = fscanf(file); // return the amount of marks */ 

	fclose(file); // close file
    return 0;
} 

/* If error >>>> fscanf(file, "%*s"); */
