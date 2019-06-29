# CrimsonFx

## Instalación de Qt en Linux y configuración del proyecto CrimsonGUI
Los siguientes pasos instalarán Qt 5.7.0 en el ordenador. Se precisa un sistema operativo Linux (por ejemplo, Ubuntu o Mint).
1.	Descargar el instalador de Qt Open Source del sitio web de Qt [23] y, al correrlo, seleccionar la opción de instalar Qt 5.7.0.
2.	En la terminal, correr los siguientes comandos para instalar las herramientas necesarias para compilar y ejecutar el proyecto
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libgl1-mesa-dev
3.	En Qt ir a Tools>Options>Build&Run>Options y seleccionar los compiladores:
 	`C: GCC(C, x86 64bit in /usr/bin)`
  `C++: GCC(C++, x86 64bit in /usr/bin)`
  
## Instalación de Pure Data en Raspberry Pi
Para instalar Pure Data en la placa Raspberry Pi, deben seguirse los siguientes pasos desde la placa Raspberry Pi:
1.	Descargar puredata_0.48.1.orig.tar.gz de el repositorio de descargas de Debian [24]
2.	Abrir una terminal y correr los comandos:
`sudo apt-get install autoconf`
`sudo apt-get install automake`
`sudo apt-get install libasound2-dev`
`sudo apt-get install libtool`
3.	Abrir una terminal en la carpeta donde se descargó el fichero del paso 1 y ejecutar los siguientes comandos
`tar -xzf puredata_0.48.1.orig.tar.gz`
`cd pd-0.48-1`
`./autogen.sh`
`./configure`
`sudo make install`
`sudo apt-get install --reinstall tk`

## Instalación de librerías de Qt en Raspberry Pi
Para instalar las librerías de Qt en la placa Raspberry Pi, se utilizó QtRpi [25].  Deben seguirse los siguientes pasos desde el ordenador:
1.	Clonar el repositorio o bajar el archivo zip.
 `git clone https://github.com/neuronalmotion/qtrpi.git`
 `cd qtrpi`
2.	Si se desea instalar una versión específica de QtRpi, deben configurarse las siguientes variables de entorno.
`export QTRPI_QT_VERSION='5.6.2'`
`export QTRPI_TARGET_DEVICE='linux-rpi3-g++'`
`export QTRPI_TARGET_HOST='pi@1.2.3.4'`
La última exportación, QTRPI_TARGET_HOST, debe contener la dirección IP de la Raspberry Pi que se esté utilizando. Esta variable será levantada más adelante por el script deploy-qtrpi.sh para deployar los archivos binarios de Qt.
3.	Correr el script. Una vez que las variables de entorno hayan sido configuradas, ejecutar el siguiente comando desde el repositorio clonado. 
`/init-qtrpi-minimal.sh`
4.	Verificar la instalación. Al finalizar la ejecución del script, debería figurar un nuevo directorio, /opt/qtrpi, con:
 bin: contiene qmake-qtrpi, un enlace simbólico al qmake pre-configurado
 raspbian: el directorio raíz del sistema
 raspi: la toolchain, Qt pre-configurado, Qt pre-compilado para Raspberry Pi
5.	Deployar en Raspberry Pi
 Una vez que la Raspberry Pi sea alcanzable, ejecutar:
 `./deploy-qtrpi.sh --prepare-rpi`
Este script conectará a la Raspberry Pi e instalará o actualizará todo lo necesario para correr aplicaciones de Qt. 
El script utilizará el comando sudo varias veces para instalar los paquetes. Debe agregarse la clave SSH en la Raspberry Pi (usando ssh-copy-id, por ejemplo) o actualizar /home/user/.netrc para evitar el re-tipeo de la contraseña.
Al finalizar el script, la Raspberry Pi debe contener el directorio /usr/local/qt5pi con Qt pre-compilado para Raspberry Pi.
6.	Exportar la ruta de QtRpi bin (opcional)
 Agregar el directorio /opt/qtrpi/bin agregar a PATH.
 export PATH=/opt/qtrpi/bin:$PATH
7.	Agregar esta línea a /home/user/.bashrc
 `source ~/.bashrc`
 
## Compilación cruzada de aplicaciones Qt 
Una vez que qtrpi fue instalado en la PC y desplegado en la placa, se puede compilar el proyecto para la placa, siguiendo los pasos desde la terminal:
`cd myproject`
`/opt/qtrpi/bin/qmake-qtrpi` 
(la ruta complete puede ser omitida si se agregó /opt/qtrpi/bin al PATH)
`make`
El archivo binario generado está listo para copiarse y ejecutarse en la Raspberry
