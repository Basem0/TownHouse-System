#include "HumiditySensor.h"
#include <Bonezegei_DHT11.h>

Bonezegei_DHT11 dht(32);

int humidity() {
    int humidityValue = 0;
    if (dht.getData()) {
        humidityValue = dht.getHumidity();
        // Uncomment the next line if you need to print humidity to Serial
        // Serial.printf("Humidity: %d - ", humidityValue);
    }
    return humidityValue;
}

