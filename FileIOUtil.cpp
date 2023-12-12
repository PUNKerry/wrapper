#include "FileIOUtil.h"

static double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}

std::vector<Point_3> FileIOUtil::LoadDataFF(std::string path)
{
    std::vector<Point_3> points;
    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '*') {
                continue;
            }

            std::istringstream ss(line);
            std::string token;
            
            std::getline(ss, token, ',');
            int number = std::stoi(token);

            std::getline(ss, token, ',');
            double x = stringToDouble(token);

            std::getline(ss, token, ',');
            double y = stringToDouble(token);

            std::getline(ss, token, ',');
            double z = stringToDouble(token);

         
            points.push_back(Point_3(x, y, z));
        }
        file.close();
    }
    else {
        
        
        
        std::cerr << "Unable to open file: " << path << std::endl;

    }

   

    return points;
}

void FileIOUtil::SaveDataIF(std::string path, Delaunay triangulation)
{
    
    std::ofstream outputFile(path);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << path << " for writing." << std::endl;
        return;
    }

    std::ostringstream dataStream;

    int i = 0;

    dataStream << "Elements:" << std::endl;

    for (auto it = triangulation.finite_cells_begin(); it != triangulation.finite_cells_end(); ++it) {
        i++;
       
        dataStream << i << ", " << it->vertex(0)->point() << ", " << it->vertex(1)->point() << ", " << it->vertex(2)->point() << std::endl;
    }

    outputFile << dataStream.str() << std::endl;

    outputFile.close();
    std::cout << "Data saved to " << path << " successfully." << std::endl;
}
