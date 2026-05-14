#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void scan(int head, int *queue, int n, int disk_size)
{
    int seek_count = 0;
    int current_head = head;
    int direction = 1; // 1 for right, -1 for left

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

    // Move right first
    for (int i = 0; i < right_count; i++)
    {
        seek_count += abs(right[i] - current_head);
        current_head = right[i];
        printf(" -> %d", current_head);
    }

    // Go to disk end
    seek_count += abs(disk_size - 1 - current_head);
    current_head = disk_size - 1;

    // Move left
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
    int n, head, disk_size;

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

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    printf("\n--- SCAN Disk Scheduling ---\n");
    scan(head, queue, n, disk_size);

    free(queue);
    return 0;
}
