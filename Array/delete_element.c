// Delete given element

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10

// Create static char array
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

void move(arr *array, int dest, int src)
{
    if (dest >= array->length)
    {
    }
    else
    {
        array->data[dest] = array->data[src];
        move(array, dest + 1, src + 1);
    }
}

void delete_element(arr *array, char e)
{
    if (array->length == 0)
    {
        printf("Cannot delete from an empty list\n");
        exit(FALSE);
    }

    int i, index;
    for (i = 0; i <= array->length; i++)
    {
        if (array->data[i] == e)
        {
            // Check if e element has duplicates
            int dup = i;
            while (array->data[dup] == e)
                dup++;

            // Move elements after the duplicate to current index
            int cur = i;
            while (dup <= array->length)
            {
                array->data[cur] = array->data[dup];
                cur++;
                dup++;
            }
        }

        // If next is not at the last element
        if (i + 2 != array->length)
            array->length--;
    }
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

    delete_element(array, 'e');

    printf("\nArray after deleting e\n");
    print_array(array);

    return 0;
}