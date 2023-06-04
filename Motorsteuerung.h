int Regler1 = 30;  // Eine Variable zur Regelung des linken Motors
int Regler2 = 10;  // Eine Variable zur Regelung des rechten Motors

// Fahrfunktionen für Motor
void backward() {
  // Motor A rückwärts
  digitalWrite(In1, LOW);   // In1 auf LOW setzen
  digitalWrite(In2, HIGH);  // In2 auf HIGH setzen
  analogWrite(EnA, pwmwert);  // PWM-Wert auf EnA setzen
  // Motor B rückwärts
  digitalWrite(In3, LOW);   // In3 auf LOW setzen
  digitalWrite(In4, HIGH);  // In4 auf HIGH setzen
  analogWrite(EnB, pwmwert);  // PWM-Wert auf EnB setzen
}

void forward() {
  // Motor A vorwärts
  digitalWrite(In1, HIGH);  // In1 auf HIGH setzen
  digitalWrite(In2, LOW);   // In2 auf LOW setzen
  analogWrite(EnA, pwmwert);  // PWM-Wert auf EnA setzen
  // Motor B vorwärts
  digitalWrite(In3, HIGH);  // In3 auf HIGH setzen
  digitalWrite(In4, LOW);   // In4 auf LOW setzen
  analogWrite(EnB, pwmwert);  // PWM-Wert auf EnB setzen
}

void stop_motors() {
  // Beide Motoren stoppen
  digitalWrite(In1, LOW);   // In1 auf LOW setzen
  digitalWrite(In2, LOW);   // In2 auf LOW setzen
  analogWrite(EnA, pwmwert);  // PWM-Wert auf EnA setzen
  digitalWrite(In3, LOW);   // In3 auf LOW setzen
  digitalWrite(In4, LOW);   // In4 auf LOW setzen
  analogWrite(EnB, pwmwert);  // PWM-Wert auf EnB setzen
}

// Bessere Kurven
void turn_left() {
  // Motor A nach links drehen
  digitalWrite(In1, HIGH);  // In1 auf HIGH setzen
  digitalWrite(In2, LOW);   // In2 auf LOW setzen
  analogWrite(EnA, (pwmwert + Regler1));  // PWM-Wert mit Regler1 erhöhen und auf EnA setzen
  // Motor B nach rechts drehen
  digitalWrite(In3, HIGH);  // In3 auf HIGH setzen
  digitalWrite(In4, LOW);   // In4 auf LOW setzen
  analogWrite(EnB, (pwmwert - Regler2));  // PWM-Wert mit Regler2 verringern und auf EnB setzen
}

void turn_right() {
  // Motor A nach rechts drehen
  digitalWrite(In1, HIGH);  // In1 auf HIGH setzen
  digitalWrite(In2, LOW);   // In2 auf LOW setzen
  analogWrite(EnA, (pwmwert - Regler2));  // PWM-Wert mit Regler2 verringern und auf EnA setzen
  // Motor B nach links drehen
  digitalWrite(In3, HIGH);  // In3 auf HIGH setzen
  digitalWrite(In4, LOW);   // In4 auf LOW setzen
  analogWrite(EnB, (pwmwert + Regler1));  // PWM-Wert mit Regler1 erhöhen und auf EnB setzen
}

//Rückwärtskurven
void turn_left_back() {
  // Motor A
  digitalWrite(In1, LOW);   // In1 auf LOW setzen
  digitalWrite(In2, HIGH);  // In2 auf HIGH setzen
  analogWrite(EnA, (pwmwert+Regler1)); // PWM-Wert mit Regler1 ehöhen und auf EnA setzen
  // Motor B
  digitalWrite(In3, LOW);   // In3 auf LOW setzen
  digitalWrite(In4, HIGH);  // In4 auf HIGH setzen
  analogWrite(EnB, (pwmwert-Regler2)); // PWM-Wert mit Regler2 erhöhen und auf EnB setzen
}

void turn_right_back() {
  // Motor A
  digitalWrite(In1, LOW);   // In1 auf HIGH setzen
  digitalWrite(In2, HIGH);  // In2 auf LOW setzen
  analogWrite(EnA, (pwmwert-Regler2)); // PWM-Wert mit Regler2 verringern und auf EnA setzen
  // Motor B
  digitalWrite(In3, LOW);   // In3 auf LOW setzen
  digitalWrite(In4, HIGH);  // In4 auf HIGH setzen
  analogWrite(EnB, (pwmwert+Regler1)); // PWM-Wert mit Regler1 erhöhen und auf EnB setzen
}
