#include "IRremote.hpp"
int IrReceiverPin = 2;
int ledPin = 13;
int yellowLed = 10;
int greenLed = 9;
int redLed = 8;
void setup() {
  Serial.begin(9600);
  pinMode(yellowLed, OUTPUT); 
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT); 
  IrReceiver.begin(IrReceiverPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    switch (command) {
      case 69:
        digitalWrite(yellowLed, HIGH);
        break;
      case 70:
        digitalWrite(greenLed, HIGH);
        break;
      case 71:
        digitalWrite(redLed, HIGH);
        break;
    }
    delay(100);
    IrReceiver.resume();
  }
}
