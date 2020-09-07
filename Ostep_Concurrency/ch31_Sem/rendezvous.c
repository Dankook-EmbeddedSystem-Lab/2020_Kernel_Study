#include <stdio.h>
#include <unistd.h>
#include "../include/common_threads.h"

// If done correctly, each child should print their "before" message
// before either prints their "after" message. Test by adding sleep(1)
// calls in various locations.

sem_t s1, s2;

void *child_1(void *arg) {
	sleep(1);
	printf("child 1: before\n");
    // what goes here?    
	Sem_wait(&s1);
	sleep(1);
	printf("child 1: after\n");
    return NULL;
}

void *child_2(void *arg) {
    sleep(1);
	printf("child 2: before\n");
    // what goes here?
    // 
    sleep(1);
    Sem_post(&s1);
    printf("child 2: after\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2, p3,p4;
    printf("parent: begin\n");
    // init semaphores here
    // s1, s2 ==> 
	Sem_init(&s1,0); Sem_init(&s2,1);
    Pthread_create(&p1, NULL, child_1, NULL);
    Pthread_create(&p2, NULL, child_2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("parent: end\n");
    return 0;
}

