/*
  Ecole Supérieure Polytehnique de Dakar
  DUT2TR & DST2TR 2016-2017
  Applications électroniques dédiées aux réseaux et télécommunications 
  TP1 – Montages électroniques à base d’Arduino
  # Application : communication série
*/

// Déclaration des variriables
const int led_rouge = 5; // broche numérique où sera brachée la LED rouge
const int led_verte = 8; // broche numérique où sera brachée la LED verte
const int code_secret = 8823;  // Le bon code
int code_saisi;          // Code saisi par l'utilisateur
boolean succes = false; 

void setup()
{
    // Configuration des broches des LED en mode OUTPUT
    pinMode(led_rouge, OUTPUT);
    pinMode(led_verte, OUTPUT);
    // Initialisation communication série
    Serial.begin(9600);
    Serial.println("Merci de saisir le code d'acces.");
}

void loop()
{
    if(Serial.available() > 0 && !succes) { // Si des données sont présentes sur l'interface série
        code_saisi = Serial.parseInt(); // Récupérer le code saisi
        if (code_saisi == code_secret){  // Si le code est correct
            // L'utilisateur a entrer le bon code
            succes = true;
            // On etteint la LED rouge            
            digitalWrite(led_rouge, LOW);
            // On allume la LED verte
            digitalWrite(led_verte, HIGH);
            // On affiche le message de succès
            Serial.println("Authentification reussie!");
        }
        else{ // Si le code est erroné                                
            // On etteint la LED verte
            digitalWrite(led_verte, LOW);
            // On allume la LED rouge            
            digitalWrite(led_rouge, HIGH);
            // On affiche le message d'erreur
            Serial.println("Erreur! code saisi errone");
        }
    }
}


