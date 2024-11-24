//This works... I think

// Pin definitions
#define ENCODER_PIN_A 2  // Must be an interrupt pin
#define ENCODER_PIN_B 3  // Can be any digital pin

volatile int encoderPosition = 0;
int lastEncoded = 0;

void setup() {
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), updateEncoder, CHANGE);

  Serial.begin(9600);
}

void loop() {
  // Print encoder position
  Serial.println(encoderPosition);
  delay(100);
}

void updateEncoder() {
  int MSB = digitalRead(ENCODER_PIN_A); // Most significant bit
  int LSB = digitalRead(ENCODER_PIN_B); // Least significant bit

  int encoded = (MSB << 1) | LSB; // Combine into single binary value
  int sum = (lastEncoded << 2) | encoded;

  if (sum == 0b0001 || sum == 0b0111 || sum == 0b1110 || sum == 0b1000)
    encoderPosition++;
  if (sum == 0b0010 || sum == 0b0100 || sum == 0b1101 || sum == 0b1011)
    encoderPosition--;

  lastEncoded = encoded; // Store current state
}
