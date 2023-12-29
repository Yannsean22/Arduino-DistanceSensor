#include <LiquidCrystal_I2C.h>

//Display -- 16x2 (But I think it would would work the same with 20x4 I2C )
#define I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

//RBG
const int red = 2;
const int green = 3;
const int blue = 4;

//Sensor
const int trig = 13;
const int echo = 12;

//ouput choice
int indicator = 5;


void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(indicator, OUTPUT);

  lcd.begin(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);
  lcd.setBacklight(HIGH);

   // Plays 262Hz tone for 0.250 seconds

  
}

void loop(){
   // Trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the duration of the echo pulse
  long duration = pulseIn(echo, HIGH);

  // Convert the duration to distance (in centimeters)
  // Speed of sound is 343 meters per second, or 0.0343 cm/microsecond
  float distance = (duration * 0.0343) / 2;

  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.setCursor(9,0);
  lcd.print(distance);

   if(distance < 25){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);

    digitalWrite(indicator, HIGH);
    tone(5, 262);
    delay(100);
    digitalWrite(indicator, LOW);
    noTone(5);
    delay(100);

  }else if(distance < 50){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);

    digitalWrite(indicator, HIGH);
    tone(indicator, 262);
    delay(250);
    digitalWrite(indicator, LOW);
    noTone(indicator);
    delay(250);

  } else if(distance < 100){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);

    digitalWrite(indicator, HIGH);
    tone(indicator,262);
    delay(500);
    digitalWrite(indicator, LOW);
    noTone(indicator);
    delay(500);

  }else if(distance < 200){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);

    digitalWrite(indicator, HIGH);
    tone(indicator,262);
    delay(750);
    digitalWrite(indicator, LOW);
    noTone(indicator);
    delay(750);

  }else {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(indicator, LOW);
  }

}