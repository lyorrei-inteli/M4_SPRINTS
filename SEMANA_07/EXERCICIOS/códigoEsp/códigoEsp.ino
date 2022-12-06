#include <WiFi.h>
#include <WebServer.h>

#define BLUE_LED 21
#define RED_LED 5

const char* ssid = "ESP32";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

WebServer server(80);

void player_one_won () {
  digitalWrite(BLUE_LED, HIGH);
  delay(1000);
  digitalWrite(BLUE_LED, HIGH);
  server.send(200); 
}

void player_two_won () {
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, HIGH);
  server.send(200); 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.print("Conectando-se ao Wi-Fi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/playerone", player_one_won);
  server.on("/playertwo", player_two_won);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
