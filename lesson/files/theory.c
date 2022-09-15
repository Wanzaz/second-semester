/* 
 * THEORY OF FILES

The standard of input and output:
	-stdin = input (keyboard)
	-stdout = output (display)

Files: 
	- binary (opening with rb, wb modes)
    - text

Working with files 4. steps:
	1. open file - FILE* (fopen(name_of_file, mode))
	2. check if file is NULL (empty pointer)
	3. check if EOF (End Of File) 
	4. close file - fclose(name_of_file)

Output/Input for each character:
	int character = fgetc(name_of_file);
					fputc(character, name_of_file);
					ungetc(character, name_of_file);

fprintf(name_of_file, "%d %f %20s", ...)
fscanf(name_of_file, "%d %f %20s", ...)
*/
