#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv, char **envp)
{
    // Set env var
    putenv("PASSCODE1=JOY");
    setenv("PASSCODE2", "AaaaA", 1);

    for (int i=0; environ[i] != NULL; i++) {
        printf("%d - %s", i , environ[i]);
    }
    

}
