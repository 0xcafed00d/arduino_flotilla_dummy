#include "Arduino.h"

#define LED 2

const size_t BUFFER_SZ = 128;
char inputBuffer[BUFFER_SZ + 1];
size_t bufferPos = 0;
char *elementPtrs[32];


bool isDelim(char c) {
    return c == ',' || c == ' ';
}

void parseBuffer() {
    char **eptrs = elementPtrs;
    *eptrs = NULL;

    if (bufferPos > 0 && !isDelim(inputBuffer[0])) {
        *eptrs++ = inputBuffer;
        for (size_t n = 1; n < bufferPos; n++) {
            if (isDelim(inputBuffer[n])) {
                inputBuffer[n] = 0;
            } else {
                if (inputBuffer[n - 1] == 0) {
                    *eptrs++ = inputBuffer + n;
                }
            }
        }
    }
    *eptrs = NULL;
}

void handleBuffer() {
    inputBuffer[bufferPos] = 0;
    parseBuffer();

    for (char **eptrs = elementPtrs; *eptrs; eptrs++) {
        Serial.println(*eptrs);
    }

    bufferPos = 0;
}

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
}

void loop() {

    if (Serial) {
        digitalWrite(LED, 1);
        int avail = Serial.available();
        for (int n = 0; n < avail; n++) {
            int c = Serial.read();
            switch (c) {
                case '\r':
                    handleBuffer();
                    break;
                case '\n':
                    break;
                default:
                    inputBuffer[bufferPos++] = (char) c;
            }
        }
    } else {
        digitalWrite(LED, 0);
    }
}
