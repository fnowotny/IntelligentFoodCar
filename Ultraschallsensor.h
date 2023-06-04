unsigned long ultraschallmessung(unsigned long l_TRIG_PIN, unsigned long l_ECHO_PIN, unsigned long abstand) {
  digitalWrite(l_TRIG_PIN, HIGH);   // Trigger-Pin auf HIGH setzen, um die Messung auszulösen
  delayMicroseconds(10);  // Eine kurze Verzögerung von 10 Mikrosekunden
  digitalWrite(l_TRIG_PIN, LOW);  // Trigger-Pin auf LOW setzen, um die Messung zu beenden
  unsigned long dauer = pulseIn(l_ECHO_PIN, HIGH);  // Dauer des Echo-Signals messen und in der Variable "dauer" speichern
  abstand = dauer / 87;  // Berechnung des gemessenen Abstands
  Serial.printf("Abstand1 = %lu\n", abstand);  // Ausgabe des gemessenen Abstands über die serielle Schnittstelle
  return abstand;  // Den gemessenen Abstand zurückgeben
}
