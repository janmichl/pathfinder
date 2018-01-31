/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Breadth-first search
*/

#pragma once

namespace bfs
{
    class Bfs
    {
        public:
            bool computePathIfExists(const pathfinder::Map&  map, 
                                     const pathfinder::Node& start_node,
                                     const pathfinder::Node& goal_node)
            {
                if(map(start_node.getRow(), start_node.getCol()))
                {
                    return(false);
                }
                
                reset();

                std::unordered_map<std::string, pathfinder::Node> came_from;
                std::queue<pathfinder::Node>                      queue;
                
                // explore
                queue.push(start_node);
                while(!queue.empty())
                {
                    pathfinder::Node current_node = queue.front();
                    queue.pop();
                    
                    if(current_node == goal_node)
                    {
                        // get path to goal
                        pathfinder::Node parent_node = came_from.at(current_node.getName());
                        path_.push_back(current_node);                             
                        while(parent_node != start_node)
                        {
                            path_.push_back(parent_node);                             
                            parent_node = came_from.at(parent_node.getName());
                        }
                        path_.push_back(parent_node);                             
                        
                        std::reverse(path_.begin(), path_.end());
                        return(true);
                    }

                    std::vector<pathfinder::Node> neighbours = map.getNeighbours(current_node);
                    for(std::size_t i = 0; i < neighbours.size(); ++i)
                    {
                        if(!map(neighbours[i].getRow(), neighbours[i].getCol()) 
                            && !came_from.count(neighbours[i].getName()))
                        {
                            came_from.insert(std::make_pair(neighbours[i].getName(), current_node));
                            queue.push(neighbours[i]);
                        }
                    }
                }

                return(false);
            }


            const std::vector<pathfinder::Node>& getPath() const
            {
                PATHFINDER_ASSERT(path_.size() != 0, "Path is empty.");
                return(path_);
            }


        private:
            void reset()
            {
                path_.clear();
            }


        private:
            std::vector<pathfinder::Node> path_;
    };
}//bfs
