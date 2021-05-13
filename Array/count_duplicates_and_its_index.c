// Display the index and number of duplicate elements of the given element

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10

// Static char array
typedef struct
{
    char data[MAX_SIZE];
    int length;
} arr;

arr *init()
{
    arr *array = (arr *)malloc(sizeof(arr));
    if (array == NULL)
    {
        printf("Failed to allocate memory space by malloc\n");
        exit(1);
    }

    array->length = 0;
    return array;
}

int insert(arr *array, int i, const char e)
{
    int k;
    if (i <= array->length - 1)
    {
        for (k = array->length - 1; k >= i; k--)
            array->data[k + 1] = array->data[k];
    }

    array->data[i] = e;
    array->length++;

    return TRUE;
}

void print_array(arr *array)
{
    printf("Array: [Index]\n");
    
    for (int i = 0; i < array->length; i++)
    {
        printf("%c: ", array->data[i]);
        printf("[%d]\n", i);
    }
}

void get_index(arr *array, const char e)
{
    int count = 0;
    for (int i = 0; i < array->length + 1; i++)
    {
        if (e == array->data[i])
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nNumber of duplicate elements: %d\n", count);
}

int main(void)
{
    arr *array = init();

    insert(array, 0, 'b');
    insert(array, 1, 'e');
    insert(array, 2, 'e');
    insert(array, 3, 'e');
    insert(array, 4, 'a');
    insert(array, 5, 't');
    insert(array, 6, 'e');
    insert(array, 7, 'r');

    print_array(array);

    printf("e elements are in indices: ");
    get_index(array, 'e');

    return 0;
}
