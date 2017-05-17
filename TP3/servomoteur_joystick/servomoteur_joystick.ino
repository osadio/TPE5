#include <Servo.h>  // Importation de la librairie servo

// Paramètres servomoteurs
Servo servomotor1;         //création instance d'un servomoteur
Servo servomotor2;         //création instance d'un servomoteur
const int servo1pin = 9;   // Numero de pin ou est relié le servomoteur 1 
const int servo2pin = 10;  // Numero de pin ou est relié le servomoteur 2
int angle1;                // Angle de rotation du servomoteur 1 (0-180)
int angle2;                // Angle de rotation du servomoteur 2 (0-180)
// Paramètres joystick
const int axeX = 1;        // nuemro de pin entrée analogique reliée à l'axeX 
const int axeY = 2;        // nuemro de pin entrée analogique reliée à l'axeY
const int bouton = 5;      // nuemro de pin entrée numérique reliée au bouton poussoir

void setup() 
{
    servomotor1.attach(servo1pin);
    servomotor2.attach(servo2pin);
    pinMode(bouton, INPUT);
}

void loop()
{
    delay(50);
    angle1 = map(analogRead(axeX), 0, 1023, 0, 180); // calcul angle servo1
    angle2 = map(analogRead(axeY), 0, 1023, 0, 180); // calcul angle servo2
    servomotor1.write(angle1);   // Envoie commande de rotation du servomoteur 1 
    servomotor2.write(angle2);   // Envoie commande de rotation du servomoteur 2
    if (digitalRead(bouton) == HIGH) {
       servomotor1.write(0);     // position de repos
       servomotor2.write(0);     // position de repos
    } 
    delay(100);  
}

