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
                if(start_node.isOccupied() || goal_node.isOccupied())
                {
                    return(false);
                }
                
                reset();

                std::queue<Node> queue;
                queue.push(start_node);
                
                // explore
                while(!queue.empty())
                {
                    Node current_node = queue.front();
                    queue.pop();
                    
                    if(current_node == goal_node)
                    {
                        // record path
                        Node parent_node = came_from_.at(current_node.getName());
                        path_.push_back(current_node);                             
                        while(parent_node != start_node)
                        {
                            path_.push_back(parent_node);                             
                            parent_node = came_from_.at(parent_node.getName());
                        }
                        path_.push_back(parent_node);                             

                        std::cout << "goal reached" << std::endl;
                        return(true);
                    }

                    std::vector<Node> neighbours = current_node.getNeighbours(map_);
                    for(std::size_t i = 0; i < neighbours.size(); ++i)
                    {
                        if(!map_(neighbours[i].getRow(), neighbours[i].getCol()) 
                            && !came_from_.count(neighbours[i].getName()))
                        {
                            came_from_.insert(std::make_pair(neighbours[i].getName(), current_node));
                            queue.push(neighbours[i]);
                        }
                    }
                }

                return(false);
            }


            const std::vector<Node>& getPath() const
            {
                PATHFINDER_ASSERT(path_.size() != 0, "Path empty.");
                return(path_);
            }


        private:
            void reset()
            {
                path_.clear();
                came_from_.clear();
            }


        private:
            Eigen::MatrixXd             map_;
            std::map<std::string, Node> came_from_;
            std::vector<Node>           path_;
    };
}//pathfinder
