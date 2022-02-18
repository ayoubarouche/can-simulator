#ifndef LIBRARIES

#include "includes.h"

#endif // !LIBRARIES

int main()
{

    // CAN_STANDARD_FRAME frame ;
    // char number = 0x40 ;
    // printf("the size of short is : %d" , get_bit(number , 6));
    unsigned char standard_frame[] = {
        0xB0, 0x06, 0xC0, 0x34};

    // get the first bits :

    // int can_header =
        unsigned char * ptr;
    printf("\n");
  //  long ret = strtol(standard_frame, &ptr, 0);
    // int data_length = get_data_length(standard_frame) ;
    // printf("\n the data length is : %d" , data_length );

    // parse the identifier part : 
    unsigned char SOF = get_bit(standard_frame[0],0);
    unsigned short arbitration_field ;
    arbitration_field = (standard_frame[0] & 0x7F)<<5 | (standard_frame[1] & 0xF8); 

    unsigned char control_field = (standard_frame[1] & 0x07)<<3 | (standard_frame[2] & 0xE0);
    // for (int i = 0; i < sizeof(standard_frame) / sizeof(char); i++)
    // {
    //     printf(" 0x%02X", standard_frame[i]);
    // }

    printf("the SOF value is : %d" , SOF);
    printf("\n");
    printf("the arbitration field is : %02X",control_field);
    printf("\n");
    printf("the long double size is : %d" , sizeof(long double));
    printf("\n");
    return 0;
}