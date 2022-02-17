#ifndef LIBRARIES

#include "includes.h"

#endif // !LIBRARIES
CAN_STANDARD_FRAME parse_can_standard_frame (char * standard_frame){

    // the frame to return : 
    CAN_STANDARD_FRAME parsed_frame; 
    // the parsed frame SOF 
    parsed_frame.SOF  = standard_frame[0]&1; // get the first bit in the frame ;

    //getting the arbitration field : 
    STANDARD_ARBITRATION_FIELD arbitration_field ;  // an arbitration datatype to handle the arbitration field 
    arbitration_field.IDENTIFIER = (standard_frame[0] & 0x0F)<< 8 | (standard_frame[1] & 0xFE); // get the arbitariton field : 
    arbitration_field.RTR = standard_frame[1] & 0x01; // get the RTR part in the can frame ( arbitration field)
    
    parsed_frame.CAN_ARBITRATION = arbitration_field ;



    // get the control field in the CAN frame : 
    STANDARD_CONTROL_FIELD control_field ; 

    // getting the control field : 

    char cf = (standard_frame[1] &0x7)<<4 | standard_frame[2] & 0x40;
    control_field.IDE = cf&(1<<6);
    control_field.RESERVED = cf&(1<<5) ; 
    control_field.DLC = cf&0x4 ;

    // save to control_field.
    parsed_frame.CAN_CONTROL = control_field ; 

    // data field 
    


    return parsed_frame;

}
typedef union{
    STANDARD_CONTROL_FIELD standard_frame ; 
    unsigned char std_frame:6 ;
}union_arbitration_field ; 
int main(){

    union_arbitration_field google  ; 
    google.std_frame = (char)0x7E;


    char  frame [] = {
        (char)0x1E , (char)0x10 , (char) 0x35,(char) 0xFF 
    } ; 
    printf("the size of control field is : %d \n", sizeof(google));
    printf("the data length in the frame is : %x\n" ,  google.standard_frame.DLC);
    printf("the frame is %d" , sizeof(frame));
    return 0 ; 
}