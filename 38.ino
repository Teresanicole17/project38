// Project 38 - Control Motor Speed with Serial Monitor

const int motorPin = 5;  // PWM pin connected to transistor/base resistor or motor driver input

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

  Serial.println("Motor speed control ready");
  Serial.println("Enter a value from 0 to 255:");
  Serial.println("0 = OFF, 255 = Full Speed");
}

void loop()
{
  if (Serial.available() > 0)
  {
    int speedValue = Serial.parseInt();          // Read number from Serial Monitor
    speedValue = constrain(speedValue, 0, 255);  // Keep value in range

    analogWrite(motorPin, speedValue);          // Set motor speed

    Serial.print("Motor speed set to: ");
    Serial.println(speedValue);

    while (Serial.available() > 0)
    {
      Serial.read(); 
    }
  }
}