#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 13 


typedef struct {
    char buffer[SIZE];
    int head; 
    int tail;   
    int count; 
} CircularBuffer;


void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}


bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}


bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}


void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\n Buffer Overflow! Cannot write: %c\n", data);
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE; 
    cb->count++;
}


char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n Buffer Underflow!\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE; 
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];
    const char *suffix = "-CE-ESY";

    
    printf("Enter your name: ");
    scanf("%s", name);

    
    strcat(name, suffix);

    printf("Storing and reading result: ");

    
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c", read(&cb));
    }
    
    return 0;
}