/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief A*
*/

#pragma once

namespace astar
{
    class Astar
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

                std::priority_queue<pathfinder::Node, 
                               std::vector<pathfinder::Node>, 
                               std::greater<pathfinder::Node>> queue;
                
                cost_so_far_.insert(std::make_pair(start_node.getName(), 0.0));
                
                // explore
                queue.push(start_node);
                while(!queue.empty())
                {
                    pathfinder::Node current_node = queue.top();
                    queue.pop();
                    
                    if(current_node == goal_node)
                    {
                        // get path to goal
                        pathfinder::Node parent_node = came_from_.at(current_node.getName());
                        path_.push_back(current_node);                             
                        while(parent_node != start_node)
                        {
                            path_.push_back(parent_node);                             
                            parent_node = came_from_.at(parent_node.getName());
                        }
                        path_.push_back(parent_node);                             
                        
                        std::reverse(path_.begin(), path_.end());
                        return(true);
                    }

                    std::vector<pathfinder::Node> neighbours = map.getNeighbours(current_node);
                    computeCosts(neighbours, start_node, current_node, goal_node, map);
                    for(std::size_t i = 0; i < neighbours.size(); ++i)
                    {
                        if(!map(neighbours[i].getRow(), neighbours[i].getCol()) 
                            && (!cost_so_far_.count(neighbours[i].getName()) || 
                                (neighbours[i].getCost() < cost_so_far_.at(neighbours[i].getName()))))
                        {
                            cost_so_far_.insert(std::make_pair(neighbours[i].getName(), 
                                                               neighbours[i].getCost()));
                            came_from_.insert(std::make_pair(neighbours[i].getName(), current_node));
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
            void computeCosts(std::vector<pathfinder::Node>& nodes,
                              const pathfinder::Node& start_node,
                              const pathfinder::Node& current_node,
                              const pathfinder::Node& goal_node,
                              const pathfinder::Map&  map)
            {
                for(std::size_t i = 0; i < nodes.size(); ++i)
                {
                    double new_cost = cost_so_far_.at(current_node.getName()) +
                                             map.getCostFH(start_node, nodes[i], goal_node);
                    nodes[i].setCost(new_cost); 
                }
            }
            
            
            void reset()
            {
                path_.clear();
                came_from_.clear();
                cost_so_far_.clear();
            }


        private:
            std::vector<pathfinder::Node>           path_;
            std::map<std::string, pathfinder::Node> came_from_;
            std::map<std::string, double>           cost_so_far_;
    };
}//astar
