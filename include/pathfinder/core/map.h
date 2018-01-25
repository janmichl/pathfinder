/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Map
*/

#pragma once

namespace pathfinder
{
    class Map
    {
        public:
            Map(const Eigen::MatrixXd& map) : map_(map)
            {
            }
      

            double operator()(int row, int col) const
            {
                PATHFINDER_ASSERT((row >= 0) && (col >= 0),
                                        "Negative indices.");
                PATHFINDER_ASSERT((row < map_.rows()) && (col < map_.cols()),
                                                             "Wrong indices.");
                return(map_(row, col));
            }
            

            friend std::ostream& operator<<(std::ostream& out, const Map& map)
            {
                out << map.map_; 
                return(out);
            }

            
            double getCostManhattan(const Node& from, 
                                    const Node& to) const
            {
               return(std::abs(to.getRow() - from.getRow()) +
                      std::abs(to.getCol() - from.getCol())); 
            }
            

            std::vector<Node> getNeighbours(const Node& node) const
            {
                std::vector<Node> neighbours;
                if((node.getRow() == 0) && (node.getCol() == 0))
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                }
                else if((node.getRow() == 0) && (node.getCol() == (map_.cols() - 1)))
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }
                else if((node.getRow() == (map_.rows() - 1)) && (node.getCol() == 0))
                {   
                    neighbours.emplace_back(node.getRow() - 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                }
                else if((node.getRow() == (map_.rows() - 1)) && (node.getCol() == (map_.cols() - 1)))
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }
                else if(node.getRow() == 0)
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }
                else if(node.getRow() == (map_.rows() - 1))
                {   
                    neighbours.emplace_back(node.getRow() - 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }
                else if(node.getCol() == (map_.cols() - 1))
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow() - 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }
                else if(node.getCol() == 0)
                {   
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow() - 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                }
                else
                {
                    neighbours.emplace_back(node.getRow() + 1, node.getCol());
                    neighbours.emplace_back(node.getRow() - 1, node.getCol());
                    neighbours.emplace_back(node.getRow(), node.getCol() + 1);
                    neighbours.emplace_back(node.getRow(), node.getCol() - 1);
                }

                return(neighbours);
            }


        private:
            Eigen::MatrixXd map_;
    };
}//pathfinder
