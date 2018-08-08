#include <Nextion.h>
//#include <INextionColourable.h>
#include <SoftwareSerial.h>

SoftwareSerial nextionSerial(10, 11); // RX, TX

Nextion nex(nextionSerial);

void setup() {
  Serial.begin(115200);

  nextionSerial.begin(9600);
  nex.init();

  Serial.println(nex.clear(NEX_COL_BLACK));

int width = 480;
int height = 320;
int x0 = width/2;
int y0 = height/2;
int r = y0-5;
int n = 20;
int x[n],y[n];

  for (int i=0; i<n; i++)
{
  float a = i*2*PI/n;
  x[i]=x0 + cos(a)*r;
  y[i]=y0 + sin(a)*r;
}
  for (int i=0; i<n-1; i++)
  {
    for (int j=i+1; j<n; j++) 
    {
  Serial.println(nex.drawLine(x[i],y[i], x[j],y[j], NEX_COL_YELLOW));
    }
  }
}

void loop() {
  nex.poll();
}
