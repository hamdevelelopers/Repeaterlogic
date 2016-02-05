/*
Playing sounds from SD card. Based on simple audio player.

*/

#include <SD.h>
#include <SPI.h>
#include <Audio.h>
File callsign, callsign_beacon, callsign2, callsign_beacon2, file1, file2, file3, file4, file5, file6, file7, file8, file9, file0, filepoint;
#define dualrepeater;

void setup()
{
  // debug output at 9600 baud
  Serial.begin(9600);

  // setup SD-card
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println(" failed!");
    return;
  }
  Serial.println(" done.");
  // hi-speed SPI transfers
  SPI.setClockDivider(4);

  // 44100Khz stereo => 88200 sample rate
  // 100 mSec of prebuffering.
  Audio.begin(88200, 100);

  if (!loadfiles()) {
    while (true);
  };
}

void loop()
{


  // open wave file from sdcard


  playfile(callsign_beacon);

  Serial.println("End of file. Thank you for listening!");
  while (true) ;


}

void playfile(File myFile) {
  int count = 0;
  const int S = 1024; // Number of samples to read in block
  short buffer[S];

  Serial.print("Playing");
  // until the file is not finished
  while (myFile.available()) {
    // read from the file into buffer
    myFile.read(buffer, sizeof(buffer));

    // Prepare samples
    int volume = 1024;
    Audio.prepare(buffer, S, volume);
    // Feed samples to audio
    Audio.write(buffer, S);

    // Every 100 block print a '.'
    count++;
    if (count == 100) {
      Serial.print(".");
      count = 0;
    }
  }
  myFile.close();

}

bool loadfiles()
{
  File callsign_beacon = SD.open("LA5DRb.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }
  File callsign = SD.open("LA5DR.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }

#if defined(dualrepeater)
  File callsign_beacon2 = SD.open("LA9DRb.wav");
  if (!callsign_beacon2) {
    Serial.println("error opening callsign_beacon.wav");
  }
  File callsign2 = SD.open("LA9DR.wav");
  if (!callsign2) {
    Serial.println("error opening callsign.wav");
  }
#endif

  File callsign_beacon = SD.open("1.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }

  File callsign = SD.open("2.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }

  File callsign_beacon = SD.open("3.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }

  File callsign = SD.open("4.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }

  File callsign_beacon = SD.open("5.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }
  
  File callsign = SD.open("6.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }
  
  File callsign_beacon = SD.open("7.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }
  
  File callsign = SD.open("8.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }
  
  File callsign_beacon = SD.open("9.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }
  
  File callsign = SD.open("0.wav");
  if (!callsign) {
    Serial.println("error opening callsign.wav");
  }
  
  File callsign_beacon = SD.open("point.wav");
  if (!callsign_beacon) {
    Serial.println("error opening callsign_beacon.wav");
  }



}
