// Load Wi-Fi library
#include <WiFi.h>

const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

WiFiServer server(80);

String header;

int contador1= 0;
int contador2 = 0;

const int output26 = 4; //verde
const int output27 = 16; //vermelho

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200); 
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   

  if (client) {                            
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");    
    String currentLine = "";            
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                   
        header += c;
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
         
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off

            if (header.indexOf("GET /26/H") >= 0) {
              digitalWrite(output26, HIGH);
              contador2++;
              
            }if (header.indexOf("GET /26/on") >= 0) {
              digitalWrite(output26, HIGH);
              contador1++;
              
            } else if (header.indexOf("GET /26/off") >= 0) {
              digitalWrite(output26, LOW);
           
            }else if (header.indexOf("GET /27/on") >= 0) {
              digitalWrite(output27, HIGH);
             
            } else if (header.indexOf("GET /27/off") >= 0) {
              digitalWrite(output27, LOW);
          
            }
            
            //  HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Quiz</h1>");
            client.println("Pontuação jogador 1: " );
            client.println(contador1);
            client.println("Pontuação jogador 1: " );
            client.println(contador2);
            client.print("<div class=\".container\" id =\"q1\">");
            client.print("<a class=\".enunciado\">(jogador1)1- Marque a opção que melhor define o conceito de Lógica na área da tecnologia?</a><br><br>");
            client.print("<a class=\".enunciado\" href=\"/26/on\">a) Organização e planejamento das instruções, em um algoritmo,<br> a fim de viabilizar a implantação de um programa/software</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/27/on\">b) O encadeamento coerente de alguma coisa que obedece a certas convenções e regras</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/27/on\">c) Significa encadear uma série de instruções para que se possa chegar à solução de um problemas</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/27/on\">d) Maneira rigorosa de raciocinar</a><br>");
            client.println("<p><a href=\"#q2\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");

            client.print("<div class=\".container\" id=\"q2\">");
            client.print("<a class=\".enunciado\">(jogador2) 2- que significa ‘concatenar’?</a><br><br>");
            client.print("<a class=\".enunciado\" href=\"/27/on\">a) Trata-se de um conjunto de caracteres</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/27/on\">b) Configurar o tipo de uma variável</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/27/on\">c) Dividir duas variáveis</a><br><br>");
            client.print("<a  class=\".enunciado\"  href=\"/26/H\">d) Unir dados de modo lógico ou manter ligação ou conexão entre eles</a><br><br><br>");
            client.println("<p><a href=\"#q3\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");
            //pergunta 3
            client.print("<div class=\".container\" id=\"q3\">");
            client.print("<a class=\".enunciado\">(jogador1)3- Onde as variáveis ficam armazenadas?</a><br><br>");
            client.print("<a class=\".enunciado\" href=\"/27/on\">a) No programa/software</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/26/on\">b) Na memória RAM do computador</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">c) No banco de dados</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">d) No banco de dados, no software e na memória RAM</a><br><br><br>");
            client.println("<p><a href=\"#q4\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");
            //pergunta 4
            
            client.print("<div class=\".container\" id=\"q4\"><a class=\".enunciado\">(jogador2)4- O que é 'Pseudocódigo'?</a><br><br>");
            client.print("<a class=\".enunciado\" href=\"/26/on\">a) Uma forma genérica de escrever um algoritmo, utilizando uma linguagem simples<br> (nativa a quem o escreve, de forma a ser entendida por qualquer pessoa)<br>sem necessidade de conhecer a sintaxe de uma linguagem de programação específica</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">b) Maneira rigorosa de raciocinar</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">c) Uma sequência de passos para atingir determinado objetivo</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">d) Uma linguagem de programação</a><br><br>");
            client.println("<p><a href=\"#q5\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");
            //pergunta 5
            client.print("<div class=\".container\" id=\"q5\"><a class=\".enunciado\">(jogador1)5- O que é um algoritmo?</a><br><br><br>");
            client.print("<a class=\".enunciado\" href=\"/27/on\">a) São ações ditas ao computador para ele executar</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">b) É a solução de um problema</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/26/on\">c) Uma sequência de passos para atingir determinado objetivo</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">d) Permite realizar operações lógicas e aritméticas utilizando apenas dois dígitos ou dois estados<br>(sim ou não, verdadeiro ou falso, tudo ou nada, ligado ou desligado, 1 ou 0)</a><br><br>");
            client.println("<p><a href=\"#q6\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");

            //pergunta 6
            client.print("<div class=\".container\"id=\"q6\"><a class=\".enunciado\">(jogador2)6- O que são arrays?</a><br><br>");
            client.print("<a class=\".enunciado\" href=\"/26/on\">a) São estruturas de dados homogêneas que possibilitam o armazenamento<br> de grupos de valores do mesmo tipo, em uma única variável</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">b) São variáveis específicas para armazenamento de números inteiro</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">c) Trata-se de uma forma de planejamento do algoritmo</a><br><br>");
            client.print("<a class=\".enunciado\"  href=\"/27/on\">d) São formas de estruturar ou organizar dados na memória RAM do computador,<br> de modo que você possa utilizar estes dados de uma forma mais eficiente</a><br><br>");
            client.println("<p><a href=\"#q7\"><button class=\"button\">Proxima</button></a></p><br><br><br><br><br><br></div>");
            if (contador1> contador2) {
              client.println("<p id=\"q7\">jogador 1 você ganhou!</p>");
            }else{
              client.println("<p id=\"q7\">jogador 2 você ganhou!</p>");
            }
            client.println("</body></html>");
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;     
        }
      }
    }
    
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
