int buzzer = 5;       // numero pin buzzer
int capteurHall = 3;  // numero pin hall

void setup () {
  pinMode(buzzer, OUTPUT);
  pinMode(capteurHall, INPUT);
}

void loop () {
   if (digitalRead(capteurHall) == LOW){ // champ magnétique détecté (pole Sud)
      tone(buzzer, 2200);  // Activation du buzzer
   } else { // Pole Nord
      noTone(buzzer);      // desactivation du buzzer
   }
}

