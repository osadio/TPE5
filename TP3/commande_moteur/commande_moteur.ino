const int commandeMoteur = 11; // numero pin de commande du moteur
const int bouton = 2;          // numero pin du boutton poussoir
int etatBouton;                // etat du boutton ; appuyé ou relaché

void setup()
{
    pinMode(commandeMoteur, OUTPUT);
    pinMode(bouton, INPUT); 
    digitalWrite(bouton, HIGH); // Activation pull-up interne
}

void loop() 
{
    etatBouton = digitalRead(bouton);  // Determination de l'état du boutton
    if (etatBouton == LOW){ // Appuie du bouton
        digitalWrite(commandeMoteur, HIGH); // Demarrer le moteur  
    }else{ // Relache du bouton
        digitalWrite(commandeMoteur, LOW); // Arreter le moteur
    }
}

