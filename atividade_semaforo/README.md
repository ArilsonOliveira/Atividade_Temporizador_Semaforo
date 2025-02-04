## Atividade_Temporizador_Semaforo
Projeto para desenvolver temporizador periódico utilizando a placa BitDogLab.

## Projeto Semáforo com Raspberry Pi Pico W

# Descrição do Projeto

Este projeto implementa um semáforo utilizando o microcontrolador Raspberry Pi Pico W que é integrado à placa de estudo BitDogLab. O sistema projetado visa controlar três LEDs (vermelho, amarelo (Azul na placa BitDogLab) e verde) para simular o funcionamento de um semáforo de trânsito. O tempo de transição entre os estados é de 3 segundos, e uma mensagem correspondente ao estado atual do semáforo é impressa na porta serial a cada segundo.

# Componentes Utilizados

- Raspberry Pi Pico W

- 3 LEDs (vermelho, amarelo e verde)

- 3 resistores de 330Ω

- Software: Pico SDK

- Simulador Wokwi

- Visual Studio Code

# Funcionamento

O sistema inicia com o LED vermelho aceso, indicando "Pare".

1- Após 3 segundos, o LED vermelho é desligado e o LED amarelo acende, indicando "Atenção".

2- Depois de mais 3 segundos, o LED amarelo apaga e o LED verde acende, permitindo a passagem "Prossiga, caminho livre".

3- Após 3 segundos, o LED verde desliga e o LED vermelho acende novamente, reiniciando o ciclo.

A cada segundo, o estado atual do semáforo é impresso na porta serial.

# Estrutura do Código

* Configuração dos GPIOs: Define os pinos como saída e inicializa os LEDs.

* Função de callback do temporizador: Alterna entre os estados do semáforo a cada 3 segundos.

* Loop principal: Exibe na porta serial a cor do LED ativo a cada segundo.

# Instruções de Uso

Configure e instale o Pico SDK no seu ambiente de desenvolvimento através da extensão do Raspberry Pi Pico Project, caso não seja feita automaticamente.

Compile e carregue o código no Raspberry Pi Pico W na BitDogLab.

Ative a visualização da porta serial da BitDogLab no Visual Code para visualizar as mensagens de estado do semáforo.

Observe a alternância dos LEDs conforme o ciclo de 3 segundos.

# Possíveis Melhorias

Implementar um sistema de pedestres.

Ajustar os tempos de transição para diferentes cenários.

# Autor

Desenvolvido por Arilson S. Oliveira, como prática pessoal e requisito de atividade avaliativa da Residência em Sistemas Embarcados Embarcatech, com foco em aprendizado da Raspberry Pi Pico W e placa BitDogLab.


