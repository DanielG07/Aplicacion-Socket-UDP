# Aplicacion-Socket-UDP
Aplicación Cliente-Servidor Socket UDP.

Utilizando el lenguaje C para Linux, implemente un cliente UDP (SOCK_DGRAM) que envíe cuatro números cualesquiera a un servidor (uno a la vez), el servidor ordenará los números de mayor a menor y posteriormente realizará la multiplicación del primer número con el cuarto número, al resultado obtenido se le restará el segundo número y finalmente se multiplicará el resultado por el tercer número, si el resultado final es menor a 5000, el servidor mandará un mensaje al cliente indicando que los datos son correctos, en caso contrario mandará un mensaje de datos incorrectos y pedirá al cliente que vuelva a mandar cuatro números, esto se repetirá hasta que el resultado obtenido de las operaciones sea menor de 5000.

## Pasos para creacion de archivos ejecutables (Linux)

### Instalacion de paquete gcc

En una terminal hacer la instalacion del paquete gcc con los siguientes comandos:

    sudo apt-get update
    sudo apt-get install gcc

### Descarga de archivos .c

Primer paso es la descargar los archivos UDPClient.c y UDPServer.c y ubicarlos en una dirección conocida.

### Creacion de archivos ejecutables

Abrir terminal y ubicarte en la direccion donde se encuentre los archivos .c. Usando el siguiente comand.

    cd
    
Una vez posicionado en la direccion donde se ubican los archivos .c ejecutar el siguiente comando para la creacion de ejecutables:

    gcc UDPServer.c -o Server
    gcc UDPClient.c -o Client
   
Despues de la ejecución de los comando se generan dos archivos con los nombres de Server y Client los cuales son los ejecutables.

### Ejecución

Para probar o ejecutar los programas, es necesario abrir dos terminales para la ejecución de cada programa. El siguiente comando se ejecutar para probarlos. Es necesario estar ubicados en la dirección donde se encuentran los ejecutables.

    ./Server
    ./Client
    
NOTA: Es necesario ejecutar primero el servidor y despues el cliente. Ademas los programas solo han sido probados en un mismo equipo de computo.
