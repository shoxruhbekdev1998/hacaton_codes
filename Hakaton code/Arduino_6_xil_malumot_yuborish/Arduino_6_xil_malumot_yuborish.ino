#include <SD_ZH03B.h>
#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


SoftwareSerial ZHSerial(2,3);
SD_ZH03B ZH03B(ZHSerial, SD_ZH03B::SENSOR_ZH03B);

const int mq7Pin = A0;
const int fotoDirencPin = A1;

const int mq2Pin = A2;   
const float R0 = 9.83;

int son = 0;


void setup()
{

 Serial.begin(9600);
 ZHSerial.begin(9600);
 ZH03B.setMode(SD_ZH03B::IU_MODE);
  dht.begin();
pinMode(A1, INPUT);
}
 
void loop()
{


if (son = 3)
{




// char printbuf1[80];

//   if (ZH03B.readData()) {
//     Serial.print(ZH03B.getMode() == SD_ZH03B::IU_MODE ? "IU: " : "Savol va Javob: ");
//     sprintf(printbuf1, "PM1.0=[%d], PM2.5=[%d], PM10=[%d]", ZH03B.getPM1_0(), ZH03B.getPM2_5(), ZH03B.getPM10_0());
//     Serial.println(printbuf1);
//     delay(600);
//   }
 



if (ZH03B.readData()) {
    //if (ZH03B.getMode() == SD_ZH03B::IU_MODE) {
     
      Serial.println(ZH03B.getPM1_0());
      
      Serial.println(ZH03B.getPM2_5());
  
      Serial.println(ZH03B.getPM10_0());
       
  }
    else {
     
      Serial.println("1");
     
      Serial.println("1");
  
      Serial.println("1");
     }



//////////////////////////////////////////////////////////////////////


 float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  //Serial.print("Harorat: ");
  Serial.println(temperature);
  //Serial.println(" °C");
 // Serial.print("Namlik: ");
  Serial.println(humidity);
  //Serial.println(" %");


///////////////////////////////////////////////////////////



 int sensorValue = analogRead(mq7Pin);

  float voltage = sensorValue * (5.0 / 1023.0); 
  float ppm = 10.0 * ((voltage - 0.1) / 0.4); 
  
  //Serial.print("CO miqdori (PPM): ");
  Serial.println(ppm);

 
////////////////////////////////////////////////////////////////////// 


 int fotoDeger = analogRead(fotoDirencPin); 
  int lux = map(fotoDeger, 0, 1023, 0, 3000);  

  //Serial.print("Lux darajasi: ");
  Serial.println(lux);  



////////////////////////////////////////////////////////////////

 int sensorValue1 = analogRead(mq2Pin); 

  float sensorVoltage1 = sensorValue1 * (5.0 / 1023.0);  
  float sensorResistance1 = ((5.0 - sensorVoltage1) / sensorVoltage1) * R0; 
  float ppm1 = 1000 * (0.262 * pow(sensorResistance1 / R0, -1.23)); 

  //Serial.print("Gaz miqdori (PPM): ");
  Serial.println(ppm1);

  delay(2000); 





}

else {
son++;
delay(1000);
}

}
