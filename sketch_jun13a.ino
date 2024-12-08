#include <Adafruit_DRV2605.h>
#define TCAADDR 0x70

Adafruit_DRV2605 drv;
char incomingData;

void setup() {
  Serial.begin(9600);

  tcaselect(7);
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.selectLibrary(1);
  drv.setWaveform(0, 81);
  drv.setWaveform(1, 3);
  drv.setWaveform(2, 0);

  tcaselect(6);
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.selectLibrary(1);
  drv.setWaveform(0, 81);
  drv.setWaveform(1, 3);
  drv.setWaveform(2, 0);

  tcaselect(5);
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.selectLibrary(1);
  drv.setWaveform(0, 81);
  drv.setWaveform(1, 3);
  drv.setWaveform(2, 0);

  tcaselect(4);
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.selectLibrary(1);
  drv.setWaveform(0, 81);
  drv.setWaveform(1, 3);
  drv.setWaveform(2, 0);

  tcaselect(3);
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.selectLibrary(1);
  drv.setWaveform(0, 81);
  drv.setWaveform(1, 3);
  drv.setWaveform(2, 0);
  
}

void loop() {
  if (Serial.available() > 0) {
    incomingData = Serial.read();
  }

  if ( incomingData == '1'){
    tcaselect(7);
    drv.go();}

  if ( incomingData == '2'){
    tcaselect(7);
    drv.stop();}

  if ( incomingData == '3'){
    tcaselect(6);
    drv.go();}

  if ( incomingData == '4'){
    tcaselect(6);
    drv.stop();}

  if ( incomingData == '5'){
    tcaselect(5);
    drv.go();}

  if ( incomingData == '6'){
    tcaselect(5);
    drv.stop();}

  if ( incomingData == '7'){
    tcaselect(4);
    drv.go();}

  if ( incomingData == '8'){
    tcaselect(4);
    drv.stop();}

  if ( incomingData == '9'){
   
    tcaselect(3);
    drv.go();}

  if ( incomingData == 'a'){
    tcaselect(3);
    drv.stop();}


}


void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}
