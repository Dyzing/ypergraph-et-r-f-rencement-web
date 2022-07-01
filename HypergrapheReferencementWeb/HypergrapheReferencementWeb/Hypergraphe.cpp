#include "Hypergraphe.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <string>

Hypergraphe::Hypergraphe()
{
}

void Hypergraphe::Fill_vec_bs(std::string const& emplacement)
{

	std::ifstream fichier("in-2004.nodes.txt", std::ios::in);  // on ouvre le fichier en lecture

    if (fichier)  // si l'ouverture a réussi
    {
        // instructions
        BlocSite temp_bs;

        temp_bs.domaine = "";


        for (std::string line; std::getline(fichier, line); ) 
        {
            std::string strings[5];
            split(line, ' ', strings);

            std::string url_strings[10];
            if (strings[2][0] == 'h' && strings[2][1] == 't' && strings[2][2] == 't' && strings[2][3] == 'p')
            {
                split(strings[2], '.', url_strings);
                SiteWeb temp_sw;


                if (temp_bs.domaine == "")
                {
                    temp_bs.domaine = url_strings[1] + "." + url_strings[2];
                    temp_bs.node_id_bs = std::stoi(strings[0]);
                }
                temp_sw.siteweb = temp_bs.domaine;


            }
        }


        fichier.close();  // on ferme le fichier
    }
    else  // sinon
       std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void Hypergraphe::Fill_vec_bs()
{
    for (std::vector<SiteWeb>& vec_site : vec_all_site)
    {
        std::string url_strings[10];
        BlocSite temp_bs;
        bool goodDomaine = true;

        split(vec_site[0].siteweb, '.', url_strings);
        temp_bs.domaine = url_strings[0] + "." + url_strings[1];
        
        temp_bs.vec_sw = vec_site;

        for (SiteWeb sw : vec_site)
        {
            if (sw.vec_id_siteSortant.size() != 0)
            {
                temp_bs.vec_id_sw_sortant.insert(temp_bs.vec_id_sw_sortant.end(), sw.vec_id_siteSortant.begin(), sw.vec_id_siteSortant.end());
            }
        }

        std::sort(temp_bs.vec_id_sw_sortant.begin(), temp_bs.vec_id_sw_sortant.end());
        auto last = std::unique(temp_bs.vec_id_sw_sortant.begin(), temp_bs.vec_id_sw_sortant.end());
        temp_bs.vec_id_sw_sortant.erase(last, temp_bs.vec_id_sw_sortant.end());

        vec_bs.push_back(temp_bs);
    }
}

int len(std::string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;

    }
    return length;
}

void Hypergraphe::split(std::string str, char seperator, std::string res_strings[])
{
    res_strings->clear();
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            res_strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

void Hypergraphe::UpdatePageRank()
{
    for (int i = 0; i < vec_all_site.size(); i++)
    {
        for (SiteWeb &sw : vec_all_site[i])
        {
            for (BlocSite bs : vec_bs) // a regarder
            {
                if (std::find(bs.vec_id_sw_sortant.begin(), bs.vec_id_sw_sortant.end(), sw.node_id) != bs.vec_id_sw_sortant.end()) 
                {
                    float sum = 0.25 / (float)bs.nb_arc_bloc;
                    sw.pageRank += sum;
                }
            }
            for (BlocSite& temp_bs : vec_bs)
            {
                for (SiteWeb& temp_sw : temp_bs.vec_sw)
                {
                    if (temp_sw.node_id == sw.node_id)
                    {
                        temp_sw.pageRank = sw.pageRank;
                    }
                }
            }
        }
    }
}

void Hypergraphe::Fill_vec_nb_arc_bloc()
{
    init_vec_nab();

    for (int i = 0; i < vec_bs.size(); i++) // parcours les BlocSite pour les remplir
    {
        for (int j = 0; j < vec_bs.size(); j++) // parcours les autres BlocSite pour regarder si l'idNode est contenu en eux
        {
            if (j != i)
            {
                for (int temp_id_node_sortant : vec_bs[i].vec_id_sw_sortant)
                {
                    for (SiteWeb sw : vec_bs[j].vec_sw)
                    {
                        if (temp_id_node_sortant == sw.node_id)
                        {
                            if (vec_bs[i].vec_nb_arc_bloc[j] != 1)
                            {
                                ++vec_bs[i].vec_nb_arc_bloc[j];
                            }
                        }
                    }
                }
            }
        }
        vec_bs[i].nb_arc_bloc = std::accumulate(vec_bs[i].vec_nb_arc_bloc.begin(), vec_bs[i].vec_nb_arc_bloc.end(), 0);
    }
}

void Hypergraphe::init_vec_nab()
{
    for (BlocSite &temp_bs : vec_bs)
    {
        for (int k = 0; k < vec_bs.size(); k++)
        {
            temp_bs.vec_nb_arc_bloc.push_back(0);
        }
    }
}

void Hypergraphe::sort_vec_bs_sw()
{
    for (BlocSite& bs : vec_bs)
    {
        std::sort(bs.vec_sw.begin(), bs.vec_sw.end(), [](SiteWeb a, SiteWeb b) {
            return a.pageRank > b.pageRank;
            });
    }
}

void Hypergraphe::toString() const
{
    for (BlocSite bs : vec_bs)
    {
        std::cout << "\n Domaine du bloc " + std::to_string(bs.node_id_bs) + " : " + bs.domaine << std::endl;
        std::cout << "Sites web du bloc : \n" << std::endl;
        for (SiteWeb sw : bs.vec_sw)
        {
            sw.toString();
        }
        std::cout << "\n" << std::endl;
    }

    std::cout << "\n" << std::endl;
}
