const int echoPin = 10;    // numero de pin pour l'emission d'ultrason 
const int triggerPin = 11; // numero pin pour réception de l'echo
long duree;                // duree impulsion
int distance;              // distance de l'obstacle

void setup() {
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(triggerPin, HIGH);  // Emission ultrason
  delayMicroseconds(10);           // Pause de 10us
  digitalWrite(triggerPin, LOW);   // Arret emission ultrason
  duree = pulseIn(echoPin, HIGH);  // Mesure duree impulsion
  distance = duree*0.034/2;        // Calcul distance
  Serial.println("Obstacle a : " + String(distance)); 
}

