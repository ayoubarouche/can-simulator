#ifndef LIBRARIES

#include "includes.h"

#endif // !LIBRARIES

//function to show the frame :
void show_the_default_frame_parts();
// function parse the frame : 
// function to get the frame type : 
void get_can_frame_type (char * );

// get the can standard frame 
CAN_STANDARD_FRAME parse_can_standard_frame (char * );
// get the can extended frame 
CAN_EXTENDED_FRAME parse_can_extended_frame(char *);

// generate a new frame 
 // standard frame 
char * generate_can_standard_frame(int number_of_bytes_in_data_field);

// extended frame
char * generate_can_extended_frame(int number_of_bytes_in_data_field);

// function to add the bit stuffing : 

char * add_bit_stuffing(char * );

// function for erreur detection in transmition : 

bool detect_erreur(CRC_FIELD crc_field);





