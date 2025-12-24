#include <stdio.h>

#define EMPTY -1

int main()
{
    int m, n;
    int i, key, index;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    int hashTable[m];


    for (i = 0; i < m; i++)
        hashTable[i] = EMPTY;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);


        index = key % m;

        while (hashTable[index] != EMPTY)
        {
            index = (index + 1) % m;
        }

        hashTable[index] = key;
    }


    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++)
    {
        if (hashTable[i] != EMPTY)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t---\n", i);
    }

    return 0;
}
