#define STATE_ON 0
#define STATE_OFF 1

int state = STATE_OFF;
int previousState = 0;

void on(void);
void off(void);

void setup() {
  pinMode(12, OUTPUT);
  pinMode(3 , INPUT);
}

void loop() {
  int currentState = digitalRead(3);
  if(currentState == 1 && previousState == 0) {
    if(state == STATE_ON) {
      state = STATE_OFF;
    } else {
      state = STATE_ON;
    }
  }
  previousState = currentState;

  switch(state) {
    case STATE_ON:
    on();
    break;

    case STATE_OFF:
    off();
    break;
  }
}

void on() {
  digitalWrite(12, HIGH);
}

void off() {
  digitalWrite(12, LOW);
}

