/*
  Ecole Supérieure Polytehnique de Dakar
  DUT2TR & DST2TR 2016-2017
  Applications électroniques dédiées aux réseaux et télécommunications 
  TP1 – Montages électroniques à base d’Arduino
  # Application : lecture et affichage d’une tension analogique
*/

// Déclaration des variriables
const int pinPotentiometre = 5; // broche analogique où sera reliée le ponteniomètre 
int Rn; 
int Ve; 

void setup() 
{ 
     // Initialisation de la communication série
     Serial.begin(9600);
}

void loop() 
{ 
     // Lecture de la valeur numérique sur la broche où est reliée le potentiomètre
     Rn = analogRead(pinPotentiometre); 
     // On tire la valeur analogique correspondante en mV
     Ve = map(Rn, 0, 1023, 0, 5000);     
     // On affiche le résultat sur l'interface série
     Serial.println("Tension (mV): "+String(Ve));
     // On met en pause le programmme durant 200ms
     delay(200);
}


