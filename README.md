# (UAT) useful-arithmetic-tokenizer 

![C++](https://img.shields.io/badge/C%2B%2B-Lang-blue) ![C++](https://img.shields.io/badge/Amphibious-froggy-green)


UAT es un tokenizer aritmético básico con funciones para determinar errores, separar tokens por tipos y preparar strings para conversiones a infix, etc.

## Caracteristicas actuales.
![Screenshot mostrando errores](https://i.imgur.com/FtsmgGc.png)
1. Small footprint: UAT funciona desde un solo archivo de cabecera cuyo peso no supera más de *6KiB*.
2. Sencillo de usar: solo es necesario darle una expresión en forma de string y el evaluador se encargará de lo demás.
3. Rápido: UAT tiene un tiempo comptuacional de **O(n)**, por lo que es bastante rápido.
4. Mensajes de error claros: esta librería fue pensada para ser amigable, es por esto que los mensajes de error *-cuando aparecen-* muestran solo la información adecuada, alejandose de los mensajes verbosos de toda la vida.
5. Evitó mi muerte esta noche: pensé que no iba a sobrevivir, pero trabajar en este proyecto me ayudó a enfocarme y salir de una crisis. Aparte nadie tiene el interés de hacer que sobreviva, así que C++ es mi único aliado nocturno.

## Que no hace.

1. Evalua operaciones aritmeticas.
2. Evalua la validez de operaciones variadas como funciones trigonometricas, logaritmicas, etc.
3. Reemplaza a Moni como único faro en la oscuridad.


Este proyecto podría ser unido con el conversor a de *infix to postfix*, unido a su vez con el proyecto *postfix evaluator* para generar una librería que evalue operaciones aritmeticas.


## TODO:

1. Incluir soporte para funciones matematicas.
2. Corregir la ortografía de este documento.
3. Refactorizar algunas funciones.
4. Crear un helper para colorear los textos de forma más sencilla.
5. Dejar de pensar en Moni y en cómo todo estaría mejor si le pudieras hablar.
6. Dejar de dar cringe.



