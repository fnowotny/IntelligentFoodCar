void display(){
  // Display
      tft.setCursor(0, 0, 2);  // Setzen des Cursors auf Position (0, 0) mit Schriftgröße 2
      tft.setTextColor(TFT_BLUE, TFT_BLACK);  // Textfarbe auf Blau mit schwarzem Hintergrund setzen
      tft.setTextSize(4);  // Schriftgröße auf 4 setzen
      tft.print("IFC");  // "IFC" auf dem Display ausgeben
      tft.println();  // Neue Zeile hinzufügen

      tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Textfarbe auf Weiß mit schwarzem Hintergrund setzen
      tft.setTextSize(2);  // Schriftgröße auf 2 setzen
      tft.print("PWM Wert: ");  // "Gewicht: " auf dem Display ausgeben
      tft.println(pwmwert);  // Gewichtswert auf dem Display ausgeben
      
      tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Textfarbe auf Weiß mit schwarzem Hintergrund setzen
      tft.setTextSize(2);  // Schriftgröße auf 2 setzen
      tft.print("Hindernis 1: ");  // "Gewicht: " auf dem Display ausgeben
      tft.println(hindernis1);  // Gewichtswert auf dem Display ausgeben
      
      tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Textfarbe auf Weiß mit schwarzem Hintergrund setzen
      tft.setTextSize(2);  // Schriftgröße auf 2 setzen
      tft.print("Hindernis 2: ");  // "Temperatur: " auf dem Display ausgeben
      tft.println(hindernis1);  // Temperaturwert auf dem Display ausgeben
}
