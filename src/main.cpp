#include <Arduino.h>

#define DIRECTION 8
#define STEP 18


int readButton(void);

namespace botao{
    int button_1 = 4;
    int button_2 = 5;
    int button_3 = 6;
    int button_4 = 7;
}

void setup() {
  // put your setup code here, to run once:
  /*pinMode(botao::button_1, INPUT_PULLUP);
  pinMode(botao::button_2, INPUT_PULLUP);
  pinMode(botao::button_3, INPUT_PULLUP);
  pinMode(botao::button_4, INPUT_PULLUP);*/

  pinMode(DIRECTION, OUTPUT);
  //pinMode(STEP, OUTPUT);
  ledcSetup(0, 1100, 8);     // canal 0, 1000 Hz, resolução 8 bits
  ledcAttachPin(STEP, 0);   // canal 0 ligado ao pino STEP}
  ledcWrite(0, 128);         // 50% duty cycle
  digitalWrite(DIRECTION, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int readButton(void){
    int button_high = 0;
    int tempo = 0;
    if(!digitalRead(botao::button_1) && !button_high){
        tempo = millis();
        button_high = 1;
    }
    if(!digitalRead(botao::button_2) && !button_high){
        tempo = millis();
        button_high = 2;
    }
    if(!digitalRead(botao::button_3) && !button_high){
        tempo = millis();
        button_high = 3;
    }
    if(!digitalRead(botao::button_4) && !button_high){
        tempo = millis();
        button_high = 4;
    }
    while(button_high && (millis() - tempo) < 50){
        if(digitalRead(botao::button_1) && digitalRead(botao::button_2) && digitalRead(botao::button_3) && digitalRead(botao::button_4)){
            return 0;
        }
    }
    return button_high;
}