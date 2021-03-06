# Aplicacion-Socket-UDP
Aplicación Cliente-Servidor Socket UDP.

Utilizando el lenguaje C para Linux, implemente un cliente UDP (SOCK_DGRAM) que envíe cuatro números cualesquiera a un servidor (uno a la vez), el servidor ordenará los números de mayor a menor y posteriormente realizará la multiplicación del primer número con el cuarto número, al resultado por el tercer número, si el resultado final es menor a 5000, el servidor mandará un mensaje al cliente indicando que los datos son correctos, en caso contrario mandará un mensaje de datos incorrectos y pedirá al cliente que vuelva a mandar cuatro números, esto se repetirá hasta que el resultado obtenido de las operaciones sea menor de 5000.
