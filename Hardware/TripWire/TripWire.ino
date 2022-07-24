
#include <SharpIR.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int tick = 0;
RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
SharpIR sensor(GP2Y0A21YK0F, A0);

void setup()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600); 
}

void loop()

{
  
  int distance = sensor.getDistance(); 
  if (distance < 37) {
    tick += 1;
    if (tick > 2) {
      const char text[] = "ALERT!";
      radio.write(&text, sizeof(text));
    
 
     Serial.println("TRIPPED");
     
     for (int i = 0;i <62;i++) {
       tone(9,400);
       digitalWrite(5,HIGH);
         digitalWrite(4,HIGH);
         delay(80);
          digitalWrite(5,LOW);
         digitalWrite(4,LOW);
           noTone(9);
   
        delay(80);

     }
    }

      
    
  }
 else{
        tick = 0;
       }
  Serial.print(distance ); //Print the value to the serial monitor
  Serial.println(" CM");
//  delay(500);
}
