#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);
char flag0 = 0;  //flag variable set to 0

void bttn_interrupt(){
    flag0 = 1;   //flag 1 varible set to 1 when he voltage falls to 0 volts 

    //printf("Buttn pressed \r\n");
    //causes following error
    //Error Message: Mutex: 0x200015FC, Not allowed in ISR context
    // the print funtion cannot be ran in this area of the p rogram because memory isn't piriotised for it.
    // will have to use flags or EventQueue to get it to run

}
void bttn_interrupt_off(){
    flag0 = 2;   //flag 2 varible set to 2 when he voltage falls to 0 volts
}

int main (){

    bttn.fall(&bttn_interrupt );  //pressing button triggers interrupt, no need to release it
    bttn.rise(&bttn_interrupt_off );  //letting go of button

    printf("program ready to start\r\n");
    while (true) {
        switch (flag0){
            case 1:   //if flag is 1 then prints button is pressed
                printf("Blue Button pressed \r\n");
                flag0 = 0;   //reset flag to 0
                break;
                
            case 2:   //if flag is 2 then prints button is let go
                printf("Blue Button let go \r\n");
                flag0 = 0;   //reset flag to 0
                break;
        
            default:
                flag0 = 0;
                break;

        }
    ThisThread :: sleep_for(10ms);  //ensures button bounce does not cause the mbed to see two presses
    }
}
