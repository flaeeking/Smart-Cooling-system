#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int motorpin = 19;
const int motorpin2 = 18;
const int pwmotorpin = 4;
const int trigpin = 2;
const int echopin = 5;
const int thermpin = 15;
const int buttonpin = 23;

int duration;
int distance;

const int pwmchanal = 0;
const int freq = 2000;
const int pwmresolution = 8;

void setup() {
  pinMode(motorpin, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(thermpin, INPUT);
  pinMode(buttonpin, INPUT);
  ledcSetup(pwmchanal, freq, pwmresolution);
  ledcAttachPin(pwmotorpin, pwmchanal);

  digitalWrite(motorpin, LOW);
  digitalWrite(motorpin2, HIGH);
  Serial.begin(9600);
   
  Wire.begin(21, 22); 
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display();
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH, 30000);

 if(duration == 0){
    distance = 999;
 }
 else{
    distance = duration * 0.034 / 2;
 }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  display.setCursor(0,0);
  display.println("Distance Measurement");

  int temperature = analogRead(thermpin);
  int buttonState = digitalRead(buttonpin);
  Serial.print("Button: ");
  Serial.println(buttonState);
  temperature = map(temperature, 1000, 3500, 0, 67);
  Serial.print("Temperature: ");
  Serial.print(temperature);  
  Serial.println(" °C");
  if (distance < 10 && buttonState == LOW) {
    ledcWrite(pwmchanal, 255);
    Serial.println("Object detected!");
    display.clearDisplay();
    display.setCursor(0,18);
    display.println("Object is too close!");

    display.println("Distance: ");
    display.print(distance);

    display.setCursor(0,10);
    display.println("FAST"); 

    display.setCursor(0,44);
    display.println("Temperature: "); 
    display.print(temperature);
    display.print(" C");
    display.display();  
  }

 if (25 >= distance && distance >= 10 && buttonState == LOW) {
    ledcWrite(pwmchanal, 80);
    Serial.println("Object within range.");
    display.clearDisplay();
    display.setCursor(0,18);
    display.println("Object within range.");

    display.println("Distance: ");
    display.print(distance);
    display.setCursor(0,10);
    display.println("SLOW"); 

    display.setCursor(0,44);
    display.println("Temperature: "); 
    display.print(temperature);
    display.print(" C");
    display.display();
  }

  if (distance > 25 && buttonState == LOW) {
    ledcWrite(pwmchanal, 0);
    Serial.println("No object detected.");
    display.clearDisplay();
    display.setCursor(0,18);
    display.println("No object detected.");
    display.println("Distance: ");
    display.print(distance);
    display.setCursor(0,10);
    display.println("STOP");

    display.setCursor(0,44);
    display.println("Temperature: "); 
    display.print(temperature);
    display.print(" C");
    display.display();
  }

 if (buttonState == HIGH) {

    display.clearDisplay();

    display.setCursor(0,0);
    display.println("AUTO MODE");

    display.setCursor(0,15);
    display.print("Distance: ");
    display.println(distance);

    display.setCursor(0,30);
    display.print("Temp: ");
    display.print(temperature);
    display.println(" C");

    if (temperature > 27) {

        Serial.println("Temperature is too high!");

        display.setCursor(0,50);
        display.println("FAST");

        ledcWrite(pwmchanal, 255);
    }

    else if (temperature >= 20) {

        Serial.println("Temperature is normal.");

        display.setCursor(0,50);
        display.println("SLOW");

        ledcWrite(pwmchanal, 80);
    }

    else {

        Serial.println("Temperature is too low!");

        display.setCursor(0,50);
        display.println("STOP");

        ledcWrite(pwmchanal, 0);
    }

    display.display();
}
}