#include <WiFi.h>
#include <PubSubClient.h>

//Wifi Setup

const char *ssid = "wifi-name-here";      // Enter your WiFi name
const char *pw = "password-here";  // Enter WiFi password

//inc MQTT
const char *mqtt_broker = "ip-address-here";  // Enter your WiFi or Ethernet IP
const char *topic = "test/topic";
const int mqtt_port = 1883;

//clnt
WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
    Serial.begin(ssid,pw);

    while(WiFi.status() !+ WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi");

    }

    Serial.println("Succesfully connected to WiFi.");

    //broker
    client.setServer(mqtt_broker, mqtt_port);

    client.setCallback(callback);

    while(!client.connected)
    {

        String client_id = "esp8266-client-";
        
        client_id += String(WiFi.macAddress());

        Serial.printf("The client %s connects to mostquitto mqtt broker", client_id.cstr());
        printf("\n");
        fflush(stdout);

        if(client.connect(client_id.c_str()))
        {
            Serial.println("Public MQTT Broker Succesfully Connected");
            else
            {
                Serial.print("Failed with state");
                Serial.print(client.state());

                delay(2000);

            }
        }

        //pub&sub
        client.publish(topic, "ESP32 would like to play a game of tic-tac-toe!");
        client.subscribe(topic);

    }
    
}

void callback(char *topic, byte *payload, unsigned int length) 
{

  Serial.print("Message arrived in topic: ");

  Serial.println(topic);

  Serial.print("Message:");

  for (int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }

  Serial.println();
  Serial.println(" - - - - - - - - - - - -");
}


void loop() 
{
  client.loop();

}
