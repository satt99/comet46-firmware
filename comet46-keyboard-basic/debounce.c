#include "stdint.h"

// Ring buffer that holds the previous states used for debouncing
#define SAMPLES_COUNT 5

extern uint32_t debounce(uint32_t previous_state, uint32_t snapshot)
{
    static uint32_t buffer[SAMPLES_COUNT] = {0};
    static uint32_t head = 0;

    uint32_t on_state = ~0;
    uint32_t off_state = 0;
    uint32_t state = previous_state;

    // Store the read state in the ring buffer
    buffer[head++] = snapshot;

    // Reset the head pointer of the ring buffer
    if (head == SAMPLES_COUNT)
    {
        head = 0;
    }

    // Collapse all the previous states into two variable
    for (uint32_t i = 0; i < SAMPLES_COUNT; ++i)
    {
        on_state &= buffer[i];
        off_state |= buffer[i];
    }

    // Debouncing the ON state (a key is pressed if previous five states are 1)
    state |= on_state;

    // Debouncing the OFF state (a key is released if previous five states are 0)
    state &= off_state;

    return state;
}