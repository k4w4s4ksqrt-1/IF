

 int trigPin = 4;                
 int echoPin = 5;              
 int led1 = 1;             
 int led2 = 2;          
 int led3 = 3;           
float distance = 0;              

void setup()
{
  Serial.begin (9600);        

  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);    
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  distance = getDistance();  

  Serial.print(distance);    

  if(distance <= 10){                        
    
    analogWrite(led1, 255);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    }

if(distance <= 20){       
    analogWrite(led1, 0);
    analogWrite(led2, 255);
    analogWrite(led3, 0);
    delay(50)
    analogWrite(led1, 0);
    analogWrite(led2, 255);
    analogWrite(led3, 0);
    delay(50)
    
  } if{                                    
    
    analogWrite(led1, 0);
    analogWrite(led2, 255);
    analogWrite(led3, 0);    
  }

  delay(50);      
}
float getDistance()
{
  float echoTime;                   
  float calcualtedDistance;        
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      
                                        

  calcualtedDistance = echoTime / 148.0;  
  return calcualtedDistance;             
}

