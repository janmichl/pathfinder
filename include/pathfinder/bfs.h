/**
    @file
    @author Jan Michalczyk 

    @brief Breadth-first search
*/

#pragma once

namespace pathfinder
{
    class Bfs
    {
        public:
            Bfs(const Eigen::MatrixXd& map) : map_(map)
            {
            }


            bool pathExists(const Node& start_node,
                            const Node& goal_node)
            {
                std::queue<Node> queue;
                queue.push(start_node);
                
                // explore
                while(!queue.empty())
                {
                    Node current_node = queue.front();
                    queue.pop();
                    
                    if(current_node == goal_node)
                    {
                        std::cout << "goal reached" << std::endl;
                        return(true);
                    }

                    std::vector<Node> neighbours = current_node.getNeighbours(map_);
                    for(std::size_t i = 0; i < neighbours.size(); ++i)
                    {
                        if(!map_(neighbours[i].getRow(), neighbours[i].getCol())
                            && !neighbours[i].isOccupied())
                        {
                            map_(neighbours[i].getRow(), neighbours[i].getCol()) = true;
                            queue.push(neighbours[i]);
                        }
                    }
                }

                return(false);
            }


        private:
            Eigen::MatrixXd map_;
    };
}//pathfinder
