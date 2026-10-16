#include <Audio.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputUSB usb1;          //xy=297,198
AudioSynthNoiseWhite noise;  //xy=350,122
AudioMixer4 mixer1;          //xy=478,189
AudioOutputI2S i2s;          //xy=683,155
AudioConnection patchCord1(usb1, 0, mixer1, 2);
AudioConnection patchCord2(usb1, 1, mixer1, 3);
AudioConnection patchCord3(noise, 0, mixer1, 0);
AudioConnection patchCord4(noise, 0, mixer1, 1);
AudioConnection patchCord5(mixer1, 0, i2s, 0);
AudioConnection patchCord6(mixer1, 0, i2s, 1);
AudioControlSGTL5000 sgtl5000_1;  //xy=682,209
// GUItool: end automatically generated code



const int ledPin = 13;  // the pin that the LED is attached to
int incomingByte;       // a variable to read incoming serial data into


void setup() {

  AudioMemory(2);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  mixer1.gain(0, 1.0);
  delay(200);
  noise.amplitude(1);
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);


  Serial.println("X");
}


void loop() {
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
