#include <IRremote.h>

// Define the pins
int irLedPin = 13;      // IR LED anode (+) connected to the collector
int bjtBasePin = 2;     // BJT base pin
int photodiodePin = 7;  // Digital pin for photodiode

IRsend irsend(2);

bool transmitted = false;  // Variable to track whether transmission has occurred

void setup() {
  // Set the pin modes
  pinMode(irLedPin, OUTPUT);
  pinMode(bjtBasePin, OUTPUT);
  pinMode(photodiodePin, INPUT);
}

void loop() {
  if (digitalRead(photodiodePin) == HIGH && !transmitted) {
    // Turn on the BJT to allow current to flow to the IR LED
    digitalWrite(bjtBasePin, HIGH);

    // Send your IR signal
    irsend.sendSony(0x1, 12);
    delay(200);

    // Turn off the BJT to stop the current flow to the IR LED
    digitalWrite(bjtBasePin, LOW);

    delay(200);

    transmitted = true;  // Set the flag to true after transmission
  } else if (digitalRead(photodiodePin) == LOW && transmitted) {
    // Turn on the BJT to allow current to flow to the IR LED
    digitalWrite(bjtBasePin, HIGH);

    // Send your IR signal
    irsend.sendSony(0x1, 12);
    delay(200);

    // Turn off the BJT to stop the current flow to the IR LED
    digitalWrite(bjtBasePin, LOW);

    delay(200);
    transmitted = false;
  }

  // Wait without transmitting
  delay(500); // Adjust the delay as needed
}
