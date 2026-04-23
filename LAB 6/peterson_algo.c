#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int turn;
int flag[2] = {0, 0};   // initially no thread wants to enter
int shared = 0;         // shared resource

void *process0(void *arg) {
    for (int i = 0; i < 5; i++) {
        flag[0] = 1;          // thread0 wants to enter
        turn = 1;             // give priority to thread1
        while (flag[1] && turn == 1);  // busy wait

        // ---- Critical Section ----
        shared++;
        printf("Thread0 in CS, shared = %d\n", shared);
        // --------------------------

        flag[0] = 0;          // thread0 leaves CS
        sleep(1);             // simulate work outside CS
    }
    return NULL;
}

void *process1(void *arg) {
    for (int i = 0; i < 5; i++) {
        flag[1] = 1;          // thread1 wants to enter
        turn = 0;             // give priority to thread0
        while (flag[0] && turn == 0);  // busy wait

        // ---- Critical Section ----
        shared++;
        printf("Thread1 in CS, shared = %d\n", shared);
        // --------------------------

        flag[1] = 0;          // thread1 leaves CS
        sleep(1);             // simulate work outside CS
    }
    return NULL;
}

int main() {
    pthread_t t0, t1;

    pthread_create(&t0, NULL, process0, NULL);
    pthread_create(&t1, NULL, process1, NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    printf("Final value of shared = %d\n", shared);
    return 0;
}
