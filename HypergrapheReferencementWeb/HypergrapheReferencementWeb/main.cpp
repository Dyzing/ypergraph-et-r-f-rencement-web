// HypergrapheReferencementWeb.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Hypergraphe.h"
#include "BlocSite.h"
#include "SiteWeb.h"
#include <vector>
#include <string>

int main()
{
    Hypergraphe hyper;

    

#pragma region RegionSiteWeb
    std::vector<SiteWeb> vec_site1;

    SiteWeb siteA("http://www.bose.res.in/~library/FILES/ditya.htm", {4, 8}); //0
    SiteWeb siteB("http://www.bose.res.in/~library/FILES/arun.htm", {}); //1
    SiteWeb siteC("http://www.bose.res.in/~library/FILES/jaydeep.htm", {}); //2
    SiteWeb siteD("http://www.bose.res.in/~library/FILES/librarian.htm", {}); //3

    vec_site1.push_back(siteA);
    vec_site1.push_back(siteB);
    vec_site1.push_back(siteC);
    vec_site1.push_back(siteD);

    std::vector<SiteWeb> vec_site2;

    SiteWeb siteE("http://indianarmy.nic.in/arkargil/arguj.htm", {}); //4
    SiteWeb siteF("http://indianarmy.nic.in/arkargil/arj&k.htm", {3}); //5
    SiteWeb siteG("http://indianarmy.nic.in/arkargil/armizo.htm", {3}); //6
    SiteWeb siteH("http://indianarmy.nic.in/arkargil/arorrisa.htm", {4}); //7

    vec_site2.push_back(siteE);
    vec_site2.push_back(siteF);
    vec_site2.push_back(siteG);
    vec_site2.push_back(siteH);

    std::vector<SiteWeb> vec_site3;

    SiteWeb siteI("http://glide.net.in/connectivity.htm", {4, 3}); //8
    SiteWeb siteJ("http://glide.net.in/consultancy.htm", {6, 7}); //9

    vec_site3.push_back(siteI);
    vec_site3.push_back(siteJ);
#pragma endregion

    hyper.vec_all_site.push_back(vec_site1);
    hyper.vec_all_site.push_back(vec_site2);
    hyper.vec_all_site.push_back(vec_site3);

    hyper.Fill_vec_bs();

    hyper.Fill_vec_nb_arc_bloc();

    hyper.UpdatePageRank();

    // --------------------------------------------------------------------------------------------

    hyper.toString();

    std::cout << "\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
