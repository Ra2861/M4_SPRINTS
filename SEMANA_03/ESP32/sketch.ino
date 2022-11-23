#include <stdarg.h>
#define sensor 7
#define buzzer 4
#define led1 1
#define led2 2
#define led3 42
#define led4 41
#define ANALOG_THRESHOLD 30
int botao1 = 9;
int botao2 = 46;
int valores[50] = {};
int salvos = 0;
int nota[] = {261,293,329,349,392,440,493,523,587,659,698,783,880,987,1046,1174,1318};
int tempo[] = { 150, 200, 100, 150, 220, 190 };

/*int intervalo(int leitura) {
  int valorConvertido = leitura/15;
  return valorConvertido;
}*/

//função para gravar
void led(int analog) {
  if (analog <= 500) {
    digitalWrite(led1, HIGH);
    tone(buzzer, nota[0], tempo[0]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 750) {
    digitalWrite(led2, HIGH);
    tone(buzzer, nota[1], tempo[1]);
    delay(200);
    noTone(buzzer);

  }

  else if (analog <= 1000) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    tone(buzzer, nota[2], tempo[2]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog<= 1250) {
    digitalWrite(led3, HIGH);
    tone(buzzer, nota[3], tempo[3]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 1500) {
    digitalWrite(led1, HIGH);
    digitalWrite(led3, HIGH);
    tone(buzzer, nota[4], tempo[4]);
    delay(200);
    noTone(buzzer);
  } else if (analog <= 1750) {
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    tone(buzzer, nota[5], tempo[5]);
    delay(200);
    noTone(buzzer);
  } else if (analog <= 2000) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    tone(buzzer, nota[6], tempo[0]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 2250) {
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[7], tempo[1]);
    delay(200);
    noTone(buzzer);
  } else if (analog <= 2500) {
    digitalWrite(led1, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[8], tempo[2]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 2750) {
    digitalWrite(led2, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[9], tempo[3]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 3000) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[10], tempo[4]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 3250) {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[11], tempo[5]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 3500) {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[12], tempo[0]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 3750) {
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[13], tempo[1]);
    delay(200);
    noTone(buzzer);
  }

  else if (analog <= 4000) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzzer, nota[14], tempo[2]);
    delay(200);
    noTone(buzzer);
  }

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void play(int analog) {
  if (salvos < 50) {
    valores[salvos] = analog;
    led(analog);
    salvos++;
  }
}

void lembra() {
  for (int i = 0; i < salvos; i++) {
    led(valores[i]);
  }
  salvos = 0;
  valores[50] = {};
}


void setup() {

  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {

  int b1 = digitalRead(botao1);
  int b2 = digitalRead(botao2);
  int light_sensor = analogRead(sensor);
  //Serial.println(light_sensor);
  Serial.println(analogRead(sensor));

  if (b1 == LOW) {
    play(light_sensor);
  }

  if (b2 == LOW) {
    lembra();
  }
}