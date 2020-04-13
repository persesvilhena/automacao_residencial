#include <SPI.h>
#include <Ethernet.h>
String readString;
int pino_rele1 = 3;
int pino_rele2 = 4;
int pino_rele3 = 5;
int pino_rele4 = 6;
boolean ligado1 = true;
boolean ligado2 = true;
boolean ligado3 = true;
boolean ligado4 = true;
byte mac[] = { 0xA4, 0x28, 0x72, 0xCA, 0x55, 0x2F };
EthernetServer server(80);
void setup()
{
  Serial.begin(9600);
  pinMode(pino_rele1, OUTPUT);
  pinMode(pino_rele2, OUTPUT);
  pinMode(pino_rele3, OUTPUT);
  pinMode(pino_rele4, OUTPUT);
  Ethernet.begin(mac);
  server.begin();
  Serial.println("Automacao Residencial"); 
  digitalWrite(pino_rele1, HIGH);
  digitalWrite(pino_rele2, HIGH);
  digitalWrite(pino_rele3, HIGH);
  digitalWrite(pino_rele4, HIGH);
}
void loop()
{
  EthernetClient client = server.available();
  if (client) {
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100) {
          readString += c;
        }
        if (c == '\n')
        {
          Serial.println(readString);
          if (readString.indexOf("?ligar1") > 0)
          {
            digitalWrite(pino_rele1, LOW);
            Serial.println("Rele 1 Ligado");
            ligado1 = false;
          }
          else
          {
            if (readString.indexOf("?desligar1") > 0)
            {
              digitalWrite(pino_rele1, HIGH);
              Serial.println("Rele 1 Desligado");
              ligado1 = true;
            }
          }
          Serial.println(readString);
          if (readString.indexOf("?ligar2") > 0)
          {
            digitalWrite(pino_rele2, LOW);
            Serial.println("Rele 2 Ligado");
            ligado2 = false;
          }
          else
          {
            if (readString.indexOf("?desligar2") > 0)
            {
              digitalWrite(pino_rele2, HIGH);
              Serial.println("Rele 2 Desligado");
              ligado2 = true;
            }
          }
          Serial.println(readString);
          if (readString.indexOf("?ligar3") > 0)
          {
            digitalWrite(pino_rele3, LOW);
            Serial.println("Rele 3 Ligado");
            ligado3 = false;
          }
          else
          {
            if (readString.indexOf("?desligar3") > 0)
            {
              digitalWrite(pino_rele3, HIGH);
              Serial.println("Rele 3 Desligado");
              ligado3 = true;
            }
          }
          Serial.println(readString);
          if (readString.indexOf("?ligar4") > 0)
          {
            digitalWrite(pino_rele4, LOW);
            Serial.println("Rele 4 Ligado");
            ligado4 = false;
          }
          else
          {
            if (readString.indexOf("?desligar4") > 0)
            {
              digitalWrite(pino_rele4, HIGH);
              Serial.println("Rele 4 Desligado");
              ligado4 = true;
            }
          }
          readString = "";
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<script type='text/javascript'>");
          client.println("function AlteraRele(id){");
          client.println("var estado = document.getElementById('estado' + id).innerHTML;");
          client.println("if(estado === '0'){");
          client.println("document.getElementById('estado' + id).innerHTML='1';");
          client.println("document.getElementById('botao' + id).innerHTML='<a href=/?desligar' + id + '>Desligar Rele ' + id + '</a>';");
          client.println("} else {");
          client.println("document.getElementById('estado' + id).innerHTML='0';");
          client.println("document.getElementById('botao' + id).innerHTML='<a href=/?ligar' + id + '>Ligar Rele ' + id + '</a>';");
          client.println("}}</script>");
          client.println("<div id='botao1'></div><div id='botao2'></div><div id='botao3'></div><div id='botao4'></div>");
          client.print("<div id='estado1' style='visibility: hidden;'>");
          client.print(ligado1);
          client.println("</div>");
          client.print("<div id='estado2' style='visibility: hidden;'>");
          client.print(ligado2);
          client.println("</div>");
          client.print("<div id='estado3' style='visibility: hidden;'>");
          client.print(ligado3);
          client.println("</div>");
          client.print("<div id='estado4' style='visibility: hidden;'>");
          client.print(ligado4);
          client.println("</div><script>AlteraRele(1)</script><script>AlteraRele(2)</script><script>AlteraRele(3)</script><script>AlteraRele(4)</script>");
          delay(1);
          client.stop();
        }
      }
    }
  }
}
