/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Graph node
*/

#pragma once

namespace pathfinder
{
    class Node
    {
        public:
            Node(std::size_t index_row, std::size_t index_col) : index_row_(index_row),
                                                                 index_col_(index_col)
            {
                std::ostringstream oss;
                oss << "Node(" << index_row_ << "," << index_col_ << ")";
                name_ = oss.str();
            }
      

            friend std::ostream& operator<<(const std::ostream& out, const Node& node)
            {
                std::cout << node.name_ << std::endl;
            }

            
            friend bool operator==(const Node& first_node, const Node& second_node)
            {
                return((first_node.index_row_ == second_node.index_row_) &&
                       (first_node.index_col_ == second_node.index_col_));
            }
            
            
            friend bool operator!=(const Node& first_node, const Node& second_node)
            {
                return((first_node.index_row_ != second_node.index_row_) ||
                       (first_node.index_col_ != second_node.index_col_));
            }

            
            std::size_t getRow() const
            {
                return(index_row_);
            }
            
            
            std::size_t getCol() const
            {
                return(index_col_);
            }

            
            const std::string& getName() const
            {
                return(name_);
            }


        private:
            std::size_t index_row_, index_col_;
            std::string name_;
    };
}//pathfinder
