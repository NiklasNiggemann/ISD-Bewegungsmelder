// Definition der Pin-Nummern für die angeschlossenen Komponenten
int buzzer = 6;        // Pin für den Buzzer
int motion = 7;        // Pin für den Bewegungssensor
int led = 3;           // Pin für die LED
int ledGround = 2;     // Pin für die Erdung der LED (Optional, abhängig von der Schaltung)

void setup() 
{
  // Initialisiert die serielle Kommunikation mit einer Baudrate von 9600 bps
  Serial.begin(9600);
  
  // Setzt den Buzzer-Pin als Ausgang
  pinMode(buzzer, OUTPUT);
  
  // Setzt den Bewegungssensor-Pin als Eingang
  pinMode(motion, INPUT);
  
  // Setzt den LED-Pin als Ausgang
  pinMode(led, OUTPUT);
  
  // Setzt den Erdungs-Pin der LED als Ausgang (optional)
  pinMode(ledGround, OUTPUT);
  
  // Setzt den Erdungs-Pin der LED auf LOW (optional, um die LED auszuschalten)
  digitalWrite(ledGround, LOW); 
}

void loop() 
{
  // Überprüft, ob der Bewegungssensor eine Bewegung erkannt hat
  if (digitalRead(motion) == HIGH) // HIGH bedeutet, dass eine Bewegung erkannt wurde
  {
    Serial.println("Motion!");     // Gibt eine Nachricht über die serielle Verbindung aus
    digitalWrite(led, HIGH);       // Schaltet die LED ein
    tone(buzzer, 20);              // Aktiviert den Buzzer mit einer Frequenz von 20 Hz
  }
  else // Wenn keine Bewegung erkannt wird
  {
    digitalWrite(led, LOW);        // Schaltet die LED aus
    noTone(buzzer);                // Deaktiviert den Buzzer
  }
}