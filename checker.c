#include <stdio.h>
#include <assert.h>

#define MAX_TEMP  (45f)
#define MIN_TEMP  (0f)

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

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
