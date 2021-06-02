#define L_LightSensor A1
#define R_LightSensor A0

#define L_motor 6

#define R_motor 9

void setup() 
{  
  pinMode(R_motor, OUTPUT);
  pinMode(L_motor, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  drive();
  //delay(1);

}

void drive()
{
  unsigned long LeftVal = analogRead(L_LightSensor);
  unsigned long RightVal = analogRead(R_LightSensor);
  unsigned long differenceR = RightVal - LeftVal;
  unsigned long differenceL = LeftVal - RightVal;
  Serial.println(differenceR);
  Serial.println(differenceL);
  
  if(RightVal < 500 && LeftVal < 500)
  {
    digitalWrite(R_motor, LOW);
    digitalWrite(L_motor, LOW);
  }
  else if(differenceR <= 50 || differenceL <= 50)
  {
    GoForward();
    Serial.println("FORWARD!");
  }
  else if(LeftVal > RightVal)
  {
    GoLeft();
  }
  else if(RightVal > LeftVal)
  {
    GoRight();
  }

}

void GoLeft()
{
  digitalWrite(R_motor, HIGH);
  digitalWrite(L_motor, LOW);
}

void GoForward()
{
  digitalWrite(L_motor, HIGH);
  digitalWrite(R_motor, HIGH);
}

void GoRight()
{
  digitalWrite(L_motor, HIGH);
  digitalWrite(R_motor, LOW);  
}
