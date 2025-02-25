""""
 * Calcula dónde estará un robot (sus coordenadas finales) que se
 * encuentra en una cuadrícula representada por los ejes "x" e "y".
 * - El robot comienza en la coordenada (0, 0).
 * - Para idicarle que se mueva, le enviamos un array formado por enteros
 *   (positivos o negativos) que indican la secuencia de pasos a dar.
 * - Por ejemplo: [10, 5, -2] indica que primero se mueve 10 pasos, se detiene,
 *   luego 5, se detiene, y finalmente 2.
 *   El resultado en este caso sería (x: -5, y: 12)
 * - Si el número de pasos es negativo, se desplazaría en sentido contrario al
 *   que está mirando.
 * - Los primeros pasos los hace en el eje "y". Interpretamos que está mirando
 *   hacia la parte positiva del eje "y".
 * - El robot tiene un fallo en su programación: cada vez que finaliza una
 *   secuencia de pasos gira 90 grados en el sentido contrario a las agujas
 *   del reloj.
"""

def robot(move):
    x=0
    y=0
    rotate_x = True
    rotate_y = False
    for i in range(len(move)):
        steps = move[i]
        if ((i+1)%2) == 0:
            if steps > 0:
                if rotate_x:
                    rotate_x = False
                    x -= steps
                else:
                    rotate_x = True
                    x += steps
            else:
                if rotate_x:
                    rotate_x = False
                    x += steps
                else:
                    rotate_x = True
                    x -= steps
            steps = 0
        else:
            if steps > 0:
                if rotate_y:
                    rotate_y = False
                    y -= steps
                else:
                    rotate_y = True
                    y += steps
            else:
                if rotate_y:
                    rotate_y = False
                    y -= steps
                else:
                    rotate_x = True
                    y += steps
        steps = 0
    return print(f"(x: {x}, y: {y})")
arreglo = [0, 0, 0]
robot(arreglo)
    