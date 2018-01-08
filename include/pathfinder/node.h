/**
    @file
    @author Jan Michalczyk 

    @brief Graph node
*/

#pragma once

namespace pathfinder
{
    class Node
    {
        public:
            Node(std::size_t index_row, std::size_t index_col,
                                        bool occupied = false): index_row_(index_row),
                                                                index_col_(index_col), 
                                                                occupied_(occupied)
            {
            }
      

            friend std::ostream& operator<<(const std::ostream& out, const Node& node)
            {
                std::cout << "Node(" << node.index_row_ << "," << node.index_col_
                  << "," << "occupied = " << node.occupied_ << ")" << std::endl;
            }

            
            friend bool operator==(const Node& first_node, const Node& second_node)
            {
                return((first_node.index_row_ == second_node.index_row_) &&
                       (first_node.index_col_ == second_node.index_col_));
            }

            
            bool isOccupied() const
            {
                return(occupied_);
            }

            
            std::vector<Node> getNeighbours(const Eigen::MatrixXd& map) const
            {
                std::vector<Node> neighbours;
                if((index_row_ == 0) && (index_col_ == 0))
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                }
                else if((index_row_ == 0) && (index_col_ == (map.cols() - 1)))
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }
                else if((index_row_ == (map.rows() - 1)) && (index_col_ == 0))
                {   
                    neighbours.emplace_back(index_row_ - 1, index_col_,
                                            map(index_row_ - 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                }
                else if((index_row_ == (map.rows() - 1)) && (index_col_ == (map.cols() - 1)))
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }
                else if(index_row_ == 0)
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }
                else if(index_row_ == (map.rows() - 1))
                {   
                    neighbours.emplace_back(index_row_ - 1, index_col_,
                                            map(index_row_ - 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }
                else if(index_col_ == (map.cols() - 1))
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_ - 1, index_col_,
                                            map(index_row_ - 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }
                else if(index_col_ == 0)
                {   
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_ - 1, index_col_,
                                            map(index_row_ - 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                }
                else
                {
                    neighbours.emplace_back(index_row_ + 1, index_col_,
                                            map(index_row_ + 1, index_col_));
                    neighbours.emplace_back(index_row_ - 1, index_col_,
                                            map(index_row_ - 1, index_col_));
                    neighbours.emplace_back(index_row_, index_col_ + 1,
                                            map(index_row_, index_col_ + 1));
                    neighbours.emplace_back(index_row_, index_col_ - 1,
                                            map(index_row_, index_col_ - 1));
                }

                return(neighbours);
            }

            
            std::size_t getRow() const
            {
                return(index_row_);
            }
            
            
            std::size_t getCol() const
            {
                return(index_col_);
            }


        private:
            std::size_t index_row_, index_col_;
            bool        occupied_;
    };
}//pathfinder
