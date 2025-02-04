#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_YELLOW 12 //  amarelo representado por azul
#define LED_GREEN 11

volatile int state = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case 0: // Vermelho -> Amarelo
        
        printf("Sinal amarelo. Atenção. \n");
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            state = 1;
            break;
        case 1: // Amarelo -> Verde
        printf("Sinal verde. Prossiga, caminho livre.\n");
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            state = 2;
            break;
        case 2: // Verde -> Vermelho
        
        printf("Sinal vermelho. Pare. \n");
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_RED, 1);
            state = 0;
            break;
    }
    return true; // Continua repetindo
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Inicialização do semáforo na cor vermelha
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // função responsável por chamar a rotina do temporizador
    
    while (true) {
        switch (state) {
            case 0:
                printf("Sinal Vermelho ligado: Pare.\n");
                break;
            case 1:
                printf("Sinal Amarelo ligado: Atenção.\n");
                break;
            case 2:
                printf("Sinal Verde ligado: Prossiga, caminho livre.\n");
                break;
        }
        sleep_ms(1000);
    }
}


