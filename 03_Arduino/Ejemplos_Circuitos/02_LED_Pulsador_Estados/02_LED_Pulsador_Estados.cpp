/*
 * MIT License
 * 
 * Copyright (c) 2021 [SPD]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
*/

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

