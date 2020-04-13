/***************************************************************   
          Tutorial Ethernet Shield   
  Objetivo: Uso do cartão micro SD para hospedagem de site HTML  
  Autor: Felipe Souza Amaral   
  ***************************************************************/   
 #include <SPI.h>  
 #include <Ethernet.h>  
 #include <SD.h>  
 byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
 IPAddress ip(192,168,0,2); // IP address  
 EthernetServer server(80); // conexão pela porta 80  
 File webFile;  
 void setup()  
 {  
   Ethernet.begin(mac, ip);   
   server.begin();        
   Serial.begin(9600);      
   // inicialização SD card  
   Serial.println("Carregando SD card...");  
   if (!SD.begin(4)) {  
     Serial.println("ERROR - SD card FAIL!");  
     return;    
   }  
   Serial.println("SUCCESS - SD card carregado.");  
   // arquivo index.htm   
   if (!SD.exists("index.htm")) {  
     Serial.println("ERROR - FAIL index.htm file!");  
     return; // sem localização do cartão SD  
   }  
   Serial.println("SUCCESS - arquivo index.htm .");  
 }  
 void loop()  
 {  
   EthernetClient client = server.available(); // tentativa de conexão com o client  
   if (client) {   
     boolean currentLineIsBlank = true;  
     while (client.connected()) {  
       if (client.available()) {    
         char c = client.read();   
         if (c == '\n' && currentLineIsBlank) {  
           client.println("HTTP/1.1 200 OK");  
           client.println("Content-Type: text/html");  
           client.println("Connection: close");  
           client.println();  
           webFile = SD.open("index.htm");      
           if (webFile) {  
             while(webFile.available()) {  
               client.write(webFile.read());   
             }  
             webFile.close();  
           }  
           break;  
         }  
         if (c == '\n') {  
           currentLineIsBlank = true;  
         }   
         else if (c != '\r') {  
           currentLineIsBlank = false;  
         }  
       }   
     }   
     delay(1);     
     client.stop();   
   }   
 }  
