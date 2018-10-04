
int LED1 = 9;
int LED2 = 10;
int BUTTON = 11;
int RELAYS = 12;
int state = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(LED1, 1);
  digitalWrite(LED2, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(BUTTON) == HIGH)
       {
       if(state == 0){
          state = 1;
          digitalWrite(LED1, 0);
          digitalWrite(LED2, 1);
          digitalWrite(RELAYS, 1);
          Serial.println("Change state to 1");     
          }
       else
          { 
          state = 0;
          digitalWrite(LED1, 1);
          digitalWrite(LED2, 0);
          digitalWrite(RELAYS, 0);
          Serial.println("Change state to 0");
          }
       }
    delay(1000); 
}
