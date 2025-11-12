#include <Servo.h>

// TB6612 connections (same as your setup)
#define AIN1 22
#define AIN2 24
#define PWMA 5
#define BIN1 26
#define BIN2 28
#define PWMB 6
#define STBY 30

#define L_S 8   // Left IR
#define R_S 9   // Right IR
#define trigger 10
#define echo 11
#define servoPin 7

Servo servoMotor;

// ---- Adjustable Parameters ----
int baseSpeed = 190;       // normal forward speed
int turnSpeed = 130;       // turning speed for lane correction
int rotateSpeed = 150;     // speed during obstacle avoidance turns
int avoidDistance = 15;    // distance (cm) to detect obstacle

int distance_L, distance_F, distance_R;

// -----------------------------
void setup() {
  Serial.begin(9600);

  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  servoMotor.attach(servoPin);

  // Center scan initialization
  servoMotor.write(90);
  Serial.println("System Initialized...");
  delay(1000);
}

// -----------------------------
void loop() {
  distance_F = Ultrasonic_read();
  Serial.print("Front Distance: ");
  Serial.println(distance_F);

  // Line Following + Obstacle Avoidance
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
    if (distance_F > avoidDistance) {
      forward(baseSpeed);
      Serial.println("Moving Forward");
    } else {
      Check_side();
    }
  } else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
    turnRight(turnSpeed);
    Serial.println("Turning Right");
  } else if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
    turnLeft(turnSpeed);
    Serial.println("Turning Left");
  } else {
    Stop();
    Serial.println("Stopped");
  }

  delay(10);
}

// ---------- SENSOR FUNCTIONS ----------
long Ultrasonic_read() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  long time = pulseIn(echo, HIGH, 30000);
  return time / 29 / 2;
}

void Check_side() {
  Stop();
  delay(200);

  // Scan Right
  servoMotor.write(140);
  delay(300);
  distance_R = Ultrasonic_read();
  Serial.print("Right: "); Serial.println(distance_R);

  // Scan Left
  servoMotor.write(40);
  delay(500);
  distance_L = Ultrasonic_read();
  Serial.print("Left: "); Serial.println(distance_L);

  // Center back
  servoMotor.write(90);
  delay(300);

  compareDistance();
}

void compareDistance() {
  if (distance_L > distance_R) {
    Serial.println("Avoiding Left");
    turnLeft(rotateSpeed);
    delay(500);
    forward(baseSpeed);
    delay(600);
    turnRight(rotateSpeed);
    delay(500);
    forward(baseSpeed);
    delay(600);
    turnRight(rotateSpeed);
    delay(400);
  } else {
    Serial.println("Avoiding Right");
    turnRight(rotateSpeed);
    delay(500);
    forward(baseSpeed);
    delay(600);
    turnLeft(rotateSpeed);
    delay(500);
    forward(baseSpeed);
    delay(600);
    turnLeft(rotateSpeed);
    delay(400);
  }
}

// ---------- MOVEMENT FUNCTIONS ----------

void forward(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);   // Left forward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);    // Right forward
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void backword(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void turnRight(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);   // Left forward
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);   // Right backward
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void turnLeft(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);    // Left backward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);    // Right forward
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void Stop() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}
