#include <SPI.h>
#include <Ethernet.h>

/******************** ETHERNET SETTINGS ********************/

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x85, 0xD9 };   //physical mac address
byte ip[] = { 169, 254, 29, 1 };                   // ip in lan
byte subnet[] = { 255, 255, 255, 0 };              //subnet mask
byte gateway[] = { 192, 168, 0, 1 };              // default gateway
EthernetServer server(80);                       //server port


void setup()
{
Ethernet.begin(mac,ip,gateway,subnet);     // initialize Ethernet device
server.begin();                                // start to listen for clients
pinMode(8, INPUT);                            // input pin for switch
}

void loop()
{
EthernetClient client = server.available();    // look for the client

// send a standard http response header

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connnection: close");
client.println();

/* 
This portion is the webpage which will be
sent to client web browser one can use html , javascript
and another web markup language to make particular layout 
*/

client.println("<!DOCTYPE html>");      //web page is made using html
client.println("<html>");
client.println("<head>");
client.println("<title>Ethernet Tutorial</title>");
client.println("<meta http-equiv=\"refresh\" content=\"1\">");

/*
The above line is used to refresh the page in every 1 second
This will be sent to the browser as the following HTML code:
<meta http-equiv="refresh" content="1">
content = 1 sec i.e assign time for refresh 
*/

client.println("</head>");
client.println("<body>");
client.println("<h1>A Webserver Tutorial </h1>");
client.println("<h2>Observing State Of Switch</h2>");

client.print("<h2>Switch is:  </2>");

if (digitalRead(8))
{
client.println("<h3>ON</h3>");
}
else
{
client.println("<h3>OFF</h3>");
}

client.println("</body>");
client.println("</html>");

delay(1);         // giving time to receive the data

/*
The following line is important because it will stop the client
and look for the new connection in the next iteration i.e
EthernetClient client = server.available();
*/
client.stop();

}
