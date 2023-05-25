//code 1.2
#include <Servo.h> 


Servo horizontal; // horizontal servo
int servoh = 90;  //180
int servohLimitHigh = 180; //175
int servohLimitLow = 1; //5
// 65 degrees MAX

Servo vertical; // vertical servo
int servov = 90; //45
int servovLimitHigh = 180; //60
int servovLimitLow = 1; //1

// LDR pin connections
// name = analogpin;
int ldrlt = A0; //LDR top left - BOTTOM LEFT <--- BDG -TL-  T //0
int ldrrt = A2; //LDR top rigt - BOTTOM RIGHT  -TR- B //2
int ldrld = A1; //LDR down left - TOP LEFT  -LB- L //1
int ldrrd = A3; //ldr down rigt - TOP RIGHT  -RB- R  //3

void setup(){
horizontal.attach(9);
vertical.attach(10);
horizontal.write(90);
vertical.write(90);
delay(2500);
}
void loop() {
int t = analogRead(ldrlt); // top left //T
int l = analogRead(ldrrt); // top right //B
int r = analogRead(ldrld); // down left // L
int d = analogRead(ldrrd); // down right //R
int dtime = 10; int tol = 45; // dtime=diffirence time, tol=toleransi
//int avt = (lt + rt) / 2; // average value top
//int avd = (ld + rd) / 2; // average value down
//int avl = (lt + ld) / 2; // average value left
//int avr = (rt + rd) / 2; // average value right
//int dvert = avt - avd; // check the diffirence of up and down
//int dhoriz = avl - avr;// check the diffirence og left and rigt
int dvert = t - d;
int dhoriz = l - r;
if (-1*tol > dvert || dvert > tol) 
 {
 if (t > d)
 {
 servov = --servov; //++
 if (servov > servovLimitHigh)
 {servov = servovLimitHigh;}
 }
 else if (t < d)
 {servov = ++servov; //--
 if (servov < servovLimitLow)
 { servov = servovLimitLow;}
 }
 vertical.write(servov);
 }
if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
 {
 if (l > r)
 {
 servoh = --servoh; //--
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (l < r)
 {
 servoh = ++servoh;//++
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 else if (l == r)
 {
 delay(5000);
 }
 horizontal.write(servoh);
 }
 
 delay(dtime);
 
}
