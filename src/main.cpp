#include <Arduino.h>

//FAZER FITA LED

#define M1_DIRECTION 19
#define M1_STEP 20
#define M1_SLEEP 21
#define M1_RESET 47
#define M1_ENABLE 48

#define M2_DIRECTION 40
#define M2_STEP 41
#define M2_SLEEP 42
#define M2_RESET 38
#define M2_ENABLE 39

//Player 1
#define BUTTON_1 4
#define BUTTON_2 5

//Player 2
#define BUTTON_3 6
#define BUTTON_4 7

#define FITA_LED 1000

//Variables timer
unsigned long timer_b1;
unsigned long timer_b2;
unsigned long timer_b3;
unsigned long timer_b4;

//Variables pressed
bool b1_last = false;
bool b2_last = false;
bool b3_last = false;
bool b4_last = false;

bool b1_pressed = false;
bool b2_pressed = false;
bool b3_pressed = false;
bool b4_pressed = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(M1_DIRECTION, OUTPUT);
    ledcSetup(1, 500, 8);
    ledcAttachPin(M1_STEP, 1);
  pinMode(M1_SLEEP, OUTPUT);
  pinMode(M1_RESET, OUTPUT);
  pinMode(M1_ENABLE, OUTPUT);

  pinMode(M2_DIRECTION, OUTPUT);
  ledcSetup(0, 500, 8);
  ledcAttachPin(M2_STEP, 0);
  pinMode(M2_SLEEP, OUTPUT);
  pinMode(M2_RESET, OUTPUT);
  pinMode(M2_ENABLE, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);

  //ATIVAR OS DRIVERS
  //DRIVER 1
  digitalWrite(M1_SLEEP, HIGH);
  digitalWrite(M1_RESET, HIGH);
  digitalWrite(M1_ENABLE, LOW);
  //DRIVER 2
  digitalWrite(M2_SLEEP, HIGH);
  digitalWrite(M2_RESET, HIGH);
  digitalWrite(M2_ENABLE, LOW);
}

void loop() {
    // Buttons state:
    if((digitalRead(BUTTON_1) == LOW) && b1_last == false){
        timer_b1 = millis();
        b1_last = true;
    }
    if((digitalRead(BUTTON_2) == LOW) && b2_last == false){
        timer_b2 = millis();
        b2_last = true;
    }
    if((digitalRead(BUTTON_3) == LOW) && b3_last == false){
        timer_b3 = millis();
        b3_last = true;
    }
    if((digitalRead(BUTTON_4) == LOW) && b4_last == false){
        timer_b4 = millis();
        b4_last = true;
    }

    if(digitalRead(BUTTON_1) == HIGH){
        b1_last = false;
    }
    if(digitalRead(BUTTON_2) == HIGH){
        b2_last = false;
    }
    if(digitalRead(BUTTON_3) == HIGH){
        b3_last = false;
    }
    if(digitalRead(BUTTON_4) == HIGH){
        b4_last = false;
    }

    if(digitalRead(BUTTON_1) == LOW && (millis() - timer_b1 > 50)){
        b1_pressed = true;
    }
    else{
        b1_pressed = false;
    }
    if(digitalRead(BUTTON_2) == LOW && (millis() - timer_b2 > 50)){
        b2_pressed = true;
    }
    else{
        b2_pressed = false;
    }
    if(digitalRead(BUTTON_3) == LOW && (millis() - timer_b3 > 50)){
        b3_pressed = true;
    }
    else{
        b3_pressed = false;
    }
    if(digitalRead(BUTTON_4) == LOW && (millis() - timer_b4 > 50)){
        b4_pressed = true;
    }
    else{
        b4_pressed = false;
    }
    
    if(b1_pressed != b2_pressed){
        digitalWrite(M1_DIRECTION, b1_pressed);
        ledcWrite(1, 128);
    }
    else{
        ledcWrite(1, 0);
    }

    if(b3_pressed != b4_pressed){
        digitalWrite(M2_DIRECTION, b3_pressed);
        ledcWrite(0, 128);
    }
    else{
        ledcWrite(0, 0);
    }

}