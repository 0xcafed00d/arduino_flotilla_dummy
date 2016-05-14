//
// Created by lmw on 12/05/16.
//

#include "Arduino.h"
#include "handlecommand.h"

int intParams[16];

void handleVersion() {
	Serial.print("# Flotilla ready to set sail..\r\n");
	Serial.print("# Version: 1.12\r\n");
	Serial.print("# Serial: 0111111111111111111111\r\n");
	Serial.print("# User: Unnamed\r\n");
	Serial.print("# Dock: Unnamed\r\n");
}

void handleDebug() {
	Serial.print("# SRAM: 1337 bytes\r\n");
	Serial.print("# Loop: 0ms (0us) 0fps\r\n");
	Serial.print("# Channels:\r\n");
	Serial.print("# - 0\r\n");
	Serial.print("# - 1\r\n");
	Serial.print("# - 2\r\n");
	Serial.print("# - 3\r\n");
	Serial.print("# - 4\r\n");
	Serial.print("# - 5\r\n");
	Serial.print("# - 6\r\n");
	Serial.print("# - 7\r\n");
}

void handleEnquire() {
	Serial.print("c 1/matrix\r\n");
	Serial.print("c 2/touch\r\n");
}

int convertParams(char** params) {
	int pcount = 0;
	while (*params) {
		intParams[pcount++] = atoi(*params++);
	}
	return pcount;
}

void handleSet(char** params) {
	int pcount = convertParams(params);

	for (int n = 0; n < pcount; n++) {
		Serial.println(intParams[n]);
	}
}

void handleCommand(char** cmd) {
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
				handleSet(cmd + 1);
				break;
		}
	}
}
