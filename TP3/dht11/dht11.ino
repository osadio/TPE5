#include <dht11.h>         // Importer la librairie dht11

dht11 DHT;                 // Creation d'une instance dht11
const int capteurDHT = 2;  // Numero pin du capteur DHT11
int temperature;           // Valeur mesuré de la temperature
int luminosite;            // Valeur mesuré de la luminosité
 
void setup()
{
   Serial.begin(9600);     // initialisation communication serie à 9600 bauds  
}
 
void loop()
{
  int chk;
  chk = DHT.read(capteurDHT);     // Decodage de la trame de donnée DHT
  temperature = DHT.temperature;  // Récupération de la valleur de la temperature
  luminosite = DHT.humidity;      // Récupération de la valleur de la luminosité
  Serial.println("Temperature : " + String(temperature));  // affichage sur le moniteur série 
  Serial.println("Humidite : " + String(luminosite)); 
  delay(1000);
}

