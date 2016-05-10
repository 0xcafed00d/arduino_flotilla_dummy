#include "Arduino.h"

#define LED 2

const size_t BUFFER_SZ = 128;
char inputBuffer[BUFFER_SZ];
char* elementPtrs[32];

size_t bufferPos = 0;

bool isDelim(char c) {
    return c == ',' || c == ' ';
}

void parseBuffer() {
    char** eptrs = elementPtrs;
    *eptrs = NULL;

    if (bufferPos > 0 && !isDelim(inputBuffer[0])) {
        *eptrs++ = inputBuffer;
        for (size_t n = 1; n < bufferPos; n++) {
            if (isDelim(inputBuffer[n])) {
                inputBuffer[n] = 0;
            } else {
                if (inputBuffer[n - 1] == 0) {
                    *eptrs++ = inputBuffer+n;
                }
            }
        }
    }
    *eptrs = NULL;
}

void handleBuffer() {
    inputBuffer[bufferPos] = 0;
    parseBuffer();

    for (int n = 0; elementPtrs[n]; n++) {
        Serial.println(elementPtrs[n]);
    }

    bufferPos = 0;
}

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
}

bool toggle = false;

void loop() {

    int avail = Serial.available();
    for (int n = 0; n < avail; n++) {
        digitalWrite(LED, (int) toggle);
        toggle = !toggle;
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
}
