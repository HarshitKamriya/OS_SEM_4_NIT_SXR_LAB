#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sstf(int head, int *queue, int n)
{
    int seek_count = 0;
    int current_head = head;
    int *visited = (int *)calloc(n, sizeof(int));

    printf("Head movement sequence: %d", current_head);

    for (int i = 0; i < n; i++)
    {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                int distance = abs(queue[j] - current_head);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }

        visited[min_index] = 1;
        seek_count += min_distance;
        current_head = queue[min_index];
        printf(" -> %d", current_head);
    }

    printf("\nTotal seek count: %d\n", seek_count);
    free(visited);
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

    printf("\n--- SSTF Disk Scheduling ---\n");
    sstf(head, queue, n);

    free(queue);
    return 0;
}
