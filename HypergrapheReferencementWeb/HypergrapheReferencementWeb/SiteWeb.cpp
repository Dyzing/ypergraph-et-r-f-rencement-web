#include "SiteWeb.h"

int SiteWeb::static_node_id = 0;


SiteWeb::SiteWeb()
	: siteweb(""), node_id(-1), pageRank(0.2f)
{
}

SiteWeb::SiteWeb(std::string const& sw, std::vector<int> const& viss)
	: siteweb(sw), vec_id_siteSortant(viss), node_id(static_node_id++), pageRank(0.25)
{
}

std::string SiteWeb::display_vec_id_ss() const
{
	std::string res = "{";

	if (vec_id_siteSortant.size() > 0)
	{
		for (int i = 0; i < vec_id_siteSortant.size() - 1; i++)
		{
			res += std::to_string(vec_id_siteSortant[i]);
			if(i < vec_id_siteSortant.size() - 1)
				res += ", ";
		}
		res += std::to_string(vec_id_siteSortant[vec_id_siteSortant.size() - 1]);
	}

	res += "}";

	return res;
}

void SiteWeb::toString() const
{
	std::cout << "Nom du site " + std::to_string(node_id) + " avec le PageRank = " + std::to_string(pageRank) +
		" redirigeant vers les site " + display_vec_id_ss() + " : " + siteweb  << std::endl;
}
