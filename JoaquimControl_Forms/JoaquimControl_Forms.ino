#include <ssl_client.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>

#define chaveID "entry.1433246606" // Pergunta 1
#define ChaveTime "entry.467123702" // Horário
#define ChaveForms "1FAIpQLSf-EVgZtMlZMmLVBSzfgLeRJin02x6ySvkh4HNnn3vsFh27-Q" //Chave do forms
WiFiClientSecure client;

//dados do wifi

const char* ssid = "sangsunga";
const char* password = "ibis2211";

void setup() {
  // Inicialização do ESP32
  Serial.begin(115200);
  Serial.println("Client has started");

  // Conectando na rede
  WiFi.begin(rede, senha);
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
      paraEnviar += "/formsResponse?"
      paraEnviar += chaveID;
      paraEnviar += "="
      paraEnviar += // Receber ID do leitor
      paraEnviar += "&"
      paraEnviar += chaveTime;
      paraEnviar += "="
      paraEnviar += // Receber horário
      paraEnviar += "&submit=Submit HTTP/1.1";
      client.println(paraEnviar);
      client.println("Host: docs.google.com")
      client.println();
      client.stop();
      Serial.print("Dados enviados");
   }  else  {
      Serial.print("Erro ao conectar");
   }
}
https://docs.google.com/forms/d/e/1FAIpQLSf-EVgZtMlZMmLVBSzfgLeRJin02x6ySvkh4HNnn3vsFh27-Q/viewform?usp=pp_url&entry.1433246606=11609177&entry.467123702=12:30:30

https://docs.google.com/forms/d/e/1FAIpQLScela3DKCOph3kJgsqbcnC31An9tmrq-2sTvAzK3qlPRGnnvQ/viewform?usp=pp_url&entry.513051709=batata
