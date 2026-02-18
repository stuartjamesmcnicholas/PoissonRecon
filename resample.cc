#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>
#include <set>
#include <vector>

#include "vec3.hpp"

struct GridPoint {
    int i,j,k,id, point_idx;
};

bool operator<(const GridPoint& a, const GridPoint& b) {
    return a.id < b.id;
}

int main(int argc, char *argv[]){

    int grid_size = 100;

    std::ifstream file(argv[1]);

    float vx, vy, vz, nx, ny, nz;
    std::string str; 

    float max_x = -1e+9;
    float max_y = -1e+9;
    float max_z = -1e+9;
    float min_x =  1e+9;
    float min_y =  1e+9;
    float min_z =  1e+9;

    std::vector<std::pair<glm::vec3,glm::vec3>> points;
    while (std::getline(file, str)) {
        std::stringstream ss (str); 
        ss >> vx;
        ss >> vy;
        ss >> vz;
        ss >> nx;
        ss >> ny;
        ss >> nz;
        if(vx>max_x) max_x = vx;
        if(vy>max_y) max_y = vy;
        if(vz>max_z) max_z = vz;
        if(vx<min_x) min_x = vx;
        if(vy<min_y) min_y = vy;
        if(vz<min_z) min_z = vz;
        glm::vec3 v(vx,vy,vz);
        glm::vec3 n(nx,ny,nz);
        std::pair<glm::vec3,glm::vec3> p(v,n);
        points.push_back(p);
    }

    std::cout << min_x << " " << min_y << " " << min_z << std::endl;
    std::cout << max_x << " " << max_y << " " << max_z << std::endl;

    float x_width = (max_x - min_x) / grid_size;
    float y_width = (max_y - min_y) / grid_size;
    float z_width = (max_z - min_z) / grid_size;

    std::cout << x_width << " " << y_width << " " << z_width << std::endl;

    std::set<GridPoint> grid;

    int ip = 0;
    for(auto &p: points){
        int bin_x = floor((p.first[0] - min_x) / x_width);
        int bin_y = floor((p.first[1] - min_y) / y_width);
        int bin_z = floor((p.first[2] - min_z) / z_width);
        GridPoint gp;
        gp.i = bin_x;
        gp.j = bin_y;
        gp.k = bin_z;
        gp.point_idx = ip;
        gp.id = gp.i * grid_size * grid_size + gp.j * grid_size + gp.k;
        grid.insert(gp);
        ip++;
    }

    std::cout << grid.size() << std::endl;

    std::ofstream ofile(argv[2]);

    for(auto &gp: grid){
        const auto &p = points[gp.point_idx];
        ofile << p.first[0] << " " << p.first[1] << " " << p.first[2] <<  " ";
        ofile << p.second[0] << " " << p.second[1] << " " << p.second[2] << std::endl;
    }

    return 0;
    

}
