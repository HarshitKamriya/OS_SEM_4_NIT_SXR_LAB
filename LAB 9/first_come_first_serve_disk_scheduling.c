#include <stdio.h>
#include <stdlib.h>

void fcfs(int head, int *queue, int n)
{
    int seek_count = 0;
    int current_head = head;

    printf("Head movement sequence: %d", current_head);

    for (int i = 0; i < n; i++)
    {
        seek_count += abs(queue[i] - current_head);
        printf(" -> %d", queue[i]);
        current_head = queue[i];
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

    printf("\n--- FCFS Disk Scheduling ---\n");
    fcfs(head, queue, n);

    free(queue);
    return 0;
}
