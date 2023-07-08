#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>

int ledState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
long interval = 800;

int step1 = 15;  //15
int step2 = 15;   
int val = 0;

int clue = 0;


const char *ssid = "K1CuboChallenge"; // The name of the Wi-Fi network that will be created
const char *password = "";   // The password required to connect to it, leave blank for an open network

ESP8266WebServer server(80);

//1cubo6ksxGSM5RwbUB9xaTdLm8dL5NwTw
//5KR1NmfpJvczkcUvtx52tGvPg2eXoDf2acTEYUGSkoep9cU8Xi7

void handleRoot();              // function prototypes for HTTP handlers
void handleNotFound();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  pinMode(step1, INPUT);
  //pinMode(step2, INPUT_PULLDOWN_16);
  Serial.begin(115200);
  
  Serial.println("Booting...");
}


// the loop function runs over and over again forever
void loop() {
  
  unsigned long currentMillis = millis();

  if (currentMillis > 1000 && clue == 0)
  {
    Serial.println("");
    Serial.println("Welcome to the #K1CuboChallenge, you were able to establish a serial connection.");
    Serial.println("Here is the first part of the private key:");
    Serial.println("===================================================");
    Serial.println("5KR1***********************************************");
    Serial.println("===================================================");
    Serial.println("The second clue is: D8 wants to go HIGHer, just like BITCOIN!");
    clue = 1;
  }

  val = digitalRead(step1);

  if (val && interval == 800)
  {
      Serial.println("Well done, you set D8 to HIGH");
      Serial.println("Here is the second part of the private key:");
      Serial.println("===================================================");
      Serial.println("5KR1NmfpJvcz***************************************");
      Serial.println("===================================================");
      Serial.println("The third clue is: Your MicroController is now a source of 2.4GHz radiation!!!");
      clue = 2;
      interval = 300;
          
      Serial.println("You won't be getting any more clues here.");
      delay(500);
      Serial.end();
      WiFi.softAP(ssid);             // Start the access point

      //Serial.print("IP address:\t");
      //Serial.println(WiFi.softAPIP()); 
          
      server.on("/", handleRoot);               // Call the 'handleRoot' function when a client requests URI "/"
      server.on("/final", handleFinal);               // Call the 'handleRoot' function when a client requests URI "/"
      server.on("/621c3de226f0b7947a273edd6e071405d2f43c6e89836ade9895a9f9a88c5dde", handleFinal2);               // Call the 'handleRoot' function when a client requests URI "/"
      server.on("/569da1165da2a35ac634ce08f1f18f56237669c3bc07c47fbc9c6ee9a5324ac4", handleFinal2);               // Call the 'handleRoot' function when a client requests URI "/"
      server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
      server.begin();           
      
  }


  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN, ledState);
  }

  if (clue > 1)
  {
    
      server.handleClient();

  }
}

void handleRoot() {
  if (interval == 300) { interval = 100; }

  String output = "";

			String output5State = "off";
            // Display the HTML web page
            
            output += "<!DOCTYPE html><html>";
            output += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
            output += "<link rel=\"icon\" href=\"data:,\">";
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            output += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
            output += ".button { background-color: #F7931A; border: none; color: white; padding: 16px 40px;";
            output += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
            output += "</style></head>";
            
            // Web Page Heading
            output += "<body><h1>#K1CuboChallenge</h1>";
            
            output += "<p>Good job! You reached the next step.</p>";
            output += "<p>Here is the third part of the private key:</p>";
            output += "<p>===================================================</p>";
            output += "<p>5KR1NmfpJvczkcUv***********************************</p>";
            output += "<p>===================================================</p>";
            
            output += "<p><button class=\"button\" disabled onclick='window.location=\"/final\"'>Continue</button></a></p>";
               
            output += "</body></html>";

  server.send(200, "text/html", output);   // Send HTTP status 200 (Ok) and send some text to the browser/client
}
void handleFinal2() {
  
  interval = 99999999999999;
  ledState = LOW;

  String output = "";
output += "<!DOCTYPE html><html>";
output += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
output += "<link rel=\"icon\" href=\"data:,\">";
output += "<title>Congratulations!</title>";
output += "<style>";
output += "body {";
output += "  font-family: Arial, sans-serif;";
output += "  background-color: #fff;";
output += "  color: #000;";
output += "  text-align: center;";
output += "  padding: 50px;";
output += "}";
output += ".prize-box {";
output += "  margin: auto;";
output += "  width: fit-content;";
output += "  padding: 20px;";
output += "  border: 2px solid #F7931A;";
output += "  border-radius: 15px;";
output += "  text-align: center;";
output += "  font-size: 20px;";
output += "  color: #F7931A;";
output += "}";
output += "</style>";
output += "</head>";
output += "<body>";
output += "<h1>Congratulations!</h1>";
output += "<p>You've successfully completed the #K1CuboChallenge.</p>";
output += "<div class=\"prize-box\">";
output += "Your reward awaits! Here's your secret key: <br/>";
output += "<strong>5KR1NmfpJvczkcUvtx52tGvPg2eXoDf2acTEYUGSkoep9cU8Xi7</strong>";
output += "<p><img src=\"data:image/png;base64,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\"></p>";
output += "</div>";
output += "</body>";
output += "</html>";



  server.send(200, "text/html", output);   // Send HTTP status 200 (Ok) and send some text to the browser/client
}
void handleFinal() {
  if (interval == 100) { interval = 25; }

  String output = "";

            // Display the HTML web page
            
            output += "<!DOCTYPE html><html>";
            output += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
            output += "<link rel=\"icon\" href=\"data:,\">";
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            output += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
            output += ".button { background-color: #F7931A; border: none; color: white; padding: 16px 40px;";
            output += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
            output += "</style></head>";
            
            // Web Page Heading
            output += "<body><h1>#K1CuboChallenge</h1>";
            
            output += "<p>You are SO CLOSE! This is the last step.</p>";
            output += "<p>Here is the next part of the private key:</p>";
            output += "<p>===================================================</p>";
            output += "<p>5KR1NmfpJvczkcUvtx52tGvP***************************</p>";
            output += "<p>===================================================</p>";
            output += "<p>In a world where SHAdows cast 256 dimensions, the key you already hold conceals the treasure you seek. To unlock, one must delve into the cryptic depths.</p>";
            
            output += "<p><input type=\"text\" name=\"crypt\" id=\"crypt\"><br>";
            output += "<button class=\"button\" onclick='window.location=\"/\" + document.getElementById(\"crypt\").value'>Give me Bitcoin!</button></a></p>";
               
            output += "</body></html>";

  server.send(200, "text/html", output);   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleNotFound(){
  server.send(404, "text/plain", "404: You took a wrong turn"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

