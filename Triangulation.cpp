#include "Triangulation.h"

Delaunay Triangulation::Triangulate(std::vector<Point_3> points)
{
	Delaunay triangulation(points.begin(), points.end());
	return triangulation;
}
