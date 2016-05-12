//
// Created by lmw on 12/05/16.
//

#include "Arduino.h"
#include "handlecommand.h"

int intParams[16];

void handleVersion(){
    Serial.print("# This is the Version text\r\n");
}

void handleDebug(){
    Serial.print("# This is the Debug text\r\n");
}

void handleEnquire(){
    Serial.print("c 1/matrix\r\n");
    Serial.print("c 2/touch\r\n");
}

int convertParams(char** params){
    int pcount = 0;
    while (*params){
        intParams[pcount++] = atoi(*params++);
    }
    return pcount;
}

void handleSet(char** params){
    int pcount = convertParams(params);

    for (int n = 0; n < pcount; n++){
        Serial.println(intParams[n]);
    }
}

void handleCommand(char** cmd){
    if (*cmd) {
        switch (*cmd[0]) {
            case 'v':
                handleVersion();
                break;
            case 'd':
                handleDebug();
                break;
            case 'e':
                handleEnquire();
                break;
            case 's':
                handleSet(cmd+1);
                break;
        }
    }
}

