// the sensor communicates using SPI, so include the library:
#include <SPI.h>


// pins used for the connection with the sensor
// the other you need are controlled by the SPI library):
const int fSync = 10;

void setup() {
  Serial.begin(9600);

  // start the SPI library:
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
  // initalize the  data ready and chip select pins:
  delay(10);
  pinMode(fSync, OUTPUT);
  digitalWrite(fSync, HIGH);
  delay(10);

  digitalWrite(fSync, LOW);
  SPI.transfer(0x20);      //turns B28 - write 28bits to FREQ register
  SPI.transfer(0x00);
  digitalWrite(fSync, HIGH);
  delayMicroseconds(1);

  digitalWrite(fSync, LOW);
  SPI.transfer(0x4C);     //write 0x0C0F to 14LSB
  SPI.transfer(0x0F);
  digitalWrite(fSync, HIGH);
  delayMicroseconds(1);

  digitalWrite(fSync, LOW);
  SPI.transfer(0x70);     //write 0x30FF to 14MSB
  SPI.transfer(0xFF);
  digitalWrite(fSync, HIGH);
  delayMicroseconds(1);

  digitalWrite(fSync, LOW);
  SPI.transfer(0x00);      //Output sinewave
  SPI.transfer(0x00);
  digitalWrite(fSync, HIGH);
  delayMicroseconds(1);

  SPI.end();
}

void loop() {

}
