 #include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

 LiquidCrystal_I2C lcd(0x27,16,2);

int pinDHT11 = 2;
SimpleDHT11 dht11;

int sensor = A0;
int gaz;

void setup() {
  //Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  Serial.begin(9600);
  pinMode(3, OUTPUT);
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
pinMode(9, OUTPUT);
pinMode(A0, INPUT);
digitalWrite(3, 1);
}

void loop() {


gaz = analogRead(sensor);

Serial.println(gaz);
delay(100);


if (gaz > 150)
{


digitalWrite(4, 1);
digitalWrite(2, 0);
tone(9, 1300);
delay(300);
digitalWrite(4, 0);
digitalWrite(2, 1);

digitalWrite(3, 0);
delay(300);
noTone(9);

lcd.clear();
lcd.setCursor(1, 0);
lcd.print("Hona malumoti");
lcd.setCursor(0, 1);
lcd.print("Is gaz: " );
lcd.setCursor(8, 1);
lcd.print(gaz);
lcd.setCursor(12, 1);
lcd.print("PPM" );


}
else
{
lcd.clear();
lcd.setCursor(1, 0);
lcd.print("Hona malumoti");
lcd.setCursor(0, 1);
lcd.print("Is gaz: " );
lcd.setCursor(8, 1);
lcd.print(gaz);
lcd.setCursor(12, 1);
lcd.print("PPM" );


noTone(9);
digitalWrite(2, 0);
digitalWrite(3, 1);

digitalWrite(4, 0);
delay(300);
}



  
  
  
}
