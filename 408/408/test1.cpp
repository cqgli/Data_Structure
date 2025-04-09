#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct {
    int data[MaxSize];
    int top;
    int bottom;
}SeqStack;

void InitStack(SeqStack S) {
    S.top = -1;
}

bool StackEmpty(SeqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SeqStack S, int x) {
    int y;
    if (S.top == MaxSize - 1)
        return false;
    for (int i = 0; i < x; i++) {
        scanf("%d", &y);
        S.data[++S.top] == y;
    }
    printf("已压入栈中的元素%d个", S.top);
    return true;
}

bool Pop(SeqStack S, int x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    printf("栈顶元素%d出栈", x);
    S.top--;
    printf("栈中的元素还剩%d个", S.top);
    return true;
}

bool GetTop(SeqStack S, int x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    printf("栈顶元素为%d", x);
    return true;
}

bool PrintStack(SeqStack S) {
    int x;
    if (S.top == -1)
        return false;
    for (int i = S.top; i >= 0; i--) {
        x = S.data[i + 1];
        printf("S.data[%d] = %d", i + 1, x);
    }
    return true;
}

int main() {
    SeqStack S;
    InitStack(S);
    Push(S, 5);
    PrintStack(S);
}