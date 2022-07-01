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

void SiteWeb::toString() const
{
	std::cout << "Nom du site " + std::to_string(node_id) + " avec le PageRank = " + std::to_string(pageRank) + " : " + siteweb << std::endl;
}
