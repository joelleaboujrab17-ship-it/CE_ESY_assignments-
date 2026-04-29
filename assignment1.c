#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 1. تحديد حجم المخزن (يمكنك تغييره لاختبار حالات الامتلاء والفراغ)
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
        printf("\n[خطأ] المخزن ممتلئ (Overflow)! لا يمكن إضافة: %c\n", data); [cite: 17, 66]
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE; // التحرك بشكل دائري
    cb->count++;
}

// دالة القراءة من المخزن 
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n[خطأ] المخزن فارغ (Underflow)!\n"); [cite: 17, 71]
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE; // التحرك بشكل دائري
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb); // تهيئة المخزن [cite: 78]

    char name[100];
    printf("أدخل اسمك: ");
    scanf("%s", name); // إدخال الاسم [cite: 20, 80]

    // إضافة اللاحقة المطلوبة [cite: 20, 83]
    strcat(name, "CE-ESY");
    printf("الناتج بعد الإضافة: %s\n", name);

    // تخزين الناتج في المخزن الدائري 
    printf("جاري الكتابة في المخزن...\n");
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]); [cite: 86]
    }

    // قراءة البيانات وعرضها 
    printf("البيانات المستخرجة من المخزن: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb)); [cite: 90, 91]
    }
    printf("\n");

    // التأكد من أن المخزن فارغ 
    if (isEmpty(&cb)) {
        printf("تم التحقق: المخزن الآن فارغ تماماً.\n");
    }

    return 0;
}
