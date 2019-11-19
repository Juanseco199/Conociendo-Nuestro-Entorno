

/*Incluir librerias de arduino DHT sensor library y 
 * Adafruit Unified Sensor 
 * MQ 135 a A0
 * MQ 4 a A1 
 * DHT 22 a 2
 * BMP180 a I2C
 */

#include <Wire.h>
#include <SPI.h>

#include <DHT.h>
#include <DHT_U.h> 

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);  

Adafruit_BMP280 bmp;

int valormq135 = 0;
int valormq4 = 1;

float TEMPERATURA;
float HUMEDAD;

float PRESION;

void setup() {
 Serial.begin(9600);
 dht.begin();
 
}

void loop() {
  valormq135 = analogRead(A0);  //lectura mq 135
  Serial.print("Dióxido de carbono: ");
  Serial.print(valormq135); 
  Serial.println(" CO2");
  
  valormq4 = analogRead(A1); //lectura mq 4
  Serial.print(" Metano: ");
  Serial.print(valormq4);
  Serial.println(" CH4"); 
  
  TEMPERATURA = dht.readTemperature(); //Lectura DHT11
  HUMEDAD = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.println(" °C");
  
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);

  PRESION = bmp.readPressure()/0.00098692326671601;  //Lectura BMP180
  Serial.print(" Presion: ");      
  Serial.print(PRESION);      
  Serial.println(" atm");    

  delay(5000);  
}

