const int photoresistance = 0;  // numero pin photoresistance
const int LED = 3;              // numero pin LED
float rn_luminosite;            // valeur numerique conversion 0-1023
float seuil = 35;               // correspond à l'obscurité

void setup()
{
    pinMode(LED, OUTPUT);       
    Serial.begin(9600);         // initialisation communication serie à 9600 bauds   
}

void loop(){
   rn_luminosite = analogRead(photoresistance);  // lecture de la valeur numerique Rn
   if (rn_luminosite <= seuil){  // Si on est dans l'obscurité
       digitalWrite(LED, HIGH);  // On allume la lumiere
   }else{                        // Sinon 
       digitalWrite(LED, LOW);   // On éteint la LED
   }
   Serial.print("mesure : ");    // Affichage sur le moniteur série
   Serial.println(rn_luminosite); 
   delay(1000);
}


