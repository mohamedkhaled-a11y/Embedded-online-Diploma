#include <stdint.h>
#include <stdbool.h>

void Queue_Init();

void Queue_push(uint8_t data);

uint8_t Queue_pop();

bool isEmpty();

bool isFULL();