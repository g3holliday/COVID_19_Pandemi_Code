const int redLed = 2;
const int blueLed = 3;

const int leftRev = 4;  //Left Motor -
const int leftFwd = 5;  //Left Motor +    
const int rightRev = 6; //Right Motor -    
const int rightFwd = 7; //Right Motor +

const int pirInput = 8;

const int trigPin = 9;      // trigPin of HC-SR04
const int echoPin = 10;     // echoPin of HC-SR04

const int uvOutput = 11;

const int ledPin = 13;                             
int pirState = LOW; 

long duration, distance;

void setup() {
  
   delay(500);
     
  Serial.begin(9600);
  
  pinMode(leftRev, OUTPUT);      // set Motor pins as output
  pinMode(leftFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trigPin as output
  pinMode(echoPin, INPUT);          // set echoPin as input 
  pinMode(pirInput, INPUT_PULLUP);         // set PIR as input
}


void loop() {

  delay(30000);
  
int proximity = digitalRead(pirInput);  // read input value

 if (proximity == HIGH) {
  
    digitalWrite(13, HIGH);
    
    digitalWrite(rightFwd, LOW);  //Stop                
    digitalWrite(rightRev, LOW);
    digitalWrite(leftFwd, LOW);                                
    digitalWrite(leftRev, LOW);
    Serial.println("stop");
    
 } if (proximity == LOW) {

    digitalWrite(13, LOW);
  
    digitalWrite(rightFwd, HIGH);  //fwd                
    digitalWrite(rightRev, LOW);
    digitalWrite(leftFwd, HIGH);                                
    digitalWrite(leftRev, LOW);
    Serial.println("fwd");
  
 }

  
  digitalWrite(blueLed, HIGH);
  delay(250);
  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(250);
  digitalWrite(redLed, LOW);

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
  if (distance > 19)            
  {
    digitalWrite(rightFwd, HIGH); // move forward
    digitalWrite(rightRev, LOW);
    digitalWrite(leftFwd, HIGH);                                
    digitalWrite(leftRev, LOW);   
    Serial.println("fwd");                                                    
  }

  if (distance < 18)
  {
    digitalWrite(rightFwd, LOW);  //Stop                
    digitalWrite(rightRev, LOW);
    digitalWrite(leftFwd, LOW);                                
    digitalWrite(leftRev, LOW);
    Serial.println("stop");
    delay(500);
    
    digitalWrite(rightFwd, LOW); //move Backward         
    digitalWrite(rightRev, HIGH);
    digitalWrite(leftFwd, LOW);                                
    digitalWrite(leftRev, HIGH);
    Serial.println("back");
    delay(500);
    
    digitalWrite(rightFwd, LOW); //Stop                
    digitalWrite(rightRev, LOW);
    digitalWrite(leftFwd, LOW);                                
    digitalWrite(leftRev, LOW);
    Serial.println("stop");
    delay(100); 
     
    digitalWrite(rightFwd, HIGH);       
    digitalWrite(rightRev, LOW);   
    digitalWrite(leftFwd, LOW);                                 
    digitalWrite(leftRev, LOW);
    Serial.println("right");  
    delay(500);
  } 
 
    }
  
