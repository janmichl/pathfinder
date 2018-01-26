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
                PATHFINDER_ASSERT(isInside(row, col), "Wrong indices.");
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
                std::vector<std::tuple<int, int>> directions;
                directions.emplace_back( 0, -1);
                directions.emplace_back( 1,  0);
                directions.emplace_back( 0,  1);
                directions.emplace_back(-1,  0);

                std::vector<Node> neighbours;
                for(std::size_t i = 0; i < directions.size(); ++i)
                {
                    int direction_x, direction_y;
                    std::tie(direction_x, direction_y) = directions[i];

                    int row = node.getRow() + direction_x;
                    int col = node.getCol() + direction_y;
                    if(isInside(row, col))
                    {
                        neighbours.emplace_back(row, col);
                    }
                }

                return(neighbours);
            }


        private:
            bool isInside(const Node& node) const
            {
                return(isInside(node.getRow(), node.getCol()));
            }
            
            
            bool isInside(int row, int col) const
            {
                bool is_inside = (((row >= 0) && (row < map_.rows())) &&
                                  ((col >= 0) && (col < map_.cols())));
                return(is_inside);
            }


        private:
            Eigen::MatrixXd map_;
    };
}//pathfinder
