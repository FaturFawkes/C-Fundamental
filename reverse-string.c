#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int top;
    char items[MAX];
} stack;


void initStack(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

int isFull(stack *s) {
    return s->top == MAX - 1;
}

void push(stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    }
    s->items[++s->top] = c;
}

char pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    } 
    return s->items[s->top--];
}

void reverseString(char *str) {
    stack s;
    initStack(&s);
    int len = strlen(str);

    // Input semua karakter ke dalam stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Ambil kembali karakter dari stack dan timpa ke string
    for (int i = 0; i < len; i++) {
        str[i] = pop(&s);
    }

    str[len] = '\0';
}

int main() {
    char str[MAX];

    printf("Masukkan string: ");
    fgets(str, MAX, stdin);

    // Hapus newline jika ada
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Hasil reverse: %s\n", str);
    return 0;
}