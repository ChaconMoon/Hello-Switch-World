/* Librería para el uso de strings */
#include <string.h>

/* Librería éstandar de input / output de */
#include <stdio.h>

/* Librerias éstandar de C*/
#include <stdlib.h>

/* Librería de Devkitpro para desarrollar para switch*/
#include <switch.h>

int main(int argc, char **argv)
{
        // Iniciamos el servicio de la consola desde la switch
        consoleInit(NULL);

        // Configuramos el mando del primer jugador en modo Standard
        padConfigureInput(1, HidNpadStyleSet_NpadStandard);

        PadState pad;
        padInitializeDefault(&pad);

        // Salido por consola
        printf("\x1b[1;2HHola Mundo, soy Carlos Chacon desde una Nintendo Switch,o mas bien un emulador\x1b[2;2Hporque no tengo la switch pirata.\x1b[3;2H(https://github.com/ChaconMoon/Hello-Switch-World)");
        printf("\x1b[5;2H\x1b[4mPulsa el boton + para salir del programa.");

        // Actualiza el estado de la consola
        consoleUpdate(NULL);

        // Bucle de la aplicación. appletMainloot es el bucle por defecto de la aplicación.
        while (appletMainLoop())
        {
                // Actualiza el estado de los mandos
                padUpdate(&pad);

                // Obtiene el estado de los botones pulsados
                u64 buttonPressed = padGetButtonsDown(&pad);

                if (buttonPressed & HidNpadButton_Plus)
                {
                        break;
                }

                                // Actualiza el estado de la consola
                consoleUpdate(NULL);
        }

        // Limpieza de los servicios de la consola antes de finalizar la ejecución del software
        consoleExit(NULL);

        return 0;
}
