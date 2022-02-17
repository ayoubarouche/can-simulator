#ifndef H_STANDARD_LIBRARIES

#include <stdlib.h>
#include <stdio.h>

#endif
#ifndef _H_CAN_TYPES

#include "types.h"

#endif
//function to show the frame :
void show_the_default_frame_parts();
// function parse the frame : 
// function to get the frame type : 
FRAME_TYPE get_can_frame_type (char * );

// get the can standard frame 
CAN_STANDARD_FRAME parse_can_standard_frame (char * );
// get the can extended frame 
CAN_EXTENDED_FRAME parse_can_extended_frame(char *);

// generate a new frame 
 // standard frame 
CAN_STANDARD_FRAME generate_can_standard_frame(int number_of_bytes_in_data_field);

// extended frame
CAN_STANDARD_FRAME generate_can_extended_frame(int number_of_bytes_in_data_field);

// function to add the bit stuffing : 

char * add_bit_stuffing(char * );

// function for erreur detection in transmition : 

bool detect_erreur(CRC_FIELD crc_field);





