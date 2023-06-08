#include <LiquidCrystal.h>
//importa a biblioteca do lcd
#include <Servo.h>
//Importa a biblioteca do servo motor

LiquidCrystal lcd(2,3,4,5,6,7,8);//define as portas do lcd
char senha ='4';//define a senha
int posicao = 0;//define a posicao inicial do servo motor
Servo servo;//cria um objeto do servo motor
int i = 0;//variável que será ultilizada no while de verificação de temperatura
int buzzer = 10;//define a porta do buzzer
int sensorTemp = A0;//define a porta do sensor
int led_red = 11;//define  aporta do led vermelho
int led_green = 12;//define a porta do led verde
int botao = 13;//define a porta do botão
int estado = 0;//define o estado do botão



void setup(){
 //lcd
 lcd.begin(16, 2);//define o tamanho dos prints do lcd
 pinMode(8, OUTPUT);//define a porta do lcd como saida de dados
  
  
 //Servo - Motor definção de portas 
  servo.attach(9);
  servo.write(0);
  
 //buzzer - definição como saída de dados
  pinMode(buzzer, OUTPUT);
  
  
 //sensorTemperatura - definição entrada de dados
  pinMode (sensorTemp, INPUT);
  
  
 //LEDs - definição como saída de dados
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  
 
  //BOTÃO - definição entrada de dados
  pinMode(botao, INPUT);  
  digitalWrite (botao, HIGH);
  
  Serial.begin(9600);
  //chama função de verificação da senha
  acesso();
}

void loop(){
  //chama função de verificação de temperatura
    sensor_temperatura();
   //lê o estado do botão
  	estado = digitalRead(botao);
  
  	if (estado == LOW) {
      //chama função que desliga todos os componentes
      reseta();
      //chama função de verificação da senha
      acesso();
  	}
  	
}


void acesso() {
  bool a = false;
  while (a==false) {
   if (Serial.available()) { // Verificar se há caracteres disponíveis
      char caractere = Serial.read(); // Armazena caractere lido
      if ( caractere == senha ) {  // Verificar se o que foi digitado é igual a senha
            lcd.clear();
            lcd.setCursor(0, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
            lcd.print("ACESSO PERMITIDO");//Escreve o texto desejado
            servo.write(90);//move o servo motor em 90 graus
            a = true;//acaba com o loop
            digitalWrite(buzzer,LOW);
        	digitalWrite(led_red,LOW);
           	i = 0;

      }else if (i>=3){
        digitalWrite(buzzer,HIGH);//liga o buzzer
        digitalWrite(led_red,HIGH);//liga o led
       

      }else if ( caractere != senha ){//valor digitado diferente da senha
          lcd.clear();
          lcd.print("ACESSO NEGADO");//Escreve o texto no lcd
          i++;
          Serial.println(i);


   } 
 }
  }
}

void sensor_temperatura() {
  int soma_temperatura = 0;//imicia as variáveis que serão ultilizadas no loop como 0
  int i = 0;
  int media_temperatura = 0;
  while (i < 5){//faz a média de 2.5 segundos da temperatura
  float tmp = analogRead(sensorTemp);
  int temperatura = map(((tmp - 20) * 3.04), 0, 1023, -40, 125);//converte a temperatura para Celsius
  delay(500);//delay de meio segundo
  soma_temperatura += temperatura;//gurada os valores da tempratura em um váriavel
  Serial.println(temperatura);//printa os valores guardados
  i+=1;//soma para acabar o loop
  } 
  media_temperatura = soma_temperatura/5;//faz a média da temperatura
  
  if (media_temperatura<-12){
    lcd.clear();//limpa o lcd
    digitalWrite(buzzer,LOW);//desliga o buzzer
    digitalWrite(led_red,LOW);//desliga o led
    lcd.setCursor(0, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("Temp. Ideal");//Escreve o texto desejado
    lcd.setCursor(0, 1);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("Temp : "+String(media_temperatura)+"°C");//printa no lcd a mensagem e a váriavle da média da temperatura
    digitalWrite(led_green,HIGH);//liga o led
    
  }
  else {
    lcd.clear();//limpa o lcd
    digitalWrite(led_green,LOW);//desliga o led
    lcd.setCursor(0, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("Temp. Alta");//Escreve o texto desejado
    lcd.setCursor(0, 1);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("Temp : "+String(media_temperatura)+"°C");
    digitalWrite(buzzer,HIGH);//liga o buzzer
    digitalWrite(led_red,HIGH);//liga o led
  
  }
}
void reseta(){//desliga todos os componetes
  digitalWrite(led_green,LOW);//desliga o led
  digitalWrite(buzzer,LOW);//desliga o buzzer
  digitalWrite(led_red,LOW);//desliga o led
  lcd.clear();//limpa o lcd
  servo.write(180);//move o motor em 180 graus

}