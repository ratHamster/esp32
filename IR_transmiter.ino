#include <IRremote.h>

// Define the pins
int irLedPin = 13;  // IR LED anode (+) connected to the collector
int bjtBasePin = 2; // BJT base pin
int buttonPin = 7;

IRsend irsend(2);

void setup() {
  // Set the pin modes
  pinMode(irLedPin, OUTPUT);
  pinMode(bjtBasePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW){
  // Turn on the BJT to allow current to flow to the IR LED
  digitalWrite(bjtBasePin, HIGH);

  // Send RC5 infrared signal with data code 0x0 and 8 bits
  //irsend.sendSony(0xa90, 8);  // The last parameter (0) indicates it's not a repeat signal
  //irsend.sendNEC(0x0102, 0x34, true, 0);
  //irsend.sendRC5(0x1F, 0x3F, 0, true);
  irsend.sendSony(0x1, 12);
  delay(200);

  // Turn off the BJT to stop the current flow to the IR LED
  digitalWrite(bjtBasePin, LOW);

  delay(200);
  }
}
  // Repeat the process with a different data code
  // Turn on the BJT
  //digitalWrite(bjtBasePin, HIGH);

  // Send RC5 infrared signal with data code 0x1 and 8 bits
  //irsend.sendRC5(0x1, 8, 0);

  //delay(200);

  // Turn off the BJT
  //digitalWrite(bjtBasePin, LOW);

  //delay(500); // Wait for 5 seconds before transmitting again
