// included files

#include "app.h"
#include "tcpip/tcpip.h"

// Server Port. Defined to used the ethernet bus
#define SERVER_PORT 1234

//list of hex values to be sent on the bus
static const char hex[][3]={"00","01","02","03","04","05","06","07","08","09","0A","0B","0C","0D","0E","0F",
                            "10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F",
                            "20","21","22","23","24","25","26","27","28","29","2A","2B","2C","2D","2E","2F",
                            "30","31","32","33","34","35","36","37","38","39","3A","3B","3C","3D","3E","3F",
                            "40","41","42","43","44","45","46","47","48","49","4A","4B","4C","4D","4E","4F",
                            "50","51","52","53","54","55","56","57","58","59","5A","5B","5C","5D","5E","5F",
                            "60","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F",
                            "70","71","72","73","74","75","76","77","78","79","7A","7B","7C","7D","7E","7F",
                            "80","81","82","83","84","85","86","87","88","89","8A","8B","8C","8D","8E","8F",
                            "90","91","92","93","94","95","96","97","98","99","9A","9B","9C","9D","9E","9F",
                            "A0","A1","A2","A3","A4","A5","A6","A7","A8","A9","AA","AB","AC","AD","AE","AF",
                            "B0","B1","B2","B3","B4","B5","B6","B7","B8","B9","BA","BB","BC","BD","BE","BF",  
                            "C0","C1","C2","C3","C4","C5","C6","C7","C8","C9","CA","CB","CC","CD","CE","CF",
                            "D0","D1","D2","D3","D4","D5","D6","D7","D8","D9","DA","DB","DC","DD","DE","DF",
                            "E0","E1","E2","E3","E4","E5","E6","E7","E8","E9","EA","EB","EC","ED","EE","EF",
                            "F0","F1","F2","F3","F4","F5","F6","F7","F8","F9","FA","FB","FC","FD","FE","FF"};
// the current app state
APP_DATA appData;

// global values for modifying rotinely
uint32_t speed;
uint32_t engTemp;
uint32_t batVolt;

// Initialze function called in main.c
// this sets the app state in the TCPIP initiate setting as well as starts the can bus
void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_TCPIP_WAIT_INIT; // APP_STATE_INIT;
    
    
    /* Initialize the can bus */
    DRV_CAN0_Open();
    

}


// the task function that goes through each state
void APP_Tasks ( void )
{
    SYS_STATUS tcpipStat;
    const char *netName, *netBiosName;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    int                 i, nNets;
    TCPIP_NET_HANDLE    netH;
    
    
    SYS_CMD_READY_TO_READ(); // accept inputs from the usb
    //Check the application's current state.
    switch ( appData.state )
    {
        //Application's initial state. 
        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip); // get the tcpip stack
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE(" APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the 
                // available interfaces 
                nNets = TCPIP_STACK_NumberOfNetworksGet();
                for(i = 0; i < nNets; i++)
                {

                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

                }
                appData.state = APP_TCPIP_WAIT_FOR_IP;
            }
            break;
        case APP_TCPIP_WAIT_FOR_IP:

            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for (i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val; // use the current IP address

                    if (ipAddr.v[0] != 0 && ipAddr.v[0] != 169) // Wait for a Valid IP
                    {
                        appData.state = APP_TCPIP_OPENING_SERVER;
                    }
                }
            }
        case APP_TCPIP_OPENING_SERVER: // open the connection
        {
            appData.socket = TCPIP_UDP_ServerOpen(IP_ADDRESS_TYPE_IPV4, SERVER_PORT, 0);
            if (appData.socket == INVALID_SOCKET)
            {
                SYS_CONSOLE_MESSAGE("Couldn't open server socket\r\n");
                break;
            }
            appData.state = APP_TCPIP_WAIT_FOR_CONNECTION;
        }
            break;

        case APP_TCPIP_WAIT_FOR_CONNECTION:
        {
            if (!TCPIP_UDP_IsConnected(appData.socket))
            {
                return;
            }
            else
            {
                // We got a connection
                appData.state = APP_TCPIP_ENABLE_CONNECTION;
                SYS_CONSOLE_MESSAGE("Received a connection\r\n");
            }
        }
        break;
        case APP_TCPIP_ENABLE_CONNECTION:
        {
            // break connection if server disconnets
            if (!TCPIP_UDP_IsConnected(appData.socket))
            {
                appData.state = APP_TCPIP_CLOSING_CONNECTION;
                SYS_CONSOLE_MESSAGE("Connection was closed\r\n");
                break;
            }

            uint8_t AppBuffer[512];
            // call can bus
            //CAN_RX_MSG_BUFFER *receivedMsg;
            //receivedMsg = (CAN_RX_MSG_BUFFER *)PLIB_CAN_ReceivedMessageGet(CAN_ID_1, CAN_CHANNEL0); // read can -depreciated until working
            //uint8_t testSend[8] = {0,1,2,3,4,5,6,7};
            //DRV_CAN0_ChannelMessageTransmit(CAN_CHANNEL1, 400, 8, (uint8_t *)testSend); // send can messsages -depreciated until working.
            // set all buffer to zero
            memset(AppBuffer, 0, 512);
            // check if udp message is ready otherwise leave the function
            if(!TCPIP_UDP_GetIsReady(appData.socket)) { break; }
            uint16_t readBytes = TCPIP_UDP_ArrayGet(appData.socket, AppBuffer, sizeof(AppBuffer));
            uint8_t CheckBuffer[5] = {'~','s','e','n','d'};
            // exit if the read buffer is smaller then the check buffer
            if(readBytes < sizeof(CheckBuffer))
            {
                TCPIP_UDP_Discard(appData.socket);
                break;
            }
            
            bool _checkFlag = true;
            int i;
            // check to see if we should enable the can bus output ore disconnect
            for (i=0; i<sizeof(CheckBuffer); i++)
            {
                if(CheckBuffer[i] != AppBuffer[i])
                {
                    _checkFlag = false;
                }
            }
            
            // break if the check flag is false otherwise change the state to send messages
            if (_checkFlag)
            {
                speed = 60;
                engTemp = 87;
                batVolt = 147; 
                appData.state = APP_TCPIP_SENDDATA_CONNECTION;
            }
            else
            {
                break;
            }
            

            
            TCPIP_UDP_Discard(appData.socket);
        }
        break;
        case APP_TCPIP_SENDDATA_CONNECTION:
        {
            // break connection if server disconnects
            if (!TCPIP_UDP_IsConnected(appData.socket))
            {
                appData.state = APP_TCPIP_CLOSING_CONNECTION;
                SYS_CONSOLE_MESSAGE("Connection was closed\r\n");
                break;
            }
            
            // read an incomming message to see if its time to stop the return.
            uint8_t AppBuffer[512];
            memset(AppBuffer, 0, 512);
            // check to see if there's any input
            if(TCPIP_UDP_GetIsReady(appData.socket)) 
            {
                uint16_t readBytes = TCPIP_UDP_ArrayGet(appData.socket, AppBuffer, sizeof(AppBuffer));
                uint8_t CheckBuffer[5] = {'~','s','t','o','p'};
                // exit if the read buffer is smaller then the check buffer
                bool _checkFlag = true;
                if(readBytes < sizeof(CheckBuffer)) // discard and continue if the data is short, otherwise check it
                {
                    TCPIP_UDP_Discard(appData.socket);                    
                }
                else
                {
                    // check to see if we should enable the can bus output ore disconnect
                    int i;
                    for (i=0; i<sizeof(CheckBuffer); i++)
                    {
                        if(CheckBuffer[i] != AppBuffer[i])
                        {
                            _checkFlag = false;
                        }
                    }

                    // break if the check flag is false otherwise change the state to send messages
                    if (_checkFlag)
                    {
                        appData.state = APP_TCPIP_CLOSING_CONNECTION;
                        break;
                    }
                }
            }
            
            //uint8_t testSend[8] = {0,1,2,3,4,5,6,7};
            //DRV_CAN0_ChannelMessageTransmit(CAN_CHANNEL1, 400, 8, (uint8_t *)testSend); // send can messsages -depreciated until working.
            
                
            int maxSend = TCPIP_UDP_PutIsReady(appData.socket);
            
            // if we can send 25 bytes, then please do so
            if(maxSend >= 26)
            {
                // getnerate the data
                uint32_t random = SYS_RANDOM_CryptoGet()%50; // get random number from 0-99
                
                // can messsage came at 0 for the randome number
                if (random == 0)
                {
                    // Transfer the data 
                    random = SYS_RANDOM_CryptoGet()%850;
                              
                    if(random<100) // temperature engine
                    {
                        if (engTemp>78&&engTemp<95)
                        {
                            uint32_t temp = SYS_RANDOM_CryptoGet()%5;
                            engTemp = engTemp+temp-2;
                        }
                        else if(engTemp<=78)
                        {
                            engTemp = 80;
                        }
                        else
                        {
                            engTemp = 93;
                        }
                        uint8_t messageData0[18] = {'0','8','0','4',hex[engTemp][0],hex[engTemp][1],'1','1','1','1','1','1','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData0, sizeof(messageData0));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<150) // engine status on
                    {
                        uint8_t messageData1[16] = {'0','8','0','2','1','0','0','1','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData1, sizeof(messageData1));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<300)
                    {
                        if (speed>30&&speed<80)
                        {
                            uint32_t temp = SYS_RANDOM_CryptoGet()%5;
                            if(temp == 0)
                            {   
                                temp =  SYS_RANDOM_CryptoGet()%5;
                                speed = speed+temp-2;
                            }
                        }
                        else if(speed<=30)
                        {
                            speed = 33;
                        }
                        else
                        {
                            speed = 75;
                        }
                        uint8_t messageData2[12] = {'0','3','F','3',hex[speed][0],hex[speed][1],'A','A','B','B','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData2, sizeof(messageData2));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<350)
                    {
                        uint8_t messageData3[12] = {'0','3','F','1','2','F','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData3, sizeof(messageData3));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<375)
                    {
                        uint8_t messageData4[12] = {'0','3','F','1','A','5','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData4, sizeof(messageData4));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<385)
                    {
                        uint8_t messageData5[12] = {'0','3','F','1','A','6','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData5, sizeof(messageData5));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<415)
                    {
                        uint8_t messageData6[12] = {'0','3','F','1','C','A','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData6, sizeof(messageData6));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    
                    else if(random<450)
                    {
                        uint8_t messageData7[12] = {'0','3','F','1','C','B','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData7, sizeof(messageData7));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<500)
                    {
                        uint8_t messageData8[16] = {'0','3','F','2','C','B','B','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData8, sizeof(messageData8));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<600)
                    {
                        if (batVolt>119&&batVolt<156)
                        {
                            uint32_t temp = SYS_RANDOM_CryptoGet()%20;
                            if(temp == 0)
                            {
                                batVolt = batVolt-1;
                            }
                        }
                        else if(batVolt<=119)
                        {
                            batVolt = 119;
                        }
                        else
                        {
                            batVolt = 147;
                        }
                        uint8_t messageData9[12] = {'0','D','4','3',hex[batVolt][0],hex[batVolt][1],'A','A','A','A','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData9, sizeof(messageData9));
                        TCPIP_UDP_Flush(appData.socket);  
                    }
                    else if(random<650)
                    {
                        uint8_t messageData10[12] = {'0','D','4','1','B','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData10, sizeof(messageData10));
                        TCPIP_UDP_Flush(appData.socket);  
                    }   
                    else if(random<680)
                    {
                        uint8_t messageData11[16] = {'0','A','1','2','A','A','0','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData11, sizeof(messageData11));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<700)
                    {
                        uint8_t messageData12[16] = {'0','A','1','1','B','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData12, sizeof(messageData12));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<720)
                    {
                        uint8_t messageData13[16] = {'0','7','7','3','7','7','7','7','0','A','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData13, sizeof(messageData13));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<750)
                    {
                        uint8_t messageData14[16] = {'0','7','7','3','7','7','7','7','0','B','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData14, sizeof(messageData14));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<790)
                    {
                        uint8_t messageData15[16] = {'0','7','7','2','F','0','0','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData15, sizeof(messageData15));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<820)
                    {
                        uint8_t messageData16[16] = {'0','7','7','2','E','0','0','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData16, sizeof(messageData16));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    else if(random<850)
                    {
                        uint8_t messageData17[16] = {'0','7','7','2','E','E','0','0','0'};
                        TCPIP_UDP_ArrayPut(appData.socket, messageData17, sizeof(messageData17));
                        TCPIP_UDP_Flush(appData.socket);  
                    } 
                    
                    //PLIB_CAN_ChannelUpdate(CAN_ID_1, CAN_CHANNEL0);  // depreciated until can is working

                }
            }
     
            
        }
        break;
        case APP_TCPIP_CLOSING_CONNECTION:
        {
            			// Close the socket connection.
            TCPIP_UDP_Close(appData.socket);

            appData.state = APP_TCPIP_OPENING_SERVER;

        }

    }
}


