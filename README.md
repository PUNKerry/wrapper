# wrapper

Для реализации процесса триангуляции используется библиотека CGAL. CGAL предоставляет обширный набор алгоритмов для решения задач, 
    связанных с вычислительной геометрией, такими как построение выпуклых оболочек, триангуляция, пересечение объектов.

    В данном случае для построения сетки используется алгоритм Делоне в пространстве - это алгоритм вычислительной геометрии, 
    который строит триангуляцию Делоне для заданного множества точек (облака точек) в пространстве. 

    Для сохранения и чтения из файлов был реализован static util "FileIOUtil"


Примечание: не реализовано сохранение в необходимом формате. (сохраняется перечисление координат вершин треугольников а не нумерация + номера точек, не успел довести до ума)


Условие:


1. Читать исходный файл данных.
Исходный текстовый файл данных содержит четыре колонки цифр, разделенных запятыми. 
Каждая строка текстового файла содержи номер и координату трехмерной точки.
С символа * начинается комментарий. Например, описание первых пяти точек:

*N,            X             Y             Z
  
1,    212.10899,      313.405,    84.250198
2,     212.1097,    315.40701,    84.250198
3,     212.1087,    312.78201,    80.000198
4,     212.1096,     315.3562,    80.000198
5,     212.1102,    316.81711,    84.250198
...

2. Из загруженного облака трехмерных точек нужно создать математическую сетку связанных треугольных элементов.
Требуется построить «сетку» элементов – топологического множества точек (также можно использовать термины «узел» или «вершина»), связанных между собой ребрами – отрезками прямых линий таким образом, что исходная трехмерная область, описанная облаком точек, разбивалась на элементы треугольной формы.
3. Результат построения нужно сохранить в выходной текстовый файл в заданном формате.
Сначала должен идти список пронумерованных точек, после точек должен идти список пронумерованных треугольных элементов, которые описываются индексами точек, образующих треугольники.

*N,            X             Y             Z
*Nodes
1,    212.10899,      313.405,    84.250198
2,     212.1097,    315.40701,    84.250198
3,     212.1087,    312.78201,    80.000198
4,     212.1096,     315.3562,    80.000198
5,     212.1102,    316.81711,    84.250198
...
*Elements
1,            1,            3,            2
2,            2,            3,            4
3,            2,            4,            5
4,            6,            8,            7
5,            7,            8,            9
6,            7,            9,           10
...

4. Консольное приложение управляется набором параметров
4.1. Имя файл исходного облака точек задается параметром -i <INPUT_FILE> или  --input <INPUT_FILE>
4.2. Имя файл файла описания сетки -o <OUTPUT_FILE> или  --output <OUTPUT_FILE>
5. Файлы тестовых данных доступны по ссылкам

Облако точек 1
https://disk.yandex.ru/d/f5pkmz1MdV8UpA

Облако точек 2
https://disk.yandex.ru/d/R7dFZJqd5ZCFDA

Облако точек 3
https://disk.yandex.ru/d/wdDSch9fQ2gX1Q


    
