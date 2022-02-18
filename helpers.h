

// shifting array ;
// char * : is the array we want to shift  ; 
// int : is the number of shifting we want to do : 
DATA_FIELD shift_array(DATA_FIELD array, int array_length );




// the starting count bit is 1 : 
int get_bit(char byte , char number){

     // get the bit and check if it's bigger than 8 than we need to check for the parity : 

    return (byte & (1<<(number-1)))>>(number-1)?1 : 0 ;
}
int get_data_length (char * frame){

    char first_bit = get_bit(frame[1] , 8);
    char last_two_bits = get_bit(frame[2] , 4);

    return (frame[2] & 0x07)<<4 | frame[1]&0x08 ; 
}


