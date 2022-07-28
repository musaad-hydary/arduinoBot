const int forwardLeft = 2;
const int backwardLeft = 3;
const int forwardRight = 4;
const int backwardRight = 5;
const int echo = 11;
const int trigger = 12;

int distance = 0;
int duration = 0;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(backwardLeft, OUTPUT);
  pinMode(backwardRight, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("Program begin!");


}

void loop() {
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  

  if ( distance < 20 )
  {
    digitalWrite(forwardLeft , LOW);
    digitalWrite(backwardLeft , HIGH);
    digitalWrite(forwardRight , HIGH);
    digitalWrite(backwardRight , LOW);
    delay(100);
  }
  else
  {
    digitalWrite(forwardLeft , HIGH);
    digitalWrite(backwardLeft , LOW);
    digitalWrite(forwardRight , HIGH);
    digitalWrite(backwardRight , LOW);
  }
  
}
