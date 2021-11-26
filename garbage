/*
  Arduino Wireless Communication Tutorial
      Example 1 - Transmitter Code

  by Dejan Nedelkovski, www.HowToMechatronics.com

  Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#define echoPin 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 4 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  //const char text[] = "Hello World";
  //radio.write(&text, sizeof(text));
  //delay(1000);
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance <= 10)
  {
      const char text[] = "Dustbin is full";
      radio.write(&text, sizeof(text));
      Serial.println(text);
      delay(1000);
  }
  else
  {
      const char text[] = "Dustbin is empty";
      radio.write(&text, sizeof(text));
      Serial.println(text);
      delay(1000);
  }
}
