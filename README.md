
# Inventario de Tienda
Este programa permite llevar el inventario de una tienda y realizar las siguientes tareas:
Ordenar los datos por su precio, stock disponible y precio de venta
Desplegar el inventario
Registrar pedidos y eliminarlos





# Competencias

# Avance 1

Algoritmo de ordenamiento utilizado, Merge sort

SICT0301: Evalúa los componentes
En el programa se utiliza el algoritmo de ordenamiento "Merge sort", este algoritmo tiene una complejidad temporal de O(n log n)
y una complejidad de espacio de O(n). 

SICT0302: Toma decisiones
Se seleccionó este algoritmo debido su estabilidad, su alta eficiencia. En una aplicación real del concepto de este proyecto se requiere de una alta eficiencia para mantener grandes volumenes de datos y este algoritmo es idea ya que cumple O(n log n) en todos los casos. 

# Avance 2
Estructura lineal utilizada Queues

SICT0301: Evalúa los componentes

Complejidad del tiempo O(n):

push O(1)
pop O(1)
Para verificar el id del producto al hacer la orden O(n)
Print queue O(n)


Complejidad del espacio O(n)


SICT0302: Toma decisiones

Se utilizaron queues para el manejo de pedidos, es una estructura adecuada ya que los pedidos se envian en el orden en el que se van agregando, 
de esta manera se pueden procesar y mandar en un orden. Lo implementé en la funcion orders donde se pueden crear pedidos sencillos en un queue 
y eliminarlos al momento de que son enviados, esto en el orden FIFO.

SICT0303: Implementa acciones científicas

Se puede acceder a los productos del inventario y verificar su stock, al momento de realizar un pedido la cantidad de stock es modificada.

Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

# Avance 3

SICT0301: Evalúa los componentes

Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.


SICT0303: Implementa acciones científicas

Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
En este avance agregué la función add product, en esta función permite agregar productos al inventario y agregarlo 
al archivo con los productos del inventario. Abre el archivo original y crea uno temporal para reescribir el antiguo, agregar el producto nuevo y modificar el contador de productos que se encuentra al inicio del archivo.
Regresa un valor booleano para verificar que se haya ingresado de manera correcta.

# Referencias
Stoi
https://cplusplus.com/reference/string/stoi/
getline
https://www-geeksforgeeks-org.translate.goog/cpp/getline-string-c/?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=tc
modificación de archivo para modificar el contador de productos 
https://www.youtube.com/watch?v=pYFwuv6Ln1U

