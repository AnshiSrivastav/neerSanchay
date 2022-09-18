// C++ code
//
int level = 0;

int water_level = 0;

int water_level2 = 0;

int rel_2 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(4, INPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop()
{
  water_level = 0.01723 * readUltrasonicDistance(3, 2);
  rel_2 = digitalRead(4);
  if (water_level > 336) {
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(4, HIGH);
    Serial.println(rel_2);
  }
  if (water_level < 336) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    Serial.println(rel_2);
  }
  digitalWrite(6, LOW);

  rel_2;
  delay(10); // Delay a little bit to improve simulation performance
}