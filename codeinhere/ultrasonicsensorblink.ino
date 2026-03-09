int trigPin = 4;
int echoPin = 5;
int led1 = 2; 
int led2 = 3; 
int led3 = 6; 

float distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  distance = getDistance();
  Serial.println(distance);

  if(distance > 20){ 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(50); 
  }
  else if(distance > 10){ 
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(500); 
    digitalWrite(led2, LOW);
    delay(500); 
  }
  else{ 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100); 
    digitalWrite(led3, LOW);
    delay(100); 
  }
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float echoTime = pulseIn(echoPin, HIGH);
  float calculatedDistance = echoTime / 148.0; 
  return calculatedDistance;
}