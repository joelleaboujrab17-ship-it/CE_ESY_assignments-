#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 1. تحديد حجم المخزن (SIZE)
#define SIZE 15

// 2. تعريف هيكل المخزن الدائري
typedef struct {
    char buffer[SIZE];
    int head;  // مؤشر الكتابة
    int tail;  // مؤشر القراءة
    int count; // عدد العناصر الحالية
} CircularBuffer;

// تهيئة المخزن
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق هل المخزن ممتلئ
bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// التحقق هل المخزن فارغ
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// دالة الكتابة في المخزن
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\n[خطأ] المخزن ممتلئ (Overflow)! لا يمكن إضافة: %c\n", data);
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

// دالة القراءة من المخزن
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n[خطأ] المخزن فارغ (Underflow)!\n");
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

    char name[50];
    printf("أدخل اسمك: ");
    scanf("%s", name);

    // إضافة اللاحقة المطلوبة
    strcat(name, "CE-ESY");
    printf("الناتج بعد التعديل: %s\n", name);

    // تخزين كل حرف في المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    // قراءة البيانات من المخزن وعرضها
    printf("البيانات المستخرجة من المخزن: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    printf("\n");

    return 0;
}
