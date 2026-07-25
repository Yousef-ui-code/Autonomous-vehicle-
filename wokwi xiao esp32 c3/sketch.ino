#include <ESP32Servo.h>

Servo servo_drive_l;  
Servo servo_drive_r;  
Servo servo_steer;    

const int drive_l_pin = D0;
const int drive_r_pin = D1;
const int steer_pin = D2;
const int led_pin = D3;
const int ldr_pin = D4; 

unsigned long previousMillis = 0;
const long interval = 200; 
bool ledState = LOW;

void setup() {
  Serial.begin(115200);

  servo_drive_l.attach(drive_l_pin);
  servo_drive_r.attach(drive_r_pin);
  servo_steer.attach(steer_pin);

  pinMode(led_pin, OUTPUT);
  servo_steer.write(90); 
}

void loop() {
  int ldr_value = analogRead(ldr_pin);
  
  Serial.print("قراءة الحساس: ");
  Serial.println(ldr_value);

  unsigned long currentMillis = millis();

  if (ldr_value < 2000) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(led_pin, ledState);
    }
    
    servo_steer.write(45); 
    servo_drive_l.write(90); 
    servo_drive_r.write(90); 
  } 
  else {
    digitalWrite(led_pin, LOW);
    ledState = LOW;
    
    servo_steer.write(90); 
    servo_drive_l.write(180); 
    servo_drive_r.write(0);   
  }

  delay(50); 
}