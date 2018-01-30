/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Auxiliary functions and classes
*/

#pragma once

namespace utilities
{
    template<typename t>
      inline void printVector(std::ostream& output_stream, const std::vector<t>& vector)
    {
        for(std::size_t i = 0; i < vector.size() - 1; ++i)
        {
            output_stream << vector[i] << " ";
        }
        output_stream << vector[vector.size() - 1] << std::endl;
    }


    template<typename t, typename n>
      inline void printMap(const std::map<t, n>& map)
    {
        for(const auto& i : map) 
        {
            std::cout << i.first << " : " << i.second << std::endl;
        }
    }

    
    template<>
      inline void printVector<pathfinder::Node>(std::ostream& output_stream,
                                   const std::vector<pathfinder::Node>& vector)
    {
        for(std::size_t i = 0; i < vector.size() - 1; ++i)
        {
            output_stream << vector[i];
        }
        output_stream << vector[vector.size() - 1];
    }
    

    template<typename t>
      inline void printVector(std::ostream& output_stream, const std::vector<std::vector<t>>& vector)
    {
        for(std::size_t i = 0; i < vector.size(); ++i)
        {
            for(std::size_t j = 0; j < vector[i].size() - 1; ++j)
            {
                output_stream << vector[i][j] << " ";
            }
            output_stream << vector[i][vector[i].size() - 1] << std::endl;
        }
    }

    
    class Timer
    {
        public:
            void start()
            {
                start_ = std::chrono::system_clock::now();
            }


            void stop()
            {
                stop_ = std::chrono::system_clock::now();
            }


            std::chrono::milliseconds::rep getTimeDiffMillisec() const
            {
                return(std::chrono::duration_cast<std::chrono::milliseconds>(stop_ - start_).count()); 
            }


        private:
            std::chrono::system_clock::time_point start_;
            std::chrono::system_clock::time_point stop_;
    };
}//utilities
