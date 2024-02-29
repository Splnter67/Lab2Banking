#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <windows.h>

#include "cvm 23.h"

using namespace std;


const size_t CLIENTS_MAX = 70;						// nombre maximal de clients
const size_t COMPTES_MAX = 3;						// nombre de comptes par client

const double MARGE_CREDIT_MAX = 10000;				// marge de cr�dit maximun d'un compte du client
const double SOLDE_COMPTE_MAX = 1000000;			// maximun � ne pas d�passer dans un compte d'un client


enum class Commandes { ajouter, quitter, inconnue, afficher, deposer, retrait, virement, list, supprimer };// � COMPL�TER AVEC LES AUTRES COMMANDES ...
using Cmd = Commandes;

struct Nom											// nom d'un client
{
	string prenom;
	string nom;
};

struct Adresse										// adresse d'un client
{
	string noCivique;
	string rue;
	string ville;
	string codePostal;
};

struct Personne										// informations personnelles d'un client
{
	Nom		nom;
	Adresse	adresse;
	string	telephone;
	string	nas;
};

struct Compte										// un compte d'un client
{
	double solde;
	double margeCredit;
};

struct Client										// informations relatives � un client
{
	Personne	info;
	Compte		comptes[COMPTES_MAX];
	time_t		date;								// date d'ajout du client
};

struct Banque										// La banque de clients
{
	size_t cpt = 0;									// cpt: compteur de client [0..CLIENTS_MAX]
	Client clients[CLIENTS_MAX];
};


/* ----------------------------------- */
/* LES VARIABLES GLOBALES DU PROGRAMME */
/* ----------------------------------- */

// ATTENTION: les variables globales ne sont pas permises dans ce TP


/* ------------------------------------------ */
/* LES D�CLARATIONS (PROTOTYPES) DE FONCTIONS */
/* ------------------------------------------ */

void io_bip();
void io_clean();
double io_round(double v, size_t p = 2);			// par defaut la pr�cision est � deux d�cimales (p = 2)

/*
	Suggestion de fonctions:

		size_t lireNoClientValide(size_t maxno);
		size_t lireNoCompteValide();
		double lireMontantValide(double maxmontant);
		void afficherComptesClient(Client& client);
*/

// �crire ici toutes vos d�clarations de fonctions ...
// ...



/* ------------------------------------- */
/* FONCTIONS TR�S G�N�RALES DU PROGRAMME */
/* ------------------------------------- */

void io_bip() { Beep(200, 300); }

void io_clean()										// pour vider les 2 tampons d'input
{
	cin.clear();									// s'assure que le cin est remis en marche
	cin.ignore(cin.rdbuf()->in_avail());			// vide le tampon du cin
	while (_kbhit()) (void)_getch();				// vide le tampon de la console
}

double io_round(double v, size_t p)					// tous les montants lus devront �tre arrondis � 2 d�cimales avec cette fonction (v:valeur et p:pr�cision)
{													// ex: montant = io_round(montant,2);
	double e = pow(10, p);
	return round(v * e) / e;
}


/* ----------------------------------------------------------------------- */
/* FONCTIONS G�N�RALES POUR L'INTERFACE USAGER (UI) EN LECTURE OU �CRITURE */
/* ----------------------------------------------------------------------- */

void afficherMenu()
{
	system("CLS");
	cout << left << setw(16) << "" << setw(45) << "BANQUE CVM - Succ C21" << "\n\n\n\n";
	cout << left << setw(16) << "" << setw(45) << "1. Ajouter un client" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "2. Afficher les informations d'un client" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "3. D�p�t" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "4. Retrait" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "5. Virement" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "6. Lister les clients et leurs cr�dit actuel" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "7. Supprimer un client" << "\n\n";
	cout << left << setw(16) << "" << setw(45) << "Q. Quitter" << "\n\n\n\n\n\n";
	cout << left << setw(16) << "" << setw(45) << "Entrez votre choix: ";
	// afficher le menu ...
}

Commandes lireChoixMenu()
{ 
	Commandes cmd = Cmd::quitter;					// commande par d�faut
	bool valid = false;
	char dec;
	do {
		gotoxy(36,24);
		dec = toupper(_getch());
		switch (dec) {
		case '1':
			cmd = Cmd::ajouter;
			valid = true;
			break;
		case '2':
			cmd = Cmd::afficher;
			valid = true;
			break;
		case '3':
			cmd = Cmd::deposer;
			valid = true;
			break;
		case '4':
			cmd = Cmd::retrait;
			valid = true;
			break;
		case '5':
			cmd = Cmd::virement;
			valid = true;
			break;
		case '6':
			cmd = Cmd::list;
			valid = true;
			break;
		case '7':
			cmd = Cmd::supprimer;
			valid = true;
			break;
		case 'Q':
			cmd = Cmd::quitter;
			valid = true;
			break;
		default:
			valid = false;
			break;
		}
		if (valid == true) {
			cout << dec;
		}
	} while (valid == false);
	// lire la commande et la retourner � main ...

	return cmd;
}

/* ------------------------------------------------------------ */
/* LES FONCTIONS OBLIGATOIRES POUR CHAQUE COMMANDE DU PROGRAMME */
/* ------------------------------------------------------------ */

void cmd_ajouter(Banque& b /* Param�tre ? indice: cette fonction doit avoir acc�s � la variable b de main */ )
{
	system("CLS");
	cout << "CMD - ajouter un client\n\nCr�ation du client #" << (b.cpt + 1) << "\n\n";
	cout << left << setw(21) << "Pr�nom" << setw(2) << ": ";
	// �crire le code ici ...
}

void cmd_afficher( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_deposer( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_retirer( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_virer( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_lister( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_supprimer( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_quitter( /* Param�tres ? */)
{
	// �crire le code ici ...
}

/* ---------------------- */
/* LA FONCTION PRINCIPALE */
/* ---------------------- */

int main()
{
	setcp(1252);						// permet de faire un 'cout' avec les accents directement
	cout << fixed << setprecision(2);	// tous les montants sont affich�s avec une pr�cision � 2

	Cmd cmd = Cmd::inconnue;

	Banque& b = *new Banque;			// cr�ation dynamique d'une Banque. La vaiable b permet l'acc�s aux donn�es
										// ex:  cout << b.cpt;    ==> afficherait le nombre actuel de client
	do
	{
		afficherMenu();
		cmd = lireChoixMenu();
		
		switch (cmd)
		{
			case Cmd::ajouter: cmd_ajouter(b /* cette fonction doit avoir acc�s � la variable b de main */ ); break;
			case Cmd::afficher: cmd_afficher(); break;
			//...

			case Cmd::quitter: cmd_quitter(); break;
		}

	} while(cmd != Cmd::quitter);

	delete &b;
}