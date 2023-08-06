#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);

void bttn_interrupt(){
    //printf("Buttn pressed \r\n");
    //causes following error
    //Error Message: Mutex: 0x200015FC, Not allowed in ISR context
    // the print funtion cannot be ran in this area of the p rogram because memory isn't piriotised for it.
    // will have to use flags or EventQueue to get it to run

}
int main ()
{
    bttn.rise(&bttn_interrupt );
    printf("program ready to start\r\n");
    while (true) {
        printf("Buttn pressed \r\n");
        break;

    }
}

