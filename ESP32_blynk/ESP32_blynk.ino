/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
int sensorValue;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  timer.setInterval(1000L, sensorDataSend);
}

void loop()
{
  Blynk.run();
  timer.run();
}
void sensorDataSend(){
  sensorValue = analogRead(A0);
  Blynk.virtualWrite(V1, sensorValue);
}
