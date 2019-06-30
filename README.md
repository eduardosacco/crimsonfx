# CrimsonFx
Interfaz grafica y nucleo de procesamiento de efectos de Crimson Fx

## Instalación de Qt en Linux y configuración del proyecto CrimsonGUI
Los siguientes pasos instalarán Qt 5.7.0 en el ordenador. Se precisa un sistema operativo Linux (por ejemplo, Ubuntu o Mint).
1.	Descargar el instalador de Qt Open Source del sitio web de Qt y, al correrlo, seleccionar la opción de instalar Qt 5.7.0.
2.	En la terminal, correr los siguientes comandos para instalar las herramientas necesarias para compilar y ejecutar el proyecto  
`sudo apt-get update`  
`sudo apt-get install build-essential libgl1-mesa-dev`  
3.	En Qt ir a Tools>Options>Build&Run>Options y seleccionar los compiladores:  
 	`C: GCC(C, x86 64bit in /usr/bin)`  
  `C++: GCC(C++, x86 64bit in /usr/bin)`  
  
## Instalación de Pure Data en Raspberry Pi
Para instalar Pure Data en la placa Raspberry Pi, deben seguirse los siguientes pasos desde la placa Raspberry Pi:
1.	Descargar `puredata_0.48.1.orig.tar.gz` (o alguna version mas nueva) de el repositorio de descargas de Debian
2.	Abrir una terminal y correr los comandos:  
`sudo apt-get install autoconf automake libasound2-dev libtool`   
3.	Abrir una terminal en la carpeta donde se descargó el fichero del paso 1 y ejecutar los siguientes comandos:  
`tar -xzf puredata_0.48.1.orig.tar.gz`  
`cd pd-0.48-1`  
`./autogen.sh`  
`./configure`  
`sudo make install`  
`sudo apt-get install --reinstall tk`  

## Instalación de librerías de Qt en Raspberry Pi (Raspbian Jesse UNICAMENTE)
Para instalar las librerías de Qt en la placa Raspberry Pi, se utilizó QtRpi. Puede verse un video tutorial en la carpeta qtrpi de este repositorio.
Deben seguirse los siguientes pasos desde el ordenador (linux):  
1. Instalar dependencias de qtrpi:  
`sudo apt-get install curl g++ gdb-multiarch git coreutils unzip zip`
2. Generar key ssh y publicarla a la raspberry, usar el ip de la rpi, para verlo usar `ifconfig` desde la terminal:  
`ssh-keygen`  
`ssh-copy-id pi@192.168.1.20`  
`ssh pi@192.168.1.20`  
`exit`  
3.	Clonar el repositorio o bajar el archivo zip.  
`git clone https://github.com/neuronalmotion/qtrpi.git`  
`cd qtrpi`
4.	Si se desea instalar una versión específica de QtRpi, deben configurarse las siguientes variables de entorno:  
`export QTRPI_QT_VERSION='5.6.2'`  
`export QTRPI_TARGET_DEVICE='linux-rpi3-g++'`  
`export QTRPI_TARGET_HOST='pi@1.2.3.4'`  
La última exportación, QTRPI_TARGET_HOST, debe contener la dirección IP de la Raspberry Pi que se esté utilizando. Esta variable será levantada más adelante por el script deploy-qtrpi.sh para deployar los archivos binarios de Qt.
3.	Correr el script. Una vez que las variables de entorno hayan sido configuradas, ejecutar el siguiente comando desde el repositorio clonado:  
`/init-qtrpi-minimal.sh`  
    1. Este comando fallara dado que la pagina web de donde se intentaran descargar los archivos `sysroot-minimal-latest.zip` y `qtrpi-rpi3_qt-5.7.0.zip` esta caida, como workaround deberemos:
    2. Descargar los archivos manualmente desde la carpeta de crimson fx de google drive https://drive.google.com/drive/folders/1OLeTtp_wzkhfvdjtgCXoouhutJ0woIYy?usp=sharing y colocarlos en la carpeta `/opt/qtrpi`
    3. Ir a `/qtrpi/utils/common.sh` y comentar las lineas de codigo (anteponiendo #) 
 `curl $QTRPI_CURL_OPT -o $SYSROOT_ZIP $QTRPI_SYSROOT_URL` y  
 `curl $QTRPI_CURL_OPT -o $QTRPI_ZIP $QTRPI_MINIMAL_URL`
    4. Ejecutar nuevamente `/init-qtrpi-minimal.sh` 
6.	Verificar la instalación. Al finalizar la ejecución del script, debería figurar un nuevo directorio, /opt/qtrpi, con:
 bin: contiene qmake-qtrpi, un enlace simbólico al qmake pre-configurado
 raspbian: el directorio raíz del sistema
 raspi: la toolchain, Qt pre-configurado, Qt pre-compilado para Raspberry Pi
7.	Deployar en Raspberry Pi
 Una vez que la Raspberry Pi sea alcanzable, ejecutar:
`./deploy-qtrpi.sh --prepare-rpi`  
Este script conectará a la Raspberry Pi e instalará o actualizará todo lo necesario para correr aplicaciones de Qt. 
El script utilizará el comando sudo varias veces para instalar los paquetes. Debe agregarse la clave SSH en la Raspberry Pi (usando ssh-copy-id, por ejemplo) o actualizar /home/user/.netrc para evitar el re-tipeo de la contraseña.
Al finalizar el script, la Raspberry Pi debe contener el directorio /usr/local/qt5pi con Qt pre-compilado para Raspberry Pi.
8.	Agregar el directorio /opt/qtrpi/bin agregar a PATH:  
 `export PATH=/opt/qtrpi/bin:$PATH`
9.	Agregar esta línea a /home/user/.bashrc:  
 `source ~/.bashrc`

## Compilación cruzada de aplicaciones Qt 
Una vez que qtrpi fue instalado en la PC y desplegado en la placa, se puede compilar el proyecto para la placa, siguiendo los pasos desde la terminal:  
`cd myproject`  
`/opt/qtrpi/bin/qmake-qtrpi`  
(la ruta complete puede ser omitida si se agregó /opt/qtrpi/bin al PATH)  
`make`  
* Si hay error al ejecutar `make`:
 `recipe for target 'main.o' failed`
  Ejecutar comando `make clean`
El archivo binario generado está listo para copiarse y ejecutarse en la Raspberry

## Configuracion para auto ejecucion de CrimsonFX y CrimsonGUI
En la terminal en rpi o bien mediante ssh ingresar el comando:
`sudo nano /etc/rc.local`  
Antes de la linea 'exit o' agregar las siguientes lineas:  
`sudo pd -nogui /home/pi/Documents/Pd/externals/CrimsonFX.pd &`  
`sudo /home/pi/CrimsonGUI &`  
Guardar el archivo, al reiniciar el dispositivo los programas iniciaran automagicamente.
