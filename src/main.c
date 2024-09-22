#include "ra4m1_address.h"
//#include <stdint.h>
//#include <stdbit.h>

void do_noop(long count) {
    for(volatile long a = 0; a < count; a++) {
        (void)0;

    }
}

int main(void) {
    volatile register unsigned long *pin0 = (void *)(P1CR_BASE);

    // Data direction register is 16 bit shifted
    *pin0 |= (1<<(11 + 16));
    *pin0 |= (1<<(12 + 16));
    
    int lighted = 0;
    while(1) {
        do_noop(999999);

        if (lighted == 0) {
            *pin0 |= (1<<11);
            *pin0 &= ~(1<<12);
            lighted = 1;
        }
        else {
            *pin0 &= ~(1<<11);
            *pin0 |= (1<<12);
            lighted = 0;
        }
    }

    return 0;
}
