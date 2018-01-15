/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Compute path from one node to another using BFS
*/

// core classes
#include "pathfinder/core.h"

// specific classes
#include "pathfinder/bfs.h"

// main
int main(int argc, char** argv)
{
    try
    {
        yaml_config::ConfigReader config_reader(std::string(PATHFINDER_CONFIG_PATH) + "maps.yaml");

        Eigen::MatrixXd map;
        config_reader.readMatrix("maps", "map2", map);

        std::cout << map << std::endl;
        
        bfs::Bfs bfs(map);
        bool path_exists = bfs.computePathIfExists(pathfinder::Node(0, 0), pathfinder::Node(9, 9));
        std::cout << "path exists " << std::boolalpha << path_exists << std::endl;
        
        std::vector<pathfinder::Node> path;
        if(path_exists)
        {
            path = bfs.getPath();
            utilities::printVector<pathfinder::Node>(std::cout, path); 
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << std::endl;
        std::exit(-1);
    }
    
    return(0);
}
