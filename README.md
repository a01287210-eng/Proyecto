Documentacion

NOMBRE: Angel Enrique Tiburcio Martinez                    FECHA: 29/07/2026
MATRICULA: A01287210

Simulación de batalla

Introducción
Buscamos representar una batalla entre dos ejércitos formados por distintos tipos de combatientes, cada uno con diferentes reglas de combate. La idea es modelar esta variedad de comportamientos sin duplicar código para cada tipo utilizando herencia, polimorfismo, entre otros temas que adquirimos en clase, al igual cargar los datos de los combatientes desde archivos .txt en vez de escribirlos en el código, y simular duelos hasta que uno de los dos ejércitos quede sin combatientes vivos, mostrando en pantalla el desarrollo de cada pelea y el resultado final de esta.

Herencia
Guerrero, Arquero y Mago heredan públicamente de Personaje, ya que “Personaje” concentra los atributos y características a cualquier combatiente, como la vida, salud, ataque, nivel, y los métodos para atacar, recibir daño y su estado. Cada clase hija agrega su propio atributo especial (fuerza en Guerrero, precisión en Arquero, “mana” en Mago) y utiliza herencia en todo lo demás sin volver a escribirlo, lo que nos evita escribir cosas como la vida y salud en sus respectivos bloques de código.

Polimorfismo
Personaje declara varios métodos como virtual calculaAtaque, recibeAtaque, atacar, Cada clase hija sobrescribe calculaAtaque, recibeAtaque e imprimir con su propia versión, y dentro de esa version normalmente llama primero a la versión de Personaje para reutilizar el calculo base y despues le agrega su propio ajuste. Por ejemplo, Guerrero::calculaAtaque llama a Personaje::calculaAtaque y le suma fuerza / 2; Mago::recibeAtaque decide cuánto reducir el dano segun su nivel y su mana antes de llamar a Personaje::recibeAtaque.
Gracias a esto, el codigo que maneja la batalla en exercise.cpp nunca necesita saber si esta trabajando con un Guerrero, un Arquero o un Mago. Los dos ejercitos se guardan como un “vector<Personaje*>”, y cuando se ejecuta “c1->atacar(*c2)” o “p->imprimir()”, C++ decide en tiempo de ejecución cuál versión del metodo ejecutar según el tipo real del objeto apuntado. Esto es lo que permite que la función de batalla y la función que presenta a los ejércitos funcionen igual sin importar de qué clase sea cada combatiente.

Clase abstracta
Personaje::calculaAtaque se declaró como método puro virtual, esto convierte a Personaje en una clase abstracta, por lo que no se pueden crear objetos de tipo Personaje directamente, solo de sus clases hijas, que tienen que implementar ese mismo método. Un "Personaje" genérico sin un tipo específico de combate no debería poder pelear por sí mismo, sólo existe como base para definir el comportamiento común que Guerrero, Arquero y Mago comparten y especializan. Aun con este, Personaje::calculaAtaque conserva su implementación en el .cpp, y las clases hijas la siguen llamando explicitamente (Personaje::calculaAtaque (objetivo)) para reutilizar el calculo base antes de aplicar su propio ajuste.

Sobrecarga de operadores
Se sobrecargó el operador > en Personaje para comparar la salud actual de dos combatientes, este se usa dentro de la función duelo() para decidir, al terminar un combate, compara cuál de los dos combatientes quedó en mejor estado: en vez de comparar manualmente con c1->getSalud() > c2->getSalud(), el código queda más claro y más cercano al lenguaje natural escribiendo *c1 > *c2, tratando a los combatientes casi como si fueran valores que se pueden comparar directamente.

Excepciones
La función cargarEjercito lanza una excepción “runtime_error” en dos casos: si el archivo del ejército no se puede abrir, y si encuentra en el archivo un tipo de combatiente que no reconoce. En main(), la carga de los dos ejércitos está dentro de un bloque try/catch,si se lanza cualquiera de esas excepciones, el catch la captura, imprime el mensaje de error obtenido con e.what() y termina el programa de forma controlada (return 1) en vez de dejar que truene con un archivo corrupto o datos inválidos.

Conclusion 
Este proyecto me permitio ver de forma practica por que la herencia y el polimorfismo ahorran trabajo y me enseñó a implementarlos en un caso util como lo es un videojuego, ademas de que sin ellos, la función de batalla tendria que revisar  de que tipo es cada combatiente constantemente para saber cómo debe atacar o defenderse, lo que le tomaria mas tiempo de correr al programa. Convertir a Personaje en una clase abstracta también hace que todo combatiente real sea de un tipo específico, y no un Personaje cualquiera. Agregar el manejo de excepciones además mostró la diferencia entre un programa que se cae ante un error de datos y uno que informa el problema y logra terminar de correr el programa, en vez de atorarse si tuviese un error.

