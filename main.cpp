#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);

void bttn_interrupt(){
    printf("Buttn pressed \r\n");
    //causes following error
    //Error Message: Mutex: 0x200015FC, Not allowed in ISR context
    // the print funtion cannot be ran in this area of the program

}
int main ()
{
    bttn.fall(&bttn_interrupt );
    while (true) {

    }
}

