#include <ESP8266WiFi.h>
#include <Servo.h>

WiFiServer server(80); //Initialize the server on Port 80
const short int LED_PIN = 16;  

// Declare Servos
Servo servo_one;
Servo servo_two;

String mainpage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP); 
  WiFi.softAP("Not Your Network", "12345678"); // Provide the (SSID, password); .
  server.begin(); // Start the HTTP Server
  IPAddress HTTPS_ServerIP = WiFi.softAPIP(); // Obtain the IP of the Server
  Serial.print("Server IP is: "); // Print the IP to the monitor window
  Serial.println(HTTPS_ServerIP);
  pinMode(LED_PIN, OUTPUT); //GPIO16 is an OUTPUT pin;
  servo_one.attach(D1);
  servo_two.attach(D2);
  digitalWrite(LED_PIN, LOW); //Initial state is ON
  // Prepare the HTML document to respond and add buttons:
      mainpage = "HTTP/1.1 200 OK\r\n";
      mainpage += "Content-Type: text/html\r\n\r\n";
      mainpage += "<br><h1>Justin's Starbucks Coffee Xylophone</h1><br>";
      mainpage += "<!DOCTYPE HTML>\r\n<html>\r\n";
      mainpage += "<br><h3>Notes</h3>";
      //Notes
      mainpage += "<input type=\"button\" name=\"b1\" value=\"G\" onclick=\"location.href='/G'\">&nbsp;";
      mainpage += "<input type=\"button\" name=\"b1\" value=\"A\" onclick=\"location.href='/A'\">&nbsp;";
      mainpage += "<input type=\"button\" name=\"b1\" value=\"B\" onclick=\"location.href='/B'\">&nbsp;";
      mainpage += "<input type=\"button\" name=\"b1\" value=\"C\" onclick=\"location.href='/C'\">&nbsp;";
      mainpage += "<input type=\"button\" name=\"b1\" value=\"D\" onclick=\"location.href='/D'\">&nbsp;";
      mainpage += "<input type=\"button\" name=\"b1\" value=\"E\" onclick=\"location.href='/E'\">&nbsp;";
      mainpage += "<br><br><br>";
      //Calibrate
      mainpage += "<br><h3>Calibrate</h3>";
      mainpage += "<br><input type=\"button\" name=\"b1\" value=\"Calibrate\" onclick=\"location.href='/Calibrate'\">";
      mainpage += "<br><br><br>";
      //Play Song
      mainpage += "<br><h3>Play Songs</h3>";
      mainpage += "<br><input type=\"button\" name=\"b1\" value=\"Track 1\" onclick=\"location.href='/Auto'\">";
      mainpage += "<br><br><br>";
      mainpage += "</html>\n";

}

void calibrate() {
  // run through all notes to calibrate positioning of bottles 
  for (int i = 0; i <= 180; i+=35) {
    servo_one.write(i);
    delay(1000);
    servo_two.write(45);
    delay(50);
    servo_two.write(135);
    delay(40);
    servo_two.write(45);
    servo_two.write(90);
    delay(100);
  }
  for (int i = 180; i >= 0; i-=35) {
    servo_one.write(i);
    delay(1000);
    servo_two.write(45);
    delay(50);
    servo_two.write(135);
    delay(40);
    servo_two.write(45);
    servo_two.write(90);
    delay(100);
  }
}

void strike(int duration) {
    // lower and raise hammer to create sound
    servo_two.write(45);
    delay(50);
    servo_two.write(135);
    delay(40);
    servo_two.write(45);
    servo_two.write(90);
    delay(duration);  
};



void playNote(char note, int duration) {
  int num = 1;
  // convert from note to numerical value
  switch(note) {
    case 'G':
      num = 1;
      break;
    case 'A':
      num = 2;
      break;
    case 'B':
      num = 3;
      break;
    case 'C':
      num = 4;
      break;
    case 'D':
      num = 5;
      break; 
    case 'E':
      num = 6;
      break;
  };
  int val = 35*(num - 1);
  // move servo to correct bottle
  servo_one.write(val);
  delay(250);
  strike(duration);
}

void playSong() {
  // play pre-recorded song (Theme of Ode to Joy)
  char notes[30] = {'B', 'B', 'C', 'D', 'D', 'C', 'B', 'A', 'G', 'G', 'A', 'B', 'B', 'A', 'A', 'B', 'B', 'C', 'D', 'D', 'C', 'B', 'A', 'G', 'G', 'A', 'B', 'A', 'G', 'G'};
  int duration[30] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 750, 250, 1000, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 750, 250, 1000};
  for (int i = 0; i < sizeof(notes); i++) {
    playNote(notes[i], duration[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("Connection established...");
  //Read what the browser has sent into a String class and print the request to the monitor
  String request = client.readStringUntil('\r');
  //Looking under the hood
  Serial.println(request);
  // Handle the Request
  if (request.indexOf("/Auto") != -1){
    playSong();
    Serial.println("Auto");
  }
  else if (request.indexOf("/Calibrate") != -1){
    calibrate();
    Serial.println("Calibrate");
  }
  else if (request.indexOf("/G") != -1){
    Serial.println("G");
    playNote('G', 250);
    Serial.println("G");
  }
  else if (request.indexOf("/A") != -1){
    Serial.println("A");
    playNote('A', 250);
    Serial.println("A");
  }
  else if (request.indexOf("/B") != -1){
    Serial.println("B");
    playNote('B', 250);
    Serial.println("B");
  }
  else if (request.indexOf("/C") != -1){
    Serial.println("C");
    playNote('C', 250);
    Serial.println("C");
  }
  else if (request.indexOf("/D") != -1){
    Serial.println("D");
    playNote('D', 250);
    Serial.println("D");
  }
  else if (request.indexOf("/E") != -1){
    Serial.println("E");
    playNote('E', 250);
    Serial.println("E");
  }
  //Serve the HTML document to the browser.
  client.flush(); //clear previous info in the stream
  client.print(mainpage); // Send the response to the client
  delay(1);
  Serial.println("Finished");
}
