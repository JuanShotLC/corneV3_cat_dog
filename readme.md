\# Corne V3 (crkbd) - Firmware Personalizado "neoncornecatdogwin"



Este repositorio contiene la configuración del firmware QMK para un teclado Corne V3 dividido (Split). Incluye mapas de teclas para Windows y macOS, control de iluminación estática y animaciones OLED reactivas (Perro y Gato) basadas en WPM (palabras por minuto).



\## 1. Preparación del Entorno (Windows)



Para compilar este firmware en Windows, la arquitectura más estable es el entorno nativo de QMK basado en MSYS2.



1\. Descarga e instala \*\*QMK MSYS\*\* desde su página oficial (msys.qmk.fm).

2\. Abre la terminal \*\*QMK MSYS\*\* desde tu menú de inicio.

3\. Instala las dependencias base del sistema y las herramientas de compilación (C y Rust) ejecutando:

```bash

pacman --needed --noconfirm -S git mingw-w64-x86\_64-toolchain mingw-w64-x86\_64-python-pip mingw-w64-x86\_64-rust mingw-w64-x86\_64-zlib mingw-w64-x86\_64-python-pillow



```





4\. Instala la herramienta principal de QMK usando `pip`. En entornos recientes de Python, debes autorizar la instalación global:

```bash

python3 -m pip install --break-system-packages qmk



```





5\. Descarga el repositorio oficial y configura las rutas de compilación ejecutando:

```bash

qmk setup



```







\## 2. Ubicación de los Archivos del Keymap



Los archivos fuente deben estar estrictamente ubicados en la carpeta correspondiente para que el compilador de QMK los detecte.



1\. Abre el Explorador de Archivos y navega a `C:\\Usuarios\\TuUsuario\\qmk\_firmware\\keyboards\\crkbd\\keymaps\\`.

2\. Crea una carpeta nueva y nómbrala exactamente `neoncornecatdogwin`.

3\. Copia tus tres archivos dentro de esta carpeta:

\* `rules.mk`

\* `config.h`

\* `keymap.c`







\*Importante: Verifica en la pestaña "Vista" de Windows que la opción "Extensiones de nombre de archivo" esté activa para asegurar que no se hayan guardado como `.txt` ocultos.\*



\## 3. Compilación del Firmware



1\. En la terminal QMK MSYS, ubícate en la raíz del proyecto:

```bash

cd \~/qmk\_firmware



```





2\. Limpia el historial de caché. Esto es obligatorio si hiciste cambios recientes en `rules.mk` relacionados con los motores RGB:

```bash

qmk clean



```





3\. Compila el código para empaquetarlo en un archivo `.hex`:

```bash

qmk compile -kb crkbd/rev1/common -km neoncornecatdogwin



```





4\. Verás un listado de procesos finalizando con `\[OK]` y el cálculo del peso final del firmware.



\## 4. Proceso de Flasheo (¡CRÍTICO!)



Este teclado utiliza la directiva `EE\_HANDS`. Esto significa que el microcontrolador no adivina su lado por la posición del cable USB; en su lugar, debes inyectar un archivo de configuración en su memoria EEPROM para decirle permanentemente si es la mano izquierda o la derecha. Debido a esto, nunca se debe usar QMK Toolbox.



\*\*⚠️ REGLA DE HARDWARE:\*\* Nunca conectes o desconectes el cable TRRS (el cable de audio) mientras el teclado esté recibiendo energía del USB. Hacerlo puede generar un cortocircuito que queme los pines de tus microcontroladores Elite-C.



\### Flashear la Mano Izquierda



1\. Asegúrate de que el cable TRRS \*\*no\*\* esté conectado. Ambas mitades deben estar físicamente separadas.

2\. Conecta \*\*solo la mitad izquierda\*\* a la computadora por USB.

3\. Ejecuta el comando de flasheo para Elite-C izquierdo:





```bash

qmk flash -kb crkbd/rev1/common -km neoncornecatdogwin -bl dfu-split-left



```





\*(Nota: Para placas Pro Micro tradicionales, se debe usar `avrdude-split-left`)\*.





4\. Cuando la terminal muestre \*Waiting for bootloader...\*, presiona el botón físico de \*\*Reset\*\* en la placa izquierda.

5\. Espera a que confirme la escritura exitosa y desconecta el USB.



\### Flashear la Mano Derecha



1\. Mantén el cable TRRS desconectado.

2\. Conecta \*\*solo la mitad derecha\*\* a la computadora por USB.

3\. Ejecuta el comando de flasheo para Elite-C derecho:





```bash

qmk flash -kb crkbd/rev1/common -km neoncornecatdogwin -bl dfu-split-right



```





4\. Al ver \*Waiting for bootloader...\*, presiona el botón de \*\*Reset\*\* en la placa derecha.

5\. Espera la confirmación y desconecta el USB.



\## 5. Arranque del Sistema



1\. Con los cables USB desconectados, une ambas mitades insertando el cable TRRS de forma segura.

2\. Conecta el cable USB desde tu computadora a la mitad \*\*izquierda\*\* (Master).

3\. El teclado iniciará. La pantalla izquierda mostrará la mascota Master (Perro), las capas actuales y los valores de iluminación. La pantalla derecha mostrará la mascota Slave (Gato) y el contador de WPM en tiempo real.

