const int thermometre = 2; // numero pin thermometre
float rn_thermometre;      // valeur numerique conversion 0-1023
float tension;             // tension analogique correspondante 0-5000mV
int temperature;           // Temperature correspndante

void setup(){
    Serial.begin(9600);    // initialisation communication serie à 9600 bauds  
}

void loop(){
    rn_thermometre = analogRead(thermometre);        // lecture de la valeur numerique Rn 
    tension = map(rn_thermometre, 0, 1023, 0, 5000); // on en déduit la valeur analogique (tension)
    temperature = tension/10;                        // temperature correspondante (10mV -> 1°C)
    Serial.print("Temp °C: ");                       // affichage sur le moniteur série 
    Serial.println(temperature);
    delay(1000);
}

