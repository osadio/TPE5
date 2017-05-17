/*
  Ecole Supérieure Polytehnique de Dakar
  DUT2TR & DST2TR 2016-2017
  Applications électroniques dédiées aux réseaux et télécommunications 
  TP1 – Montages électroniques à base d’Arduino
  # Application : Commander une LED et un buzzer à l’aide d’un bouton poussoir
*/

// Déclaration des variriables
const int led = 5;    // broche numérique ou sera branchéd la LED
const int buzzer = 8; // broche numérique ou sera branchée le buzzer  
const int bouton = 2; // broche numérique ou sera branchée le bouton poussoir  
int etatBouton;       // conserve l'état du bouton cad appuie ou relache

void setup()
{
    pinMode(led, OUTPUT);     // C'est le microcontrôleur qui fournit le courant à la LED
    pinMode(buzzer, OUTPUT);  // C'est le microcontrôleur qui fournit le courant au buzzer
    pinMode(bouton, INPUT);   // Le microcontrôleur recoit un courant (signal) issue du bouton 
    digitalWrite(bouton, HIGH); // Activation pull-up interne
}

void loop()
{
    // Lecture état bouton, deux valeurs possibles : LOW ou HIGH
    etatBouton = digitalRead(bouton);
    if (etatBouton == LOW){ // Appuie du bouton
        // On allume la LED
        digitalWrite(led, HIGH);
        // On active le buzzer avec une fréquence de 400Hz
        tone(buzzer, 400);
    }else{ // Relache du bouton
        // On étteint la LED
        digitalWrite(led, LOW);
        // On désactive le buzzer
        noTone(buzzer);
    }
}


