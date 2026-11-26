#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FreeRTOS.h"
#include "task.h"

void vBlinkTask(void *pvParameters) {
    (void)pvParameters;
    for (;;) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(250));
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}

int main() {
    if (cyw43_arch_init()) {
        return -1;   // Wireless chip failed to initialise
    }

    xTaskCreate(vBlinkTask, "Blink Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    return 0;
}
