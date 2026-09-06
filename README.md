# Hello Switch World

Un pequeño Hello World para **la consola Nintendo Switch**, creado para aprender los fundamentos de desarrollo en C para la Switch con **devkitPro y libnx**.

<p align="center">
  <img src=".github/images/Program Screenshot.png" alt="Captura del programa" width="700px"/>
</p>

## ¿Qué incluye?

- Inicializar la pantalla de la Nintendo Switch.
- Mostrar texto por consola.
- Capturar los inputs del mando para salir del programa.

## Requisitos

La forma recomendada de compilar el proyecto es utilizar el contenedor de
desarrollo incluido. Para ello necesitas:

- [Visual Studio Code](https://code.visualstudio.com/).
- [Docker](https://www.docker.com/).
- La extensión [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) para Visual Studio Code.

También puedes instalar manualmente devkitA64 y las bibliotecas necesarias
desde los repositorios oficiales de [devkitPro](https://devkitpro.org/).

## Primeros pasos

### 1. Clonar el repositorio

```bash
git clone https://github.com/ChaconMoon/Hello-Switch-World.git
cd Hello-Switch-World
```

### 2. Abrir el contenedor de desarrollo

Instala la extensión de Dev Containers si todavía no la tienes:

```bash
code --install-extension ms-vscode-remote.remote-containers
```

Abre el proyecto en Visual Studio Code y ejecuta el comando
`Dev Containers: Reopen in Container` desde la paleta de comandos
(`Ctrl+Shift+P`). Visual Studio Code utilizará la configuración de
`.devcontainer/devcontainer.json` y preparará el entorno de compilación.

### 3. Compilar

Desde la terminal del contenedor, ejecuta:

```bash
make
```

Los archivos generados son `HelloSwitchWorld.nro`, `HelloSwitchWorld.nacp` y `HelloSwitchWorld.elf`. Los archivos intermedios se guardan en `build/`.

Para limpiar la compilación:

```sh
make clean
```

## Ejecutar

Copia `HelloSwitchWorld.nro` en la ubicación de aplicaciones homebrew de tu dispositivo o emulador y ejecútalo desde el entorno correspondiente.

Pulsa `+` para cerrar la aplicación.

## Cómo funciona
 
1. `consoleInit(NULL)`: Inicializa la consola de texto.
2. `padConfigureInput()`: Configura el primer mando conectado.
3. `PadState pad` y `padInitializeDefault(&pad)`: Inicializa el estado del mando.
4. `consoleUpdate(NULL)`: Actualiza el estado actual de la consola.
5. `padUpdate()`: Actualiza el estado de los mandos.
6. `padGetButtonsDown()`: Obtiene los botones pulsados.

## Estructura del proyecto

```text
.
├── .devcontainer/       # Configuración del contenedor de desarrollo.
├── .vscode/             # Configuración de Visual Studio Code.
├── icon.jpg             # Icono de la aplicación (256 x 256 píxeles).
├── Makefile             # Configuración de compilación para devkitPro/libnx.
└── source/              # Código fuente de la aplicación.
    └── main.c           # Código principal de la aplicación.
```