/*
  Ecole Supérieure Polytehnique de Dakar
  DUT2TR & DST2TR 2016-2017
  Applications électroniques dédiées aux réseaux et télécommunications 
  TP1 – Montages électroniques à base d’Arduino
  # Application : Faire clignoter une LED
*/

// Déclaration des variriables
const int led = 5; // broche numérique où sera brachée la LED

void setup()
{
    // Configuration de la broche led en mode OUTPUT
    // C'est au microcontroleur de fournir le courant pour allumer la LED 
    pinMode(led, OUTPUT);
}

void loop()
{
    // Allumer la LED i.e envoyer 5V au pin 5
    digitalWrite(led, HIGH);
    // pause du programme durant 2s=2000ms
    delay(2000); 
    // Eteindre la LED i.e envoyer 0V au pin 5
    digitalWrite(led, LOW);
    // pause du programme durant 1s=1000ms
    delay(1000); 
}

