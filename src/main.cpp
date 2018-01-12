/**
    @file
    @author Jan Michalczyk 

    @brief
*/

#include "pathfinder.h"

// main
int main(int argc, char** argv)
{
    try
    {
        yaml_config::ConfigReader config_reader(std::string(PATHFINDER_CONFIG_PATH) + "maps.yaml");

        Eigen::MatrixXd map;
        config_reader.readMatrix("maps", "map2", map);

        std::cout << map << std::endl;
        
        pathfinder::Bfs bfs(map);
        bool path_exists = bfs.pathExists(pathfinder::Node(0, 0), pathfinder::Node(9, 9));
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
