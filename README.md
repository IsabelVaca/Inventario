
# Inventario de Tienda
Este programa permite llevar el inventario de una tienda y realizar las siguientes tareas:
Ordenar los datos por su precio
Ordenar los datos por el stock disponible
Desplegar inventario




# Competencias

Avance 1

SICT0301: Evalúa los componentes
En el programa se utiliza el algoritmo de ordenamiento "Selection sort", este algoritmo tiene una complejidad temporal de O(n^2)
y una complejidad de espacio de O(1). 

SICT0302: Toma decisiones
Se seleccionó este algoritmo debido a la poca o media cantidad de datos utilizados, es fácil de implementar y comprender lo que evita problemas, 
se realizan pocos swaps, no requiere memoria extra, para este avance funciona bien, pero si es necesario se harán modificaciones. 

Avance 2
Estructura lineal utilizada Queues

SICT0301: Evalúa los componentes

Para verificar el id del producto al hacer la orden O(n)
Ver inventario O(n)
ver queue O(n)

O(n)

SICT0302: Toma decisiones

Se utilizaron queues para el manejo de pedidos, es una estructura adecuada ya que los pedidos se envian en el orden en el que se van agregando, 
de esta manera se pueden procesar y mandar en un orden. Lo implementé en la funcion orders donde se pueden crear pedidos sencillos en un queue 
y eliminarlos al momento de que son enviados, esto en el orden FIFO.

SICT0303: Implementa acciones científicas

Se puede acceder a los productos del inventario y verificar su stock, al momento de realizar un pedido la cantidad de stock es modificada.

Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

#Referencias
Stoi
https://cplusplus.com/reference/string/stoi/
getline
https://www-geeksforgeeks-org.translate.goog/cpp/getline-string-c/?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=tc
