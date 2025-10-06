#include <Keypad.h>


// This is the size of the keyboard
const byte ROWS = 4;
const byte COLS = 4;
const int buzzer = 3;
const int LED1 = 2;
const int LED2 = 4;
const int code1 = 4;
const int code2 = 4;
const int code3 = 5;
const int code4 = 6;
bool setCode = false;
const byte CAP = 4;
int buf[CAP];
byte len = 0;

void clearBuf() {
  len = 0;
}

bool pushBack(int v) {
    if (len >= CAP) { return false; }
    buf[len] = v;
    len = len + 1;
    return true;
}

// This is what each button will return
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// The wiring of the rows/cols. pins on the keyboard
byte rowPins[ROWS] = { 13,12,11,10 };
byte colPins[COLS] = { 9,8,7,6 };

// Creates an object pad of type Keypad, from Keypad.h
Keypad pad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    pinMode(LED1, OUTPUT);
  	pinMode(LED2, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    Serial.println("4x4 Keypad test: press keys...");
}

void loop()
{
    char key = pad.getKey();
    if (key >= '0' && key <= '9') {
        tone(buzzer, 1000);
        digitalWrite(LED1, HIGH);
        delay(50);
        noTone(buzzer);
        digitalWrite(LED1, LOW);
        Serial.print("Key: ");
        Serial.println(key);
      	Serial.println(len);

      
        if (setCode == true) {
            if (pushBack(key - '0') == false) {
                Serial.println("FALSE");
                setCode = false;
            }
        }
    }

        if (key == '*') {
            tone(buzzer, 2000);
            digitalWrite(LED1, HIGH);
            delay(500);
            noTone(buzzer);
            digitalWrite(LED1, LOW);

            setCode = true;
          	clearBuf();
            Serial.println("Input code");
        }


        if (key == '#') {
            tone(buzzer,1000);
            delay(50);
            noTone(buzzer);

			Serial.println("Checking code...");
          
          
          if (buf[0] == code1 && buf[1] == code2 && buf[2] == code3 && buf[3] == code4) {
          	Serial.println("TRUE CODE");
            		delay(500);
                    tone(buzzer, 3000);
            		digitalWrite(LED2, HIGH);
            		delay(500);
                    noTone(buzzer);
            		digitalWrite(LED2, LOW);
                    clearBuf();
          }
          else {
                	Serial.println("FALSE CODE");
            		delay(500);
                    tone(buzzer, 2000);
            		digitalWrite(LED1, HIGH);
            		delay(500);
                    noTone(buzzer);
            		digitalWrite(LED1, LOW);
            		clearBuf();


                }
          




        }

}