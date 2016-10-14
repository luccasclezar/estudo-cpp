// Estudo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main();

/*******************************Química Reconhecimento*******************************/

/**
	Retorna a resposta certa.

	@param rand	Número aleatório que para a definição da resposta.
	@return Resposta certa.
*/
string setChemistryUnderstandmentAnswer(int rand) {
	string answer = "";

	switch (rand) {
	case 1:
		answer = "hidrocarboneto";
		break;
	case 2:
		answer = "alcool";
		break;
	case 3:
		answer = "enol";
		break;
	case 4:
		answer = "aldeido";
		break;
	case 5:
		answer = "cetona";
		break;
	case 6:
		answer = "acidocarboxilico";
		break;
	case 7:
		answer = "eter";
		break;
	case 8:
		answer = "ester";
		break;
	case 9:
		answer = "fenol";
		break;
	case 10:
		answer = "haletoorganico";
		break;
	case 11:
		answer = "amina";
		break;
	case 12:
		answer = "amida";
		break;
	case 13:
		answer = "nitrila";
		break;
	case 14:
		answer = "nitrocomposto";
		break;
	default:
		cout << "Oops... bug";
	}

	return answer;
}

/**
	Define a pergunta.

	@param rand				Número aleatório que para a definição da pergunta.
	@param typeOfQuestion	Número definido pelo usuário para definição do tipo de pergunta.
*/
void setChemistryUnderstandmentQuestion(int rand, int typeOfQuestion) {
	string question = "";
	int randType;

	switch (typeOfQuestion) {
	case 1:
		randType = 1;
		break;
	case 2:
		randType = 2;
		break;
	case 3:
		random_device rd;
		uniform_int_distribution<int> dist(1, 2);
		randType = dist(rd);
		break;
	}

	switch (rand) {
	case 1:
		switch (randType) {
		case 1:
			question = "C - C - C";
			break;
		case 2:
			question = "somente carbonos na cadeia principal";
			break;
		}
		break;
	case 2:
		switch (randType) {
		case 1:
			question = "C - C - O";
			break;
		case 2:
			question = "hidroxila(OH) ligada a um carbono saturado";
			break;
		}
		break;
	case 3:
		switch (randType) {
		case 1:
			question = "O\n|\nC = C - C";
			break;
		case 2:
			question = "hidroxila(OH) ligada a carbono insaturado(ligacao dupla)";
			break;
		}
		break;
	case 4:
		switch (randType) {
		case 1:
			question = "C - C - C = O";
			break;
		case 2:
			question = "carbonila (C=O) na extremidade da cadeia";
			break;
		}
		break;
	case 5:
		switch (randType) {
		case 1:
			question = "C - CO - C";
			break;
		case 2:
			question = "carbonila(C=O) no interior da cadeia";
			break;
		}
		break;
	case 6:
		switch (randType) {
		case 1:
			question = "HOOC - C - C - C - C";
			break;
		case 2:
			question = "presenca do grupo funcional carboxila (COOH)";
			break;
		}
		break;
	case 7:
		switch (randType) {
		case 1:
			question = "C - C - O - C - C - C";
			break;
		case 2:
			question = "oxigenio como heteroatomo (entre radicais)";
			break;
		}
		break;
	case 8:
		switch (randType) {
		case 1:
			question = "C - COO - C - C";
			break;
		case 2:
			question = "caracterizada pelo grupo funcional carboxilato (- COO -)";
			break;
		}
		break;
	case 9:
		switch (randType) {
		case 1:
			question = "C6H5 - OH";
			break;
		case 2:
			question = "hidroxila ligada diretamente a um carbono que faz parte do anel aromatico";
			break;
		}
		break;
	case 10:
		switch (randType) {
		case 1:
			question = "Cl - C - C";
			break;
		case 2:
			question = "compostos resultantes da substituicao de um ou mais hidrogenios dos hidrocarbonetos por um ou mais halogenios";
			break;
		}
		break;
	case 11:
		switch (randType) {
		case 1:
			question = "C - C - N\n    |\n    C";
			break;
		case 2:
			question = "resultantes da substituicao dos hidrogenios do NH3 por radicais organicos";
			break;
		}
		break;
	case 12:
		switch (randType) {
		case 1:
			question = "C - C - CO - N";
			break;
		case 2:
			question = "compostos resultantes da substituicao de hidrogenios do NH3, por radicais acila (R - CO -)";
			break;
		}
		break;
	case 13:
		switch (randType) {
		case 1:
			question = "C - C - C -= N";
			break;
		case 2:
			question = "nitrogenio com ligacao tripla no final da cadeia";
			break;
		}
		break;
	case 14:
		switch (randType) {
		case 1:
			question = "C - C - C - NO";
			break;
		case 2:
			question = "NO2 no final da cadeia";
			break;
		}
		break;
	default:
		cout << "Oops... bug";
	}

	cout << question << endl;
}

/**
	Loop principal do reconhecimento de funções.

	@param typeOfQuestion Número definido pelo usuário para definição do tipo de questão.
*/
void chemistryUnderstandmentWorkflow(int typeOfQuestion) {
	random_device rd;
	uniform_int_distribution<int> dist(1, 14);

	int rand = dist(rd);
	string answer;
	string input;

	answer = setChemistryUnderstandmentAnswer(rand);
	setChemistryUnderstandmentQuestion(rand, typeOfQuestion);
	cin >> input;

	if (input == answer)
		cout << "Acertou!" << endl << endl;
	else {
		cout << "Errou... A resposta certa e \"" << answer << "\"" << endl << endl;
	}

	chemistryUnderstandmentWorkflow(typeOfQuestion);
}

/**
	Setup inicial para o reconhecimento de funções.
*/
void chemistryUnderstandmentInitialSetup() {
	cout << "Reconhecimento de funcoes organicas, escreva o nome da funcao sem acentos e em minusculo. \nDigite \"voltar\" para recomecar o programa." << endl;
	cout << "Escreva 1 para somente questoes estruturais, 2 para questoes teoricas ou 3 para os dois: ";
	int typeOfQuestion;
	cin >> typeOfQuestion;

	cout << endl;

	chemistryUnderstandmentWorkflow(typeOfQuestion);
}



/*******************************Química nomenclatura*******************************/

/**
	Retorna a resposta do exercício.

	@param randFunction Função orgânica aleatória.
	@param randExercise Seletor de três exercícios diferentes para cada função orgânica.
	@param randType		Seletor do tipo do exercício (Usual ou IUPAC).
*/
string chemistryNamesAnswer(int randFunction, int randExercise, int randType) {
	string answer;

	if (randType == 1)
		cout << "Nome Oficial" << endl;
	else
		cout << "Nome Usual" << endl;

	switch (randFunction) {
	case 1:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "propano";
				break;
			case 2:
				answer = "etano";
				break;
			case 3:
				answer = "1-buteno";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "etino";
				break;
			case 2:
				answer = "iso-propano";
				break;
			case 3:
				answer = "metano";
				break;
			}
		break;
	case 2:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "butanol";
				break;
			case 2:
				answer = "1-propanol";
				break;
			case 3:
				answer = "ciclobutanol";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "alcool-butilico";
				break;
			case 2:
				answer = "alcool-propilico";
				break;
			case 3:
				answer = "alcool-ciclobutilico";
				break;
			}
		break;
	case 3:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "etenol";
				break;
			case 2:
				answer = "prop-1-en-1-ol";
				break;
			case 3:
				answer = "but-2-en-2-ol";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "pent-2-en-3-ol";
				break;
			case 2:
				answer = "prop-1-en-2-ol";
				break;
			case 3:
				answer = "but-1-en-2-ol";
				break;
			}
		break;
	case 4:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "propanal";
				break;
			case 2:
				answer = "etanal";
				break;
			case 3:
				answer = "butanal";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "aldeido-propionico";
				break;
			case 2:
				answer = "aldeido-acetico";
				break;
			case 3:
				answer = "aldeido-butirico";
				break;
			}
		break;
	case 5:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "3-pentanona";
				break;
			case 2:
				answer = "butanona";
				break;
			case 3:
				answer = "propanona";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "dietil-cetona";
				break;
			case 2:
				answer = "etil-metil-cetona";
				break;
			case 3:
				answer = "dimetil-cetona";
				break;
			}
		break;
	case 6:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "acido-butanoico";
				break;
			case 2:
				answer = "acido-pentanoico";
				break;
			case 3:
				answer = "acido-propanoico";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "acido-butirico";
				break;
			case 2:
				answer = "acido-valerico";
				break;
			case 3:
				answer = "acido-propionico";
				break;
			}
		break;
	case 7:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "etoxi-propano";
				break;
			case 2:
				answer = "metoxi-etano";
				break;
			case 3:
				answer = "etoxi-butano";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "eter-etil-propilico";
				break;
			case 2:
				answer = "eter-metil-etilico";
				break;
			case 3:
				answer = "eter-etil-butirico";
				break;
			}
		break;
	case 8:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "propanoato-de-etila";
				break;
			case 2:
				answer = "butanoato-de-metila";
				break;
			case 3:
				answer = "metanoato-de-propila";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "propionato-de-etila";
				break;
			case 2:
				answer = "butirato-de-metila";
				break;
			case 3:
				answer = "formiato-de-propila";
				break;
			}
		break;
	case 9:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "1,2-hidroxi-propil-benzeno";
				break;
			case 2:
				answer = "1,3-hidroxi-butil-benzeno";
				break;
			case 3:
				answer = "b-hidroxi-naftaleno";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "o-propil-fenol";
				break;
			case 2:
				answer = "m-butil-fenol";
				break;
			case 3:
				answer = "b-naftol";
				break;
			}
		break;
	case 10:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "1-cloro-butano";
				break;
			case 2:
				answer = "2-iodo-butano";
				break;
			case 3:
				answer = "1-bromo-pentano";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "cloreto-de-butila";
				break;
			case 2:
				answer = "iodeto-de-s-butila";
				break;
			case 3:
				answer = "brometo-de-pentila";
				break;
			}
		break;
	case 11:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "metilamina";
				break;
			case 2:
				answer = "propilamina";
				break;
			case 3:
				answer = "butilamina";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "amino-metano";
				break;
			case 2:
				answer = "1-amino-propano";
				break;
			case 3:
				answer = "1-amino-butano";
				break;
			}
		break;
	case 12:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "etanamida";
				break;
			case 2:
				answer = "n-metil-propanamida";
				break;
			case 3:
				answer = "n-butil-propanamida";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "acetamida";
				break;
			case 2:
				answer = "n-metil-propionamida";
				break;
			case 3:
				answer = "n-butil-propanamida";
				break;
			}
		break;
	case 13:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "propano-nitrila";
				break;
			case 2:
				answer = "butano-nitrila";
				break;
			case 3:
				answer = "etano-nitrila";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "cianeto-de-propila";
				break;
			case 2:
				answer = "cianeto-de-butila";
				break;
			case 3:
				answer = "cianeto-de-etila";
				break;
			}
		break;
	case 14:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				answer = "1-nitro-propano";
				break;
			case 2:
				answer = "2-nitro-butano";
				break;
			case 3:
				answer = "nitro-etano";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				answer = "2-nitro-pentano";
				break;
			case 2:
				answer = "2-nitro-propano";
				break;
			case 3:
				answer = "1-nitro-butano";
				break;
			}
		break;
	default:
		cout << "Oops... bug";
	}

	return answer;
}

/**
	Setup para a nomenclatura de funções.

	@param randFunction Função orgânica aleatória.
	@param randExercise Seletor de três exercícios diferentes para cada função orgânica.
	@param randType		Seletor do tipo do exercício (Usual ou IUPAC).
*/
void chemistryNamesQuestion(int randFunction, int randExercise, int randType) {
	string question;

	switch (randFunction) {
	case 1:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				question = "C - C - C";
				break;
			case 2:
				question = "C - C";
				break;
			case 3:
				question = "C = C - C - C";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				question = "C -= C";
				break;
			case 2:
				question = "C - C\n|\nC";
				break;
			case 3:
				question = "C";
				break;
			}
		break;
	case 2:
		switch (randExercise) {
		case 1:
			question = "C - C - C - C - OH";
			break;
		case 2:
			question = "C - C - C - OH";
			break;
		case 3:
			question = "C - C\n|   |\nC - C - OH";
			break;
		}
		break;
	case 3:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				question = "OH - C = C";
				break;
			case 2:
				question = "OH - C = C - C";
				break;
			case 3:
				question = "    OH\n    |\nC - C = C - C";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				question = "C - C = C - C - C\n        |\n        OH";
				break;
			case 2:
				question = "C = C - C\n    |\n    OH";
				break;
			case 3:
				question = "C = C - C - C\n    |\n    OH";
				break;
			}
		break;
	case 4:
		switch (randExercise) {
		case 1:
			question = "C - C - CO";
			break;
		case 2:
			question = "C - CO";
			break;
		case 3:
			question = "C - C - C - CO";
			break;
		}
		break;
	case 5:
		switch (randExercise) {
		case 1:
			question = "C - C - CO - C - C";
			break;
		case 2:
			question = "C - CO - C - C";
			break;
		case 3:
			question = "C - CO - C";
			break;
		}
		break;
	case 6:
		switch (randExercise) {
		case 1:
			question = "C - C - C - COOH";
			break;
		case 2:
			question = "C - C - C - C - COOH";
			break;
		case 3:
			question = "C - C - COOH";
			break;
		}
		break;
	case 7:
		switch (randExercise) {
		case 1:
			question = "C - C - O - C - C - C";
			break;
		case 2:
			question = "C - C - O - C";
			break;
		case 3:
			question = "C - C - O - C - C - C - C";
			break;
		}
		break;
	case 8:
		switch (randExercise) {
		case 1:
			question = "C - C - COO - C - C";
			break;
		case 2:
			question = "C - C - C - COO - C";
			break;
		case 3:
			question = "COO - C - C - C";
			break;
		}
		break;
	case 9:
		switch (randExercise) {
		case 1:
			question = " ___\n/   \\_ OH\n\\   /\n ---\n    |\n    C - C - C";
			break;
		case 2:
			question = " ___ _ OH\n/   \\\n\\   /\n ---\n    |\n    C - C - C - C";
			break;
		case 3:
			question = "HO\n |\n ___\n/   \\\n\\   /\n ---\n/   \\\n\\   /\n ---";
			break;
		}
		break;
	case 10:
		switch (randExercise) {
		case 1:
			question = "Cl - C - C - C - C";
			break;
		case 2:
			question = "C - C (I) C - C";
			break;
		case 3:
			question = "Br - C - C - C - C - C";
			break;
		}
		break;
	case 11:
		switch (randExercise) {
		case 1:
			question = "C - N";
			break;
		case 2:
			question = "C - C - C - N";
			break;
		case 3:
			question = "C - C - C - C - N";
			break;
		}
		break;
	case 12:
		switch (randExercise) {
		case 1:
			question = "C - CON";
			break;
		case 2:
			question = "C - C - CON - C";
			break;
		case 3:
			question = "C - C - CON - C - C - C - C";
			break;
		}
		break;
	case 13:
		switch (randExercise) {
		case 1:
			question = "C - C - C -= N";
			break;
		case 2:
			question = "C - C - C - C -= N";
			break;
		case 3:
			question = "C - C -= N";
			break;
		}
		break;
	case 14:
		if (randType == 1)
			switch (randExercise) {
			case 1:
				question = "C - C - C - NO2";
				break;
			case 2:
				question = "C - C - C - C\n    |\n    NO2";
				break;
			case 3:
				question = "C - C - NO2";
				break;
			}
		else
			switch (randExercise) {
			case 1:
				question = "C - C - C - C - C\n    |\n    NO2";
				break;
			case 2:
				question = "C - C - C\n    |\n    NO2";
				break;
			case 3:
				question = "C - C - C - C - NO2";
				break;
			}
		break;
	default:
		cout << "Oops... bug";
	}

	cout << question << endl;
}

/**
	Loop principal da nomenclatura de funções.
*/
void chemistryNamesWorkflow() {
	random_device rd;
	uniform_int_distribution<int> functionDist(1, 14);
	uniform_int_distribution<int> exerciseDist(1, 3);
	uniform_int_distribution<int> typeDist(1, 2);

	int randFunction = functionDist(rd);
	int randExercise = exerciseDist(rd);
	int randType = typeDist(rd);
	string answer;
	string input;

	answer = chemistryNamesAnswer(randFunction, randExercise, randType);
	chemistryNamesQuestion(randFunction, randExercise, randType);
	cin >> input;

	if (input == answer)
		cout << "Acertou!" << endl << endl;
	else
		cout << "Errou... A resposta certa e \"" << answer << "\"" << endl << endl;

	chemistryNamesWorkflow();
}

/**
	Setup inicial para nomenclatura de funções.
*/
void chemistryNamesInitialSetup() {
	cout << "Troque todos os espacos por \"-\"" << endl;

	chemistryNamesWorkflow();
}

/********Main Loop********/
int main()
{
	system("color 3f");

	char charSubject[50];
	cout << "Digite \"reconhecimento-quimica\" para reconhecimento de funcoes ou \"nomenclatura-quimica\" para nomenclatura (sem acentos): ";
	cin.clear();
	cin.get(charSubject, 100);
	string subject(charSubject);

	if (subject == "reconhecimento-quimica")
		chemistryUnderstandmentInitialSetup();
	else if (subject == "nomenclatura-quimica")
		chemistryNamesInitialSetup();

	return 0;
}


