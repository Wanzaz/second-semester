
/* It doesn't work for sequential data streams */
int fseek(FILE *file, long offset, int whence);

/* It sets reading HEAD on the start of the file */
void rewind(FILE *stream);

ftell, fgetpos - returns current postion of a reading HEAD
fsetpos - sets postion of reading HEAD similary to fseek

/* Returns non-zero value (true), if the file is in error state -> error */
int ferror(FILE *file);

/* Returns non-zero value (true), if there is reading beyond the end of the file */
/* It does not detect that the last element of the file has been read. Returns true only after the next one */
/* attempt to read. */
int feof(FILE *file);

/* variable errno from errno.h */
/* 	-It contains code of mistake last V/V function */
/* 	-The variable is set by all V/V functions */
/* -All functions returns error codes */
