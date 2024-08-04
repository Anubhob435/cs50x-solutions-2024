//coppying all the elements of the list to a new list when new element is added and free,
//the original list

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3*sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *temp = realloc(list, 4 * sizeof(int));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }
    list = temp;

    temp[3] = 4;

    for (int i = 0; i<3; i++)
    {
        printf("%i\n", list[i]);
    }
}