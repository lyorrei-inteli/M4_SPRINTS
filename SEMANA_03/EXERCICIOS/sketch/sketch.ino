int BLUE_LED = 21;
int YELLOW_LED = 19;
int GREEN_LED = 18;
int PINK_LED = 5;

int LDR_PIN = 27;
int BUZZER_PIN = 25;
int BUTTON1_PIN = 32;
int BUTTON2_PIN = 33;

int ledVectors[4];
int ledVectorsHistory[100][4];
int ledVectorsHistoryCount = 0;

void convertToBinary(int decimalValue) {

  for (int i = 0; i < 4; i++) {
    ledVectors[i] = decimalValue % 2;
    ledVectorsHistory[ledVectorsHistoryCount][i] = decimalValue % 2;
    decimalValue = decimalValue / 2;
  }
  ledVectorsHistoryCount += 1;
}

void lightLed(int light, int led_pin) {
  if (light == 1) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
}

void toneBuzzer(int *vectors) {
  int toneVal = 0;
  for (int i = 0; i < 4; i++) {
    toneVal += vectors[i] * i * 800;
  }

  Serial.println(toneVal);
  tone(BUZZER_PIN, toneVal, 500);
}

void checkLedValue () {
  int ledVal = 0;
  for (int i = 0; i < 4; i++) {
    ledVal += ledVectors[i];
  }

  if (ledVal == 0) {
    Serial.println("Valor de Led = 0. Por favor, acenda uma luz!");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PINK_LED, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

int lastState = HIGH;
void loop() {


  if (digitalRead((BUTTON1_PIN)) == LOW) {


    // Transformação do número do led para um número em uma escala de 1 a 15
    float divisionNumber = 4063;
    float dividedNumber = analogRead(LDR_PIN) / divisionNumber;
    float multipliedNumber = dividedNumber * 15;
    convertToBinary(multipliedNumber);

    checkLedValue();

    lightLed(ledVectors[0], BLUE_LED);
    lightLed(ledVectors[1], YELLOW_LED);
    lightLed(ledVectors[2],  GREEN_LED);
    lightLed(ledVectors[3], PINK_LED);

    toneBuzzer(ledVectors);
    delay (500);

    lightLed(0, BLUE_LED);
    lightLed(0, YELLOW_LED);
    lightLed(0,  GREEN_LED);
    lightLed(0, PINK_LED);
    while (digitalRead((BUTTON1_PIN)) == LOW)
    {}
  }

  if (digitalRead((BUTTON2_PIN)) == LOW) {


    for (int i = 0; i < ledVectorsHistoryCount; i++) {
      lightLed(ledVectorsHistory[i][0], BLUE_LED);
      lightLed(ledVectorsHistory[i][1], YELLOW_LED);
      lightLed(ledVectorsHistory[i][2],  GREEN_LED);
      lightLed(ledVectorsHistory[i][3], PINK_LED);

      toneBuzzer(ledVectorsHistory[i]);
      delay (500);

      lightLed(0, BLUE_LED);
      lightLed(0, YELLOW_LED);
      lightLed(0,  GREEN_LED);
      lightLed(0, PINK_LED);

      delay (1000);


    }
    ledVectorsHistoryCount = 0;
    while (digitalRead((BUTTON2_PIN)) == LOW)
    {}

  }

  delay(10);

}
