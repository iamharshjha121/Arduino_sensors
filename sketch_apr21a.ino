#include <Adafruit_Sensor.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
#include <Adafruit_BMP280.h>
#include <DallasTemperature.h>
#include <DS1881.h>


#define pH_pin A0 
int temp_pin = 2;
int methane_pin = A1;
int moisture_pin = A2;
int Uv_pin = A3;
int scl_pin = A4;
int sda_pin = A5;
void setup()
{
  pinMode(pH_pin,INPUT); 
  pinMode(temp_pin,INPUT); 
  pinMode(methane_pin,INPUT); 
  pinMode(moisture_pin,INPUT); 
  pinMode(Uv_pin,INPUT);
  Serial.print("****Ready to star**** \n");
  Serial.begin(9600);
  sensors.begin();
   
}
void loop()
{
pH_sensor();//done
methane_sensor();//done
temperature_sensor();//done
moisture_sensor();//done
Uv_sensor();//done
pressure_sensor();
}
void ph_sensor()
{float pH = analogRead(pH_pin);
 pH = pH*5/1024/6;//convert analog value to millivolts
 pH = 3.5*pH // millivolt to pH
 Serial.print("pH value = ", +pH)
 digitalWrite(13,HIGH);// the led at digital pin 13 , will glow 
 delay(800);
 digitalWrite(13,LOW);
 Serial.print("pH :"+pH);
 return 0 ;
 }
 void temperature_sensor( )
 { sensors.requestTemperatures(); // command to get temperature reading. we need to download few libraries to make sure this sensor works. need to download a library for this one
   Serial.print("temperature is:");
   Serial.print(sensors.getTempCByIndex(0));
   delay(1000);
   return 0;
 }
void methane_sensor()
{ int threshold= 250;
  int green_pin=4;
  int red_pin = 5;
  float concentration = analogRead(methane_pin);
  Serial.print("Value= "+ concentration);
  if(concentration>=threshold)
  {digitalWrite(red_pin,HIGH);
   digitalWrite(green_pin,LOW);
  delay(200);
  }
  else
  {
  digitalWrite(green_pin,HIGH);
  delay(200);
  digitalWrite(red_pin,LOW);
  }
  Serial.write("concentration: "+conccentration);
  return 0;
  
 }
 void moisture_sensor()
 {
  int output = analogRead(moisture_pin);
  output = map(output_value,550,10,0,100); // for the dry sample it gives the output of 550 and for a wet soil it gives a output of 10 therefore this function map converts the value obtained between 0-100.
  Serial.print("moisture pin:");
  Serial.print(output+"%");
  delay(1000);
  return 0;
 }
 void Uv_sensor()
 {
int UVIndex;  
float value = analogRead(moisture_pin);
float voltage = (voltage* (5.0 / 1023.0))*1000;  //Voltage in miliVolts  
 if(voltage<50)
  {
    UVIndex = 0;
  }else if (voltage>50 && voltage<=227)
  {
    UVIndex = 0;
  }else if (voltage>227 && voltage<=318)
  {
    UVIndex = 1;
  }
  else if (voltage>318 && voltage<=408)
  {
    UVIndex = 2;
  }else if (voltage>408 && voltage<=503)
  {
    UVIndex = 3;
  }
  else if (voltage>503 && voltage<=606)
  {
    UVIndex = 4;
  }else if (voltage>606 && voltage<=696)
  {
    UVIndex = 5;
  }else if (voltage>696 && voltage<=795)
  {
    UVIndex = 6;
  }else if (voltage>795 && voltage<=881)
  {
    UVIndex = 7;
  }
  else if (voltage>881 && voltage<=976)
  {
    UVIndex = 8;
  }
  else if (voltage>976 && voltage<=1079)
  {
    UVIndex = 9;
  }
  else if (voltage>1079 && voltage<=1170)
  {
    UVIndex = 10;
  }else if (voltage>1170)
  {
    UVIndex = 11;
  }
  Serial.write("UVIndex :"+UVIndex);
  return 0;
 }
 // adafruit and onewire libraries are needed for operating this one
 void pressure_sensor()
 { float Po=1013;
   float pressure_value = bmp.readPressure();
   Serial.write("pressure :"+pressure);
   float temperature_value = bmp.readTemperature();  
     Serial.write("temperature  :"+temperature_value);
   float  alt = bmp180.altitude(pressure_value, Po);
     Serial.write("altitude :"+alt);
     return 0;

 }
