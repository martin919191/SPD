#define STATE_OFF 0
#define STATE_ON 1
#define STATE_BLINK 2

int state = STATE_OFF;
int previousState = 0;
int ledState = 0;
long blinkStartTime = -1001;

void on(void);
void off(void);
void blink(void);

void setup() {
  pinMode(12, OUTPUT);
  pinMode(3 , INPUT_PULLUP);
}

void loop() {
  int currentState = 1 - digitalRead(3);
  if(currentState == 1 && previousState == 0) {
    state++;
    if(state == 3) state = STATE_OFF;
  }
  previousState = currentState;

  switch(state) {
    case STATE_ON:
    on();
    break;

    case STATE_OFF:
    off();
    break;

    case STATE_BLINK:
    blink();
    break;
  }

  delay(100);
}

void on() {
  digitalWrite(12, HIGH);
}

void off() {
  digitalWrite(12, LOW);
}

void blink() {
  long currentMillis = millis();
  if(currentMillis - blinkStartTime > 500) {
    ledState = 1 - ledState;
    digitalWrite(12, ledState);
    blinkStartTime = currentMillis;
  }
}

