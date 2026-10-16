#include <Audio.h>


// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise;          //xy=532,325
AudioOutputI2S           i2s;            //xy=865,358
AudioConnection          patchCord1(noise, 0, i2s, 0);
AudioConnection          patchCord2(noise, 0, i2s, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=864,412
// GUItool: end automatically generated code


const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into


void setup(){
  
  AudioMemory(2);

    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    delay(200);
    noise.amplitude(1);
    Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  
  Serial.println("X");

}


void loop(){
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'X') {
      digitalWrite(ledPin, HIGH);
      noise.amplitude(1);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'x') {
      digitalWrite(ledPin, LOW);
      noise.amplitude(0);
    }
  }
}
