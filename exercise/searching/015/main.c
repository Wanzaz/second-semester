#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 550


typedef struct 
{
    int day;
    int month;
    char name[31];
}Tname;



int LoadToArray(FILE * input, Tname array[])
{
    int i = 0;
    while (i < MAX && fscanf(input,"%d. %d. %30s", &array[i].day, &array[i].month, array[i].name) == 3 )
    {
        i++;
    }
    return i;
}


void pause(void)
{
    #if defined __WIN32 || defined __WIN64
        system("pause"); 
	#else 
		system("read a");
	#endif
}

void clear(void)
{
	#ifdef _WIN32 
		system("cls");
	#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	    system("clear");
	//add some other OSes here if needed
	#else
		#error "OS not supported."
	#endif
}

void menu()
{
    clear();
    printf("End of program ................0\n");
    printf("Show all names ............... 1\n");
    printf("Sort names by alphabet ....... 2\n");
    printf("Who has name day ..............3\n");
    printf("When does have name day .......4\n");
    printf("Enter your option 0-5: ");
}

void showNames(FILE *outputs, Tname array[], int n)
{
    for (int i = 0; i < n; i++) {
        fprintf(outputs, "%-10s %d. %d.\n", array[i].name, array[i].day, array[i].month);
    }  
    printf("\n");
}


void sortNames(Tname array[], int n)
{
    for (int i = 1; i < n; i++) {
        int inner = i;
        Tname current = array[i];
        while (inner > 0 && strcmp(current.name, array[i - 1].name) > 0) {
            array[inner] = array[inner - 1];
            inner--;
        }
        array[inner] = current;
    }
}


int searchDate(Tname array[], int n, char name[])
{
    int i = 0;
    
    while (i < n && strcmp(array[i].name, name) != 0) {
        i++;
    }

    if (i < n) return i;
    else return -1;
}


int searchName(Tname array[], int n, int day, int month)
{
    int i = 0;
    
    while (i < n && (array[i].day != day || array[i].month != month)) {
        i++;
    }

    if (i < n) return i;
    else return -1;
}


int main(void) {
    printf("Sorting and searching\n");
    printf("--------------------\n");
    FILE *file = fopen("names.txt", "r");
    if (file == NULL) {
        printf("File cannot be opened!");
    }

    int option, number, position, quantity, day, month;
    char name[31];
    Tname names[MAX];
    quantity = LoadToArray(file, names);
    printf("Number of sorted names: %d.\n", quantity);
    fclose(file);

    option = 1;

    while (option !=0) {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 1: showNames(stdout, names, quantity);
                break;
            case 2: sortNames(names, quantity);
                printf("Names are sorted.\n");
                break;
            case 3: printf("Enter a day: ");
                    scanf("%d", &day);
                    printf("Enter a month: ");
                    scanf("%d",&month);
                    position = searchName(names, quantity, day, month);

                    if (position == -1)
                        printf("This day doesn't have anybody a name day.\n");
                    else
                        printf("%d. %d. has a name day %s.\n", day, month, names[position].name);
                    break;
            case 4: printf("Enter a name: ");
                    scanf("%30s", name);
                    position = searchDate(names, quantity, name);

                    if (position == -1)
                        printf("We don't have this name here.\n");
                    else
                        printf("%s has a name day %d. %d.\n",names[position].name, names[position].day,names[position].month);
                    break;
        }

        if (option != 0) {
            pause();
        }
    }

    printf("End of a program\n");
    return 0;
}
