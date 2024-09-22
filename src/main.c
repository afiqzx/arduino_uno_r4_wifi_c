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
    volatile register unsigned long *pin0d = (pin0 + 0x02);

    *pin0d |= (1<<12);
    
    int lighted = 0;
    while(1) {
        do_noop(9999);

        if (lighted == 0) {
            *pin0 |= (1<<12);
            lighted = 1;
        }
        else {
            *pin0 &= ~(1<<12);
            lighted = 0;
        }
    }

    return 0;
}
