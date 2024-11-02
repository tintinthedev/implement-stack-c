#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *elements;
  int top;
  int capacity;
} int_stack;

int_stack *create_int_stack(int capacity) {
  int_stack *stack = malloc(sizeof(int_stack));

  if (stack == NULL)
    return NULL;

  stack->elements = malloc(sizeof(int) * capacity);

  if (stack->elements == NULL) {
    free(stack);
    return NULL;
  }

  stack->top = -1;
  stack->capacity = capacity;

  return stack;
}

int is_stack_full(int_stack *stack) {
  return stack->top == stack->capacity - 1;
}

int is_stack_empty(int_stack *stack) { return stack->top == -1; }

void push(int_stack *stack, int element) {
  if (is_stack_full(stack))
    return;

  stack->top++;

  stack->elements[stack->top] = element;
}

int pop(int_stack *stack) {
  if (is_stack_empty(stack))
    return NULL;

  int removed_element = stack->elements[stack->top];
  stack->top--;

  return removed_element;
}

void show_stack(int_stack *stack) {
  if (is_stack_empty(stack))
    return;

  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->elements[i]);
  }
}

int main() { int_stack *stack = create_int_stack(10); }
