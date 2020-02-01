const int trigPin = 14;
const int echoPin = 17;

// Definiramo spremenljivke.
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Nastavimo trigPin kot Output (izhod).
pinMode(echoPin, INPUT); // Nastavimo echoPin kot Input (vhod).
Serial.begin(9600); // Prične s komunikacijo.
}
void loop() {
// Pripravi trigPin.
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Nastavi trigPin na logično 'enko' za 5 mikro sekund.
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
// Odčita echoPin , vrne čas potovanja zvočnega signala (v mikrosekundah).
duration = pulseIn(echoPin, HIGH);
// Izračun prepotovane razdalje.
distance= duration*0.034/2;
// Izpiše razdaljo na uporabniškem vmesniku.
Serial.println(distance);
}
