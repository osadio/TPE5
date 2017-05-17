#include <TinyGPS++.h>  // Importation de la bibliothèque 

TinyGPSPlus gps; // créer un instance TinyGPS++

void setup() {
  Serial.begin(9600);  // Interface série ordinateur (USB)
  Serial2.begin(9600); // Interface série GPS
  delay(1000);
}

void loop() {
  while (Serial2.available() > 0){      // Tant des données sont disponibles sur l'interface série
    if (gps.encode(Serial2.read())){    // Fournir à l’instance TinyGPS les données recueillies du GPS
       if (gps.location.isUpdated()) {  // Si les données de l’instance TinyGPS sont à jour 
          // Affichage des informations GPS
          Serial.print("LAT="); Serial.print(gps.location.lat(), 6);
          Serial.print("LNG="); Serial.println(gps.location.lng(), 6);
          Serial.print("ALT="); Serial.println(gps.altitude.meters());
          Serial.print("VIT="); Serial.println(gps.speed.mps());
          Serial.print("SAT="); Serial.println(gps.satellites.value());     
       }
    }
  }
}

