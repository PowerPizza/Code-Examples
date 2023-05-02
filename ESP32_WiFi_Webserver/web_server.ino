#include <WiFi.h>

char *ssid = "";  // your network's name/ssid
char *password = "";  // your network's password

WiFiServer server(80);  // creating a server object which will run on port 80 [HTTP port].

void setup() {
  Serial.begin(115200);
  Serial.println("Started");
  WiFi.begin(ssid, password);  // wifi connecting.
  while (WiFi.status() != WL_CONNECTED){  // printing (.) till wifi not connected to network.
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected [IP]: "); Serial.println(WiFi.localIP());  // printing local ip address of esp32 in the network.
  server.begin();  // [MOST IMPORTANT]  launching the http server.
}

void loop() {
  WiFiClient cli = server.available();  // accepting HTTP client [one who will visit local ip].
  if (cli){  // client is online true so,
    Serial.println("Client arrived");
    while (cli.connected()){  // client is online at our server and ready to recieve a response.
      if (cli.available()){  // client is waiting for a response of his request [GET, POST].
        Serial.print("Client is available");
        char data_ = cli.read();  // reading data of client request.
        Serial.println(data_);  // printing the request of client.
        if (data_ == '\n'){  // if request is newline.
          /*
           * the proper http response is required before sending any response.
           * the syntax of http response is given.
            HTTP/1.1 200 OK
            Content-type: text/html
            Connection: close
          */
          cli.println("HTTP/1.1 200 OK");  // sending http response with code 200 [all is ok].
          cli.println("Content-type: text/html");  // defining content's type we going to send in this response.
          cli.println("Connection: close");  // closing the connection for entring data in response.
          cli.println();  // required.
          cli.println("Hello World");  // sending hello world you can put any html code here as string.
          cli.println();  // required.
          break;  // ending the response + letting load the webserver.
        }
      }
    }
  }
}