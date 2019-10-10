/* 
 * A Relay control script utilising a Real Time Clock
 * 
 * Author: Phil Ashby
 * Modified: 10-10-2019
 */ 


#include <DS3231.h>

const int Relay1 = 2;
const int Relay2 = 3;
const int Relay3 = 4;
const int Relay4 = 5;

DS3231  rtc(SDA, SCL);
Time t;

// Set time for activationg relays 1 and 2
const int OnOpenHour = 8;
const int OnOpenMin = 0;

// Set time for deactivating relays 1 and 2
const int OffOpenHour = 8;
const int OffOpenMin = 2;

// Set time for activating relays 3 and 4
const int OnCloseHour = 21;
const int OnCloseMin = 0;

// Set time for deactivating relays 3 and 4
const int OffCloseHour = 21;
const int OffCloseMin = 2;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1,HIGH);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);
  pinMode(Relay3, OUTPUT);
  digitalWrite(Relay3, HIGH);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay4, HIGH);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  delay (1000);

  if(t.hour == OnOpenHour && t.min == OnOpenMin){
    digitalWrite(Relay1,LOW);
    digitalWrite(Relay2,LOW);
    Serial.println("DOOR OPENING");
    }
    
    else if(t.hour == OffOpenHour && t.min == OffOpenMin){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Serial.println("DOOR OPEN");
    }
    
    else if(t.hour == OnCloseHour && t.min == OnCloseMin){
      digitalWrite(Relay3,LOW);
      digitalWrite(Relay4,LOW);
      Serial.println("DOOR CLOSING");
    }

    else if(t.hour == OffCloseHour && t.min == OffCloseMin){
      digitalWrite(Relay3,HIGH);
      digitalWrite(Relay4,HIGH);
      Serial.println("DOOR CLOSED");
    }
}
