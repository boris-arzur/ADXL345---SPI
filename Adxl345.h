

#ifndef Accelerometer_h
#define Accelerometer_h
#include <SPI.h>
/* ------- Register names ------- */
#define ADXL345_DEVID 0x00
#define ADXL345_RESERVED1 0x01
#define ADXL345_THRESH_TAP 0x1d
#define ADXL345_OFSX 0x1e
#define ADXL345_OFSY 0x1f
#define ADXL345_OFSZ 0x20
#define ADXL345_DUR 0x21
#define ADXL345_LATENT 0x22
#define ADXL345_WINDOW 0x23
#define ADXL345_THRESH_ACT 0x24
#define ADXL345_THRESH_INACT 0x25
#define ADXL345_TIME_INACT 0x26
#define ADXL345_ACT_INACT_CTL 0x27
#define ADXL345_THRESH_FF 0x28
#define ADXL345_TIME_FF 0x29
#define ADXL345_TAP_AXES 0x2a
#define ADXL345_ACT_TAP_STATUS 0x2b
#define ADXL345_BW_RATE 0x2c
#define ADXL345_POWER_CTL 0x2d
#define ADXL345_INT_ENABLE 0x2e
#define ADXL345_INT_MAP 0x2f
#define ADXL345_INT_SOURCE 0x30
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_DATAX0 0x32
#define ADXL345_DATAX1 0x33
#define ADXL345_DATAY0 0x34
#define ADXL345_DATAY1 0x35
#define ADXL345_DATAZ0 0x36
#define ADXL345_DATAZ1 0x37
#define ADXL345_FIFO_CTL 0x38
#define ADXL345_FIFO_STATUS 0x39

/* 
 Interrupt PINs
 INT1: 0
 INT2: 1
 */
#define ADXL345_INT1_PIN 0x00
#define ADXL345_INT2_PIN 0x01

/* 
 Interrupt bit position
 */
#define ADXL345_INT_DATA_READY_BIT 0x07
#define ADXL345_INT_SINGLE_TAP_BIT 0x06
#define ADXL345_INT_DOUBLE_TAP_BIT 0x05
#define ADXL345_INT_ACTIVITY_BIT   0x04
#define ADXL345_INT_INACTIVITY_BIT 0x03
#define ADXL345_INT_FREE_FALL_BIT  0x02
#define ADXL345_INT_WATERMARK_BIT  0x01
#define ADXL345_INT_OVERRUNY_BIT   0x00

class Accelerometer
{
public:
  Accelerometer(int spiSelectPin);
  void powerOn();
  void readAccel(int* x, int* y, int* z);

  void setAxisOffset(int x, int y, int z);
  void getAxisOffset(int* x, int* y, int*z);

  float getRate();
  void setRate(float rate);

  void getRangeSetting(byte* rangeSetting);
  void setRangeSetting(int val);
  bool getSelfTestBit();
  void setSelfTestBit(bool selfTestBit);
  bool getSpiBit();
  void setSpiBit(bool spiBit);
  bool getFullResBit();
  void setFullResBit(bool fullResBit);
  bool getJustifyBit();
  void setJustifyBit(bool justifyBit);
  void printAllRegister();

private:
  int _selectPin;
  void writeTo(int device, byte address, byte val);
  void readFrom(int device, byte address, int num, byte buff[]);
  void setRegisterBit(byte regAdress, int bitPos, bool state);
  bool getRegisterBit(byte regAdress, int bitPos);  
  byte _buff[6] ;    //6 bytes buffer for saving data read from the device
};

#endif

