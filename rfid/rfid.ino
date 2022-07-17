 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int htci=0;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  Serial.println("************* HELLO, WELCOME TO BMSCE!*************");
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  
}


void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "64 AC 6D 1A") //change here the UID of the card/cards that you want to give access
  {
    
    Serial.println("AUTHORIZED ACCESS");
    if(htci==0)
    {
    Serial.println("Enabling pathway to Electricity") ; 
    analogWrite(A0,255);
    analogWrite(A1,0);
    Serial.println("You can go in, bro");
    htci=1;
    
    }
    else if (htci==1)
    {
      Serial.println("No Electricity Supplied") ; 
    analogWrite(A0,0);
    analogWrite(A1,255);
    Serial.println("Thank you for coming in");
    //delay(1000);
    htci=0;
    }
  }
 
 else   {
    Serial.println("ACCESS DENIED");
    Serial.println("TRY AGAIN");
    //delay(3000);
    mfrc522.PCD_Init();
    Serial.println("Approximate your card to the reader...");
    Serial.println();
  }
  delay(1000);
} 
