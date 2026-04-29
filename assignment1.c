#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAPACITY 18

typedef struct {
    char data_storage[MAX_CAPACITY];
    int write_pos;
    int read_pos;
    int current_size;
} MyCircularBuffer;

void setupBuffer(MyCircularBuffer *cb) {
    cb->write_pos = 0;
    cb->read_pos = 0;
    cb->current_size = 0;
}

bool checkFull(MyCircularBuffer *cb) {
    return cb->current_size == MAX_CAPACITY;
}

bool checkEmpty(MyCircularBuffer *cb) {
    return cb->current_size == 0;
}

void insertData(MyCircularBuffer *cb, char item) {
    if (checkFull(cb)) {
        printf("\n[Overflow] %c\n", item);
        return;
    }
    cb->data_storage[cb->write_pos] = item;
    cb->write_pos = (cb->write_pos + 1) % MAX_CAPACITY;
    cb->current_size++;
}

char extractData(MyCircularBuffer *cb) {
    if (checkEmpty(cb)) {
        printf("\n[Underflow]\n");
        return '\0';
    }
    char item = cb->data_storage[cb->read_pos];
    cb->read_pos = (cb->read_pos + 1) % MAX_CAPACITY;
    cb->current_size--;
    return item;
}

int main() {
    MyCircularBuffer my_cb;
    setupBuffer(&my_cb);

    char user_name[60];
    printf("Enter name: ");
    scanf("%s", user_name);

    strcat(user_name, "CE-ESY");
    
    for (int i = 0; i < strlen(user_name); i++) {
        insertData(&my_cb, user_name[i]);
    }

    printf("Buffer Output: ");
    while (!checkEmpty(&my_cb)) {
        printf("%c", extractData(&my_cb));
    }
    printf("\n");

    return 0;
}

