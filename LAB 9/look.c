#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void look(int head, int *queue, int n)
{
    int seek_count = 0;
    int current_head = head;

    qsort(queue, n, sizeof(int), compare);

    int left[n], right[n];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (queue[i] < head)
        {
            left[left_count++] = queue[i];
        }
        else
        {
            right[right_count++] = queue[i];
        }
    }

    printf("Head movement sequence: %d", current_head);

    // Move right first (until no more requests in right)
    for (int i = 0; i < right_count; i++)
    {
        seek_count += abs(right[i] - current_head);
        current_head = right[i];
        printf(" -> %d", current_head);
    }

    // Move left (until no more requests in left)
    for (int i = left_count - 1; i >= 0; i--)
    {
        seek_count += abs(left[i] - current_head);
        current_head = left[i];
        printf(" -> %d", current_head);
    }

    printf("\nTotal seek count: %d\n", seek_count);
}

int main()
{
    int n, head;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    printf("Enter the requests (disk positions):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head);

    printf("\n--- LOOK Disk Scheduling ---\n");
    look(head, queue, n);

    free(queue);
    return 0;
}
