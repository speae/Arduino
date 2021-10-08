const int trigPin = 11;
const int echoPin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;

  Serial.print(timeDistance);
  Serial.println("㎲");
  
  Serial.print(distance);
  Serial.println("cm");
}
