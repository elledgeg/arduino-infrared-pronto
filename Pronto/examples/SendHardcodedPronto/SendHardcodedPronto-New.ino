/*
Send Pronto Hex via an IR LED connected to Arduino Pin D9.

Store Pronto Code in uint16_t in either 0x00 or 0000 format commas between each HEX
 
Based on IR_Player_ProntoCode.c by Stephen Ong
https://github.com/stephenong/Arduino-IR-Remote-Control-Player
This work is licenced under the Creative Commons Attribution-NonCommercial 
3.0 Unported License. To view a copy of this licence, visit 
http://creativecommons.org/licenses/by-nc/3.0/ or send a letter to Creative 
Commons, 171 Second Street, Suite 300, San Francisco, California 94105, USA.
http://creativecommons.org/licenses/by-nc/3.0/
*/
#include <Pronto.h>



Pronto pronto(9);

uint16_t up[78] = { 0x0, 0x6D, 0x22, 0x3, 0xA9, 0xA8, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x3F, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x40, 0x15, 0x15, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x3F, 0x15, 0x702, 0xA9, 0xA8, 0x15, 0x15, 0x15, 0xE6E };

void setup() {
	Serial.begin(115200);
	while (Serial.available());
	Serial.print("Hello World!\r\n enter \"SEND\" to send IR\r\n");
}

void loop() {
	if (Serial.available() > 0 ) {
		String inString = Serial.readString();
		if (inString.startsWith("SEND")) {
			int j = 78;
			pronto.ir_start(up);
			Serial.print("SENT: ");
			for ( int i = 0; i < j; i++ ) {
				Serial.print ("0x");
				Serial.print (up[i], HEX);
				Serial.print(" ");
			}
			Serial.print("\r\n");
		}
	}
}


