#include <PKAE_Timer.h>

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

// Callback functions
void led1_blinker();
void led2_blinker();
void led3_blinker();
void show_count();

// Define the Repeat Timers
RepeatTimer LED1_Flash(100, led1_blinker), LED2_Flash(300, led2_blinker);
RepeatTimer LED3_Flash(500, led3_blinker);
RepeatTimer LED4_Flash(1000, [](){
  static bool LED4_State = LOW;
  LED4_State = !LED4_State;
  digitalWrite(LED4, LED4_State);
});
RepeatTimer ShowCount(3000, show_count);

void led1_blinker() {
  // Private but Global
  static bool LED1_State = LOW;
  LED1_State = !LED1_State;
  digitalWrite(LED1, LED1_State);
}

void led2_blinker() {
  static bool LED2_State = LOW;
  LED2_State = !LED2_State;
  digitalWrite(LED2, LED2_State);
}

void led3_blinker() {
  static bool LED3_State = LOW;
  LED3_State = !LED3_State;
  digitalWrite(LED3, LED3_State);
}

void show_count() {
  Serial.print("Count 1 = ");
  Serial.print(LED1_Flash.nCount);
  Serial.print("  Count 2 = ");
  Serial.print(LED2_Flash.nCount);
  Serial.print("  Count 3 = ");
  Serial.print(LED3_Flash.nCount);
  Serial.print("  Count 4 = ");
  Serial.println(LED4_Flash.nCount);
}

//=============================================================================
// SETUP                                                                      |
//=============================================================================
void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(115200);
}

//=============================================================================
// LOOP                                                                       |
//=============================================================================
void loop() {
  LED1_Flash.update();
  LED2_Flash.update();
  LED3_Flash.update();
  LED4_Flash.update();
  ShowCount.update();
}
