int trameNMEA;  // trame NMEA du GPS

void setup() {
  // Paramétrage module GPS & Arduino
  Serial.begin(9600);  // Interface serie ordinateur (USB)
  Serial2.begin(9600); // Interface serie GPS 
  delay(1000);
}
 
void loop() {
  if (Serial2.available()){      // Test disponibilité trame NMEA 
    trameNMEA = Serial2.read();  // récupération de la trame NMEA du GPS
    Serial.write(trameNMEA);     // Envoie de la trame en mode binaire trame vers l'ordinateur via USB
  }
}



