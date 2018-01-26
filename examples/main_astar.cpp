/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Compute path from one node to another using A*
*/

// core classes
#include "pathfinder/core.h"

// specific classes
#include "pathfinder/astar.h"

// main
int main(int argc, char** argv)
{
    try
    {
        yaml_config::ConfigReader config_reader(std::string(PATHFINDER_CONFIG_PATH) + "maps.yaml");

        Eigen::MatrixXd map;
        config_reader.readMatrix("maps", "map4", map);

        pathfinder::Map binary_map(map);
        std::cout << binary_map << std::endl;
        
        astar::Astar astar;
        bool path_exists = astar.computePathIfExists(binary_map,
                                  pathfinder::Node(0, 0), pathfinder::Node(9, 9));
        std::cout << "path exists " << std::boolalpha << path_exists << std::endl;
        
        std::vector<pathfinder::Node> path;
        if(path_exists)
        {
            path = astar.getPath();
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
