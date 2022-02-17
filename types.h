

// the can configuration frame : 
typedef enum  {
    true  ,
    false 
}bool;

typedef enum {
    STANDARD , EXTENDED 
}FRAME_TYPE ;
typedef char *DATA_FIELD;
typedef struct {
    
    int IDENTIFIER:11 ;
    char RTR:1;  
 
    
}STANDARD_ARBITRATION_FIELD;

typedef struct {
    int IDENTIFIER:11;
    char SRR: 1; 
    char IDE:1 ;
    int EXTENDED_IDENTIFIER:18;
    char RTR:1 ;
}EXTENDED_ARBITRATION_FIELD;


typedef struct {
    char IDE: 1; //
    char RESERVED: 1 ; //it's a reserved bit 
    char DLC:4 ; //the data length field 
} STANDARD_CONTROL_FIELD;

typedef struct{
    char r1:1 ;
    char r0:1 ;
    char DLC:4;
}EXTENDED_CONTROL_FIELD;

typedef struct {
    unsigned short CRC:15;
    char DELIMETER:1;
}CRC_FIELD ;

typedef struct {
    char ACK : 1; 
    char DEL : 1 ;
}ACK_FIELD;

// the total can frame  :

// standard can frame : 
typedef struct {
    char SOF:1 ;
    STANDARD_ARBITRATION_FIELD CAN_ARBITRATION ; 
    STANDARD_CONTROL_FIELD CAN_CONTROL;
    DATA_FIELD CAN_DATA; // the data field ;
    CRC_FIELD CAN_CRC;
    ACK_FIELD CAN_ACK;
    char CAN_EOF:7;
}CAN_STANDARD_FRAME;

// extended can frame 
typedef struct {
    char SOF:1 ;
    EXTENDED_ARBITRATION_FIELD CAN_ARBITRATION;
    EXTENDED_CONTROL_FIELD CAN_CONTROL; 
    DATA_FIELD CAN_DATA;
    CRC_FIELD CAN_CRC ; 
    ACK_FIELD CAN_ACK;
    char CAN_EOF:7; 
}CAN_EXTENDED_FRAME ;