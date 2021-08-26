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

#define LED 8
#define BOTON 3

int estadoBoton;
int estadoAnteriorBtn = 0;
int estadoLed = 0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BOTON, INPUT);
  Serial.begin(9600);
}

void loop() {  
    //PULL DOWN
    estadoBoton = digitalRead(BOTON);
    //AntiBousing 0 Rebote  : estadoBoton != estadoAnteriorBtn
    if(estadoBoton != estadoAnteriorBtn){
        if(estadoBoton == HIGH){
            estadoLed = !estadoLed;
            digitalWrite(LED,estadoLed);
        }
    estadoAnteriorBtn = estadoBoton;
    }
  
    delay(50);
}