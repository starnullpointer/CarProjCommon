#ifndef CONSTANTS
#define CONSTANTS

/* *****************
 * PIN DEFINITIONS
 * *****************
 */

#define WINC_CS   8
#define WINC_IRQ  7
#define WINC_RST  4
// WINC_EN goes to 5v.

#define TCAADDR 0x70 //for multiplexor


//                                        "---------x---------x---------x"
//sender reciever command
const char CAR_CON_REQ_POS[30]          = "{ Car Con ReqPos }";
const char CON_CAR_TURN_LIGHT_ON[30]    = "{ Con Car TurnLightOn }";
const char CAR_CON_LIGHT_ON[30]         = "{ Car Con LightIsOn }";
const char CON_CAM_REQ_POS[30]          = "{ Con Cam ReqPos }";
const char CAM_CON_HERE_IS_POS[30]      = "{ Cam Con HereIsPos "; //need to add others. MISSING BRACE
const char CON_CAR_YOUR_POS[30]         = "{ Con Car YourPos "; //need others MISSING BRACE

const char CAR_CON_REQ_DEST[30]         = "{ Car Con ReqDest }";
const char CON_CAR_HERE_IS_DEST[30]        = "{ Con Car HereIsDest ";  //need to finish

const char CAR_CON_HELLO[30]            = "{ Car Con Hello }";
const char CAM_CON_HELLO[30]            = "{ Cam Con Hello }";
const char CON_CAR_HELLO[30]            = "{ Con Car Hello }";
const char CON_CAM_HELLO[30]            = "{ Con Cam Hello }";

const char COMM_LIGHT_IS_ON[15]         ="LightIsOn";
const char COMM_HERE_IS_POS[15]         ="HereIsPos";
const char COMM_TURN_LIGHT_ON[15]       ="TurnLightOn";
const char COMM_YOUR_POS[15]            ="YourPos";
const char COMM_YOUR_DEST[15]           ="HereIsDest";


//IP address
const int IP1=172;
const int IP2=20;
const int IP3=10;
const int IP4=2;

const int port = 3141;
const char ssid[] = "Mac's iPhone";     //  your network SSID (name)
const char pass[] = "helloworld";    // your network password (use for WPA, or use as key for WEP)
#endif // CONSTANTS

