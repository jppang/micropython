#include "py/mphal.h"

void board_early_init(void) {
    mp_hal_pin_output(pin_B12);
    mp_hal_pin_write(pin_B12, 1);
}
