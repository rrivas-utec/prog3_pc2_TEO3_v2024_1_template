# Task #PC2: Practica Calificada 2  
**course:** Programación III  
**unit:** 2 ,3 y 4  
**cmake project:** prog3_pc2_TEO3_v2024_1
## Instructions
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`):
    - `sort_except.h`
    - `tokenize_concurrently.h`
- Adicionalmente, la **pregunta #2** podrá ser elaborada en el mismo archivo de la **pregunta #1**.
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - Ordenar con Exclusión (7 points)

Diseñar y desarrollar dos templates de función que permitan ordenar elementos de un contenedor, excluyendo ciertos elementos de la operación de ordenación. Los elementos excluidos deben permanecer en sus posiciones originales.

Los template de función son los siguientes:
1. **`sort_except`**: Esta función ordena los elementos de un contenedor, excluyendo un valor específico.
2. **`sort_except_if`**: Esta función ordena los elementos de un contenedor, excluyendo aquellos que cumplen con un predicado dado.

Ambas funciones deben recibir dos iteradores (inicio y fin) que definen el rango del contenedor a ordenar.
- **`sort_except`** debe recibir adicionalmente un valor fijo que define los elementos a excluir de la ordenación.
- **`sort_except_if`** debe recibir adicionalmente un predicado que define la condición para excluir elementos de la ordenación.
- Los elementos excluidos deben permanecer en sus posiciones originales dentro del contenedor.

## Caso de Uso: Exclusión de un Valor Fijo
```cpp
  vector<int> vec = {5, 3, 8, 6, 2, 6, 7, 4, 1};
  int exclude_value = 6;
  sort_except(vec.begin(), vec.end(), exclude_value);
  for(const auto& item: vec) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
```
#### Caso de uso #1
Entrada:
```
6
5 3 8 6 2 6 7 4 1
```
Salida:
```
1 2 3 6 4 6 5 7 8
```

#### Caso de uso #2
Entrada:
```
|
pp | mm | aa | ee | ff | yy | gg | vv | dd
```
Salida:
```
aa | dd | ee | ff | gg | mm | pp | vv | yy
```

## Caso de Uso: Exclusión Basada en un Predicado
```cpp
  vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};
  auto exclude_pred = [](int x) { return x % 2 == 0; };
  sort_except_if(vec.begin(), vec.end(), exclude_pred);
  for(const auto& item: vec) {
    cout << item << " ";
  }
  cout << endl;
```

#### Caso de uso #3
Entrada:
```
5 3 8 6 2 7 4 1
```
Predicado:
```cpp
  [](int x) { return x % 2 == 0; }
```
Salida:
```
1 3 8 6 2 5 4 7
```  

#### Caso de uso #4
Entrada:
```
platano a manzana b uva c durazno d
```
Predicado:
```cpp
  [](auto a) { return a.size() == 1; }
```
Salida:
```
durazno a manzana b platano c uva d
```
## Question #2 - Complejidad Algoritmica (6 points)
Determinar la función de tiempo y el Big O de la siguiente función:
```cpp
int funcion(int n) {
    srand(time(0));
    vector<vector<int>> matriz(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    int resultado = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<int> sorted_row = matriz[i];
            sort(sorted_row.begin(), sorted_row.end());
            for (int k = 0; k < log2(n); ++k) {
                resultado += sorted_row[j] * log2(n);
            }
        }
    }

    return resultado;
}
```

## Question #3 - Max Value (7 points)

Diseñar y desarrollar un template de función `parallel_max` que encuentre el valor máximo en un contenedor de elementos utilizando múltiples hilos para mejorar el rendimiento. La función debe dividir el contenedor en partes, procesar cada parte en paralelo y luego combinar los resultados.

- La función debe recibir un contenedor de elementos.
- La función debe utilizar múltiples hilos para encontrar el valor máximo en diferentes partes del contenedor en paralelo.
- La función debe retornar el valor máximo encontrado en el contenedor.

## Caso de Uso
```cpp
    std::vector<int> nums = {1, 5, 3, 9, 2, 8, 4, 7, 6, 0};
    int max_val = parallel_max(nums.begin(), nums.end());
    std::cout << max_val << std::endl;
```

#### Caso de uso #1
Entrada:
```
10 23 15 98 47 56 21 67 89 34 23 76 58 92 45 28 16 73 54 82
```

Salida:
```
98
```

#### Caso de uso #2
Entrada:
```
1.2 3.4 2.1 8.5 4.3 5.6 7.2 6.8 9.0 4.7 3.8 2.9 8.4 7.1 6.3 5.9 9.5 2.2 1.5 8.9
```

Salida:
```
9.5
```
#### Caso de uso #3
Entrada:
```
h e l l o w o r l d p r o g r a m m i n g
```

Salida:
```
w
```
#### Caso de uso #4
Entrada:
```
apple banana kiwi strawberry blueberry cherry watermelon pineapple grape mango papaya
```

Salida:
```
watermelon
```
