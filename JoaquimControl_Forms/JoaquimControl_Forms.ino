#include <ssl_client.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>

#define chaveID "entry.1433246606" // Pergunta 1
#define chaveTime  "entry.467123702" // Horário
#define chaveForms "1FAIpQLSf-EVgZtMlZMmLVBSzfgLeRJin02x6ySvkh4HNnn3vsFh27-Q" //Chave do forms
WiFiClientSecure client;

// Dados do wifi

const char* ssid = "Sangsunga";
const char* password = "ibis2211";
int i = 0;

void setup() {
  // Inicialização do ESP32
  Serial.begin(115200);
  Serial.println("Client has started");

  // Conectando na rede
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void loop() {
    // put your main code here, to run repeatedly:
   if (client.connect("docs.google.com", 443)) {
      String paraEnviar = "GET /forms/d/e/";
      paraEnviar += chaveForms;
      paraEnviar += "/formsResponse?";
      paraEnviar += chaveID;
      paraEnviar += "=";
      paraEnviar += "11609177"; //Receber ID do leitor;
      paraEnviar += "&";
      paraEnviar += chaveTime;
      paraEnviar += "=";
      paraEnviar += "10:30:20";// Receber horário
      paraEnviar += "&submit=Submit HTTP/1.1";
      client.println(paraEnviar);
      client.println("Host: docs.google.com");
      client.println();
      client.stop();
      Serial.print("Dados enviados");
   }  else  {
       Serial.println("Erro ao conectar");
       Serial.println("Tentando reconectar");
       
   }while not (client.connect("docs.google.com", 443) {   // ver issooooooooooooooo
       
       Serial.print(".");
       delay(500); 
        
        }
   }
}
}
