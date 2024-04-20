# Первая задача
## Задание
* Добавить токены `max`, `sqr`
* Реализовать `ParseName`
* Закончить `Tokenize`
## Реализация
Реализовал функцию `ParseName`, позволяющую строку разбить на симовлы, 
разделенные одним или несколькими символами(в данной реализации - `' '`)

Реализация функции `Tokenize`, которая вызывает `ParseName`. После 
этого каждая часть строки приводится к своему типу токена при помощи
функции `ToToken`

В файле `main.cpp` показывается, как работает `Tokenize` на примере.