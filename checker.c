#include <stdio.h>
#include <assert.h>

// Constants for acceptable ranges
#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

// Function to check if temperature is within acceptable range
int isTemperatureOk(float temperature) {
    return (temperature >= TEMP_MIN && temperature <= TEMP_MAX);
}

// Function to check if state of charge (SOC) is within acceptable range
int isSOCOk(float soc) {
    return (soc >= SOC_MIN && soc <= SOC_MAX);
}

// Function to check if charge rate is within acceptable range
int isChargeRateOk(float chargeRate) {
    return (chargeRate <= CHARGE_RATE_MAX);
}

// Function to check overall battery status
int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!isTemperatureOk(temperature)) {
        fprintf(stderr, "Error: Temperature out of range (%d-%d°C)!\n", TEMP_MIN, TEMP_MAX);
        return 0;
    }

    if (!isSOCOk(soc)) {
        fprintf(stderr, "Error: State of Charge out of range (%d-%d%%)!\n", SOC_MIN, SOC_MAX);
        return 0;
    }

    if (!isChargeRateOk(chargeRate)) {
        fprintf(stderr, "Error: Charge Rate out of range (<= %.2f)!\n", CHARGE_RATE_MAX);
        return 0;
    }

    return 1;
}

int main() {
    // Test cases using assertions
    assert(batteryIsOk(25, 70, 0.7));   // Should pass
    assert(!batteryIsOk(50, 85, 0));    // Should fail due to temperature and SOC out of range

    printf("Tests passed successfully.\n");

    return 0;
}
