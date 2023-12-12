#include <iostream>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <cxxopts.hpp>
#include "FileIOUtil.h"
#include "Triangulation.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K> Delaunay;
typedef K::Point_3 Point_3;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "russian");

    std::string inputFileName;
    std::string outputFileName;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-i" || arg == "--input") {
            if (i + 1 < argc) {
                inputFileName = argv[i + 1];
                i++; 
            }
            else {
                std::cerr << "Ошибка: Отсутствует аргумент после " << arg << std::endl;
                return 1; 
            }
        }
        else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                outputFileName = argv[i + 1];
                i++; 
            }
            else {
                std::cerr << "Ошибка: Отсутствует аргумент после " << arg << std::endl;
                return 1; 
            }
        }
    }

    if (inputFileName.empty() || outputFileName.empty()) {
        std::cerr << "Ошибка: Необходимо указать имена файлов для ввода и вывода." << std::endl;
        return 1; 
    }


    std::vector<Point_3> points = FileIOUtil::LoadDataFF(inputFileName);

    Delaunay result = Triangulation::Triangulate(points);


    FileIOUtil::SaveDataIF(outputFileName, result);


    std::cout << "Имя файла исходного облака точек: " << inputFileName << std::endl;
    std::cout << "Имя файла описания сетки: " << outputFileName << std::endl;

    return 0; 

}

/*

    Для реализации процесса триангуляции используется библиотека CGAL. CGAL предоставляет обширный набор алгоритмов для решения задач, 
    связанных с вычислительной геометрией, такими как построение выпуклых оболочек, триангуляция, пересечение объектов.

    В данном случае для построения сетки используется алгоритм Делоне в пространстве - это алгоритм вычислительной геометрии, 
    который строит триангуляцию Делоне для заданного множества точек (облака точек) в пространстве. 

    Для сохранения и чтения из файлов был реализован static util "FileIOUtil"

*/