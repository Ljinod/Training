// ============================================================================
//
//       Filename:  acm_icpc.cpp
//        Created:  20/09/2014
//         Author:  Ljinod
//
//    Description:  You are given a list of N people who are attending ACM-ICPC
//      World Finals. Each of them are either well versed in a topic or they
//      are not. Find out the maximum number of topics a 2-person team can know
//      and also find out how many teams can know that maxium number of topics. 
//
//      Input format:
//      The first line has two integers M and N separated by a single space,
//      where N represents the number of people and M represents the number of
//      topics. N lines follow.
//      Each line contains a binary string of length M. In this string, 1
//      indicates that the ith person knows a particular topic, and 0 indicates
//      that the ith person does not know the topic.
//
//      Output format:
//      On the first line, print the maximum number of topics a 2-person team
//      can know.
//      On the second line, print the number of 2-person teams that can know
//      the maximum number of topics.
//
// ============================================================================


#define MAX_TOPICS 500


#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <bitset>


int getNumberOfTopics(const std::bitset<MAX_TOPICS>&);


int main()
{ 
    std::string tmp;
    int line_index = 0;
    int nb_people = 0;
    int nb_topics = 0;
    std::vector<std::bitset<MAX_TOPICS> > people_knowledge;

    do 
    {
        // first line: need to get M and N
        if(!line_index)
        {
            std::getline(std::cin, tmp);

            // find the first space in the string
            std::size_t pos_space = tmp.find(" ");
            if(pos_space == std::string::npos)
            {
                std::cerr << "ERROR: could not find an empty space" 
                          << std::endl;
                return 1;
            }
                
            nb_people = atoi((tmp.substr(0, pos_space)).c_str());
            nb_topics = atoi((tmp.substr(pos_space+1)).c_str());
        }
        // lines representing people's knowledge
        else
        {
            // initialize the bitset directly with the value of the line
            std::bitset<MAX_TOPICS> current_people_knowledge(tmp, 0, nb_topics);
            people_knowledge.push_back(current_people_knowledge);
        }

        line_index++;

    } while(line_index <= nb_people && std::getline(std::cin, tmp));


    int nb_teams_at_max_knowledge = 0;
    int max_knowledge             = 0;
    int current_knowledge_value   = 0;
    std::bitset<MAX_TOPICS> current_knowledge;
    
    for(int i=0; i<nb_people; i++)
    {
        for(int j=i+1; j<nb_people; j++)
        {
            current_knowledge = people_knowledge[i] | people_knowledge[j];
            current_knowledge_value = getNumberOfTopics(current_knowledge);
            if (max_knowledge < current_knowledge_value)
            {
                max_knowledge = current_knowledge_value;
                nb_teams_at_max_knowledge = 1;
            }
            else if(max_knowledge == current_knowledge_value)
                nb_teams_at_max_knowledge++;
        }
    }

    std::cout << max_knowledge << std::endl;
    std::cout << nb_teams_at_max_knowledge << std::endl;
}


int getNumberOfTopics(const std::bitset<MAX_TOPICS>& person_knowledge)
{
    int res = 0;
    for(unsigned int i=0; i<person_knowledge.size(); i++)
    {
        if(person_knowledge.test(i))
            res++;
    }
    return res;
}
