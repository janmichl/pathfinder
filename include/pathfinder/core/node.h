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
            Node(int index_row, int index_col) : index_row_(index_row),
                                                 index_col_(index_col)
            {
                PATHFINDER_ASSERT((index_row_ >= 0) && (index_col_ >= 0),
                                                      "Negative indices.");

                setCost(0.0);
                setPriority(0.0);
                
                std::ostringstream oss;
                oss << "Node(" << index_row_ << "," << index_col_ << ")";
                name_ = oss.str();
            }
      

            bool operator>(const Node& rhs) const
            {
                return(priority_ > rhs.getPriority());
            }

            
            void setCost(double cost)
            {
                cost_ = cost;
            }

            
            double getCost() const
            {
                return(cost_);
            }
            
            
            void setPriority(double priority)
            {
                priority_ = priority;
            }

            
            double getPriority() const
            {
                return(priority_);
            }


            friend std::ostream& operator<<(std::ostream& out, const Node& node)
            {
                out << node.name_ << std::endl;
                return(out);
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

            
            int getRow() const
            {
                return(index_row_);
            }
            
            
            int getCol() const
            {
                return(index_col_);
            }

            
            const std::string& getName() const
            {
                return(name_);
            }


        private:
            int         index_row_, index_col_;
            double      cost_, priority_;
            std::string name_;
    };
}//pathfinder
