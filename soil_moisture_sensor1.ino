// C++ code
//
int moisture_data = 0;

int relay = 0;

void setup()
{
  pinMode(4, INPUT);
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  relay = digitalRead(4);
  moisture_data = analogRead(A0);
  if (moisture_data < 24) {
    digitalWrite(4, HIGH);
    Serial.println(relay);
  } else {
    digitalWrite(4, LOW);
    Serial.println(relay);
  }

  digitalWrite(4, LOW);
  Serial.println(relay);
  delay(10); // Delay a little bit to improve simulation performance
}