# Bewegungsmelder

Dieses Projekt ist ein einfaches Bewegungserkennungssystem, das einen Buzzer und eine LED zur Signalisierung verwendet. Es wurde für Bildungszwecke an der HSHL für den Studiengang Intelligent Systems Design entwickelt, um Einsteiger*innen in die Welt der Embedded Systems einzuführen. Das System erkennt Bewegungen über einen Sensor und löst bei Aktivität sowohl eine akustische als auch eine visuelle Warnung aus.

## Komponenten

- **Arduino Uno**: Mikrocontroller-Board
- **Bewegungssensor (PIR-Sensor)**: Erkennt Bewegung in einem definierten Bereich
- **Buzzer**: Gibt bei erkannter Bewegung einen Warnton aus
- **LED**: Leuchtet bei erkannter Bewegung auf
- **Verbindungskabel**: Zum Anschluss der Komponenten an das Arduino-Board

## Verkabelung

Die Komponenten werden wie folgt mit dem Arduino verbunden:

- Buzzer:
	- VCC an 3.3V
 	- GND an GND		 
	- I/O an 6
- LED:
  - GND an 2
  - SIG an 3 	
- Bewegungsmelder:
  Wenn der Sensor nach oben und die Anschlüsse zu einem zeigen, dann… 
	- linker Anschluss an GND 
 	- mittlerer Anschluss an 7
  - rechter Anschluss an 5V 

## Codeerklärung

### Setup-Funktion

Die `setup()`-Funktion initialisiert die seriellen Kommunikation, konfiguriert die Pins für Buzzer, Bewegungssensor und LED und schaltet die LED initial aus.

```cpp
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
```

### Hauptprogramm (Loop)

In der `loop()`-Funktion wird kontinuierlich überprüft, ob der Bewegungssensor eine Bewegung erkennt. Wenn eine Bewegung erkannt wird, leuchtet die LED auf und der Buzzer gibt einen Ton ab. Wird keine Bewegung erkannt, bleiben LED und Buzzer ausgeschaltet.

```cpp
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
```

### Konzeption

Dieses Projekt ist ideal für den Einstieg in die Arbeit mit Mikrocontrollern und sensorbasierten Systemen. Es kann als Grundlage für komplexere Alarmsysteme verwendet werden, bei denen beispielsweise mehrere Sensoren integriert oder die Ausgaben über eine drahtlose Verbindung übertragen werden. Das System ist einfach aufzubauen und eignet sich gut für Demonstrationen in Bildungseinrichtungen oder bei Workshops.

**Erweiterungsmöglichkeiten**:
- Integration eines LCD-Displays zur Anzeige von Warnmeldungen
- Verwendung eines drahtlosen Moduls (z.B. Wi-Fi oder Bluetooth) zur Übertragung von Alarmmeldungen an ein Smartphone
- Hinzufügen weiterer Sensoren (z.B. Temperatursensoren) zur Erfassung weiterer Umgebungsparameter
