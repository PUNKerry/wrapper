
#pragma once
#include <iostream>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K> Delaunay;
typedef K::Point_3 Point_3;

class FileIOUtil
{
public:
	static std::vector<Point_3> LoadDataFF(std::string path);
	static void SaveDataIF(std::string path, Delaunay triangulation);
};

