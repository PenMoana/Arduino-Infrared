#include "IRremote.hpp"
int IrReceiverPin = 2;
int ledPin = 13;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  IrReceiver.begin(IrReceiverPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    switch (command) {
      case 69:
        Serial.println("you pressed button 1");
        break;
      case 70:
        Serial.println("you pressed button 2");
        break;
      case 71:
        Serial.println("you pressed button 3");
        break;
    }
    delay(100);
    IrReceiver.resume();
  }
}
