
int IN1 = D1;
int IN2 = D2;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  setDirection();
  delay(1000);

}

void setDirection() {


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
}

