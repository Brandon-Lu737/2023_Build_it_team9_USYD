// Initialize the line sensor module and motor driver module
int sensor1Pin = 2; // Pin connected to line sensor 1
int sensor2Pin = 3; // Pin connected to line sensor 2
int motor1Pin1 = 9; // Pin connected to motor driver 1 (direction 1)
int motor1Pin2 = 10; // Pin connected to motor driver 1 (direction 2)
int motor2Pin1 = 5; // Pin connected to motor driver 2 (direction 1)
int motor2Pin2 = 6; // Pin connected to motor driver 2 (direction 2)

// TODO: We have a trade-off between an optimal speed and we don't want to veer off course
// Set the motor speeds to a default value
int motorSpeed1 = 150; // Speed of motor 1
int motorSpeed2 = 150; // Speed of motor 2

void setup() {
  // Initialize the line sensor module
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);

  // Initialize the motover module
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  // Read the output of the line sensor module
  int sensor1Value = digitr drialRead(sensor1Pin);
  int sensor2Value = digitalRead(sensor2Pin);

  // Determine the position of the line relative to the bot
  if (sensor1Value == LOW && sensor2Value == LOW) {
    // Both sensors are on the line, move forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else if (sensor1Value == LOW && sensor2Value == HIGH) {
    # TODO: We have to determine how fast /swift we wanna turn
    // Sensor 1 is on the line, turn left
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else if (sensor1Value == HIGH && sensor2Value == LOW) {
    // Sensor 2 is on the line, turn right
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  } else {
    // Neither sensor is on the line, stop moving
    // TODO: stop moving entirely
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
  }

  // Adjust the motor speeds and directions accordingly
  analogWrite(motor1Speed, motorSpeed1);
  analogWrite(motor2Speed, motorSpeed2);
  
  // Repeat the loop
  delay(10); // add a short delay to allow the bot to respond to the sensor readings
}
