# Отчет по лабораторной работе N 11 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Шаталов Максим Алексеевич\
Контакты: rcmaksim@gmail.ru \
Работа выполнена: 06.11.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Простейшие приёмы лексического анализа

## 2. Цель работы

Написание конечного автомата, который решает поставленную задачу на языке C

## 3. Задание

Раскодировать текст, закодированный по Цезарю с переменным ключом, равным номеру слова в строке.

## 4. Оборудование

Процессор: Intel Core i5-8265U @ 8x 3.9GH\
ОП: 7851 Мб\
НМД: 1024 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **18.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**

## 6. Идея, метод, алгоритм решения задачи

Производим посимвольное чтение из файла с тестом. Каждую букву раскодируем смещая ее на (-1*номер слова в строке)
## 7. Сценарий выполнения работы

План:
состояния 0-поиск начала слова 1-работа с буквами слова 2-конец слова

1. открываем на чтение файл
2. изначально состояние равно 0
3. пока не достигли конца файла читаем символ
4. если состояние равно 0
	1. если ввели букву то состояние равно 1 иначе состояние равно 0
5. если состояние равно 1
	1. если ввели символ пробела, табуляции, сброса коретки то состояние равно 0
	2. если ввели букву то перекодируем ее с помощью функции newc
повторяем пункт 3

функция newc()
1. если при сдвиге мы не выходим за первую букву алфавита, то возвращяем сдвинутую букву.
2. иначе возвращаем смещение относительно конца алфавита.

## 8. Распечатка протокола

a a a a a a a a a a

```
z y x w v u t s r q

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                                                | Действие по исправлению   | Примечание     |
|---|---------------|------------|-----------|--------------------------------------------------------|---------------------------|----------------|
|1  | Дом           | 06.11.2023 | 13:50     | ошибка компиляции из-за отсутствия ;   | Написал ;             | Совсем забыл про ;| невнимательность
|2  | Дом           | 07.11.2023 | 02:50     | не правильно открывался файл              | написал сикнтаксически верное открытитие| не прочитал как правильно открывать файл|

## 10. Замечания автора по существу работы

Еще раз убедился в очень удобном программировании на языке C, язык очень прост в осовоении и дает очень много возможностей для программирования.

## 11. Выводы

Это был мой первый конечный автомат на языке C, цель работы достигнута, все поставленнные задачи выполнены. Выполнение данной лабораторной работы доставило удовольствие.

