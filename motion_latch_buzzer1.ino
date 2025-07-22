// --- Pin Definitions ---
const int buttonPin = 9;
const int ledPin = 13;
const int externalLedPin = 12;
const int digitalSensorPin = 7;
const int buzzerPin = 6;

// --- State Variables ---
bool systemState = false;
bool lastButtonState = HIGH;
bool currentButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

unsigned long systemOnTime = 0;
unsigned long autoOffDelay = 3000; // الإيقاف بعد 3 ثواني

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(externalLedPin, OUTPUT);
  pinMode(digitalSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(externalLedPin, LOW);
  noTone(buzzerPin);

  Serial.begin(9600);
  Serial.println("System Ready");
}

void playIntroMelody() {
  int tones[] = {600, 700, 1000};
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, tones[i], 500);
    digitalWrite(ledPin, HIGH);
    digitalWrite(externalLedPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(externalLedPin, LOW);
    delay(100);
  }

  tone(buzzerPin, 1500);
  digitalWrite(ledPin, HIGH);
  digitalWrite(externalLedPin, HIGH);
  delay(3000);
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
  digitalWrite(externalLedPin, LOW);
}

void loop() {
  // --- Manual Button Toggle ---
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      if (currentButtonState == LOW) {
        systemState = !systemState;
        if (systemState) {
          systemOnTime = millis();         // ✅ ضبط التوقيت قبل التشغيل
          digitalWrite(ledPin, HIGH);
          playIntroMelody();
          Serial.println("Manual Toggle: System ON with melody");
        } else {
          digitalWrite(ledPin, LOW);
          digitalWrite(externalLedPin, LOW);
          noTone(buzzerPin);
          Serial.println("Manual Toggle: System OFF");
        }
      }
    }
  }
  lastButtonState = reading;

  // --- Motion Trigger ---
  int digitalValue = digitalRead(digitalSensorPin);
  if (digitalValue == HIGH && !systemState) {
    systemState = true;
    systemOnTime = millis();              // ✅ ضبط التوقيت قبل التشغيل
    digitalWrite(ledPin, HIGH);
    playIntroMelody();
    Serial.println("Auto ON: Motion Detected with melody");
  }

  // --- Auto OFF after timeout ---
  if (systemState && (millis() - systemOnTime > autoOffDelay)) {
    systemState = false;
    digitalWrite(ledPin, LOW);
    digitalWrite(externalLedPin, LOW);
    noTone(buzzerPin);
    Serial.println("Auto OFF Triggered");
  }
}