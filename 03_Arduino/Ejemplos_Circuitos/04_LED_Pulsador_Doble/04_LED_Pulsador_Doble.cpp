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

int led = 6;
int estadoPulsDerAntes = LOW;
int estadoPulsIzqAntes = LOW;

void setup(){ 
	for(int i=3; i<7; i++){ 
		pinMode(i, OUTPUT);
	} 
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	digitalWrite(6, HIGH);
}

void loop(){
    int estadoPulsDerAhora = digitalRead(8);
    int estadoPulsIzqAhora = digitalRead(9);
    
    if(estadoPulsDerAhora == HIGH && estadoPulsDerAntes == LOW){
        if(led > 3){ 
            digitalWrite(led, LOW);
            led--;
            digitalWrite(led, HIGH);
        }
    }

    estadoPulsDerAntes = estadoPulsDerAhora;

    if (estadoPulsIzqAhora == HIGH && estadoPulsIzqAntes == LOW){
        if (led<6){
            digitalWrite(led,LOW);
            led++;
            digitalWrite(led,HIGH);
        }
    }

    estadoPulsIzqAntes = estadoPulsIzqAhora;
    delay(50);
}