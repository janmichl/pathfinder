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
      

            double operator()(std::size_t row, std::size_t col) const
            {
                PATHFINDER_ASSERT((row < map_.rows()) && (col < map_.cols()),
                                                            "Wrong indices.");
                return(map_(row, col));
            }
            

            friend std::ostream& operator<<(std::ostream& out, const Map& map)
            {
                out << map.map_; 
                return(out);
            }

            
            double getCostFH(const Node& from, 
                             const Node& current,
                             const Node& to) const
            {
                return(getDistance(from, current) + getDistance(current, to));
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
            double getDistance(const Node& from, const Node& to) const
            {
               return(std::abs(static_cast<double>(from.getRow()) -
                                    static_cast<double>(to.getRow())) +
                      std::abs(static_cast<double>(from.getCol()) -
                                    static_cast<double>(to.getCol()))); 
            }


        private:
            Eigen::MatrixXd map_;
    };
}//pathfinder
