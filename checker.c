#include <stdio.h>
#include <assert.h>

const float MAX_TEMP = 45;
const float MIN_TEMP = 0;
const float MAX_SOC = 80;
const float MIN_SOC = 20;
const float MAX_ChargeRate = 0.8;

int temperatureIsOk(float temperature)
{
    if(temperature < MIN_TEMP || temperature > MAX_TEMP) 
    {
      printf("Temperature out of range!\n");
      return 0;
    }
    else
    {
      return 1;
    }
}

int socIsOk(float soc)
{
  if(soc < MIN_SOC || soc > MAX_SOC) 
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else
  {
    return 1;
  }
}
int chargeRateIsOk(float chargeRate)
{
  if(chargeRate > MAX_ChargeRate) 
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else
  {
    return 1;
  }
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int retval;
  retval = temperatureIsOk(temperature) && socIsOk(soc) && chargeRateIsOk(chargeRate);
}

/*
int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < MIN_TEMP || temperature > MAX_TEMP) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}
*/

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
