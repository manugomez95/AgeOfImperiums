#pragma once

#include "Utils.h"

// TODO cambiar
const string Utils::SILLY_NAMES[59] =
{		"Aitor Tilla ",
		"Zoyla Vaca ",
		"Ana Busado de Hesa ",
		"Eusebia Tetas Planas ",
		"Juanjo Sefina ",
		"Rafael Nieto de Dios ",
		"Zacarias Flores del Campo ",
		"Lola Mento ",
		"Luz Cuesta Mogollon ",
		"Luz Rojas ",
		"Armando Gavilan Vibora ",
		"Encarna Vales ",
		"Paca Garte ",
		"Juan Macho Seco ",
		"Karen Latada ",
		"Jesucristo Hitler Montoya Gonzalez ",
		"Ana Tomia ",
		"Helen Chufe ",
		"Susana Torio ",
		"Maria Luisa Brazo Dorado ",
		"Marcia Ana ",
		"Email Suarez Barboza ",
		"Armando Bronca Segura ",
		"Alberto Comino Grande ",
		"Matias Queroso ",
		"Valdomero a la Plancha ",
		"Igor Dito ",
		"Dolores Delano",
		"Jorge Nitales ",
		"Miguel Marco Gol ",
		"Elvia Raton Calvo ",
		"Antonio Bragueta Suelta ",
		"Batman Bin Suparman ",
		"Disney Landia Rodriguez Juarez ",
		"Elena Nito ",
		"Ramona Ponte Alegre ",
		"Ana Pulpillo Salido ",
		"Elsa Capunta ",
		"Oscar Acol ",
		"Ines Queleto ",
		"Blanca Nieve Bague ",
		"Julio Feo ",
		"Paul Vazo ",
		"Estela Gartija ",
		"Penelope Luda ",
		"Ruben Fermizo ",
		"Isaac A. Mocos ",
		"Juanca Daver ",
		"Alba Sura ",
		"Alex Cremento ",
		"Marta Tuada ",
		"Nicolas Queroso ",
		"Omar Icon ",
		"Josefa Natica ",
		"Vicente Levidente ",
		"Dolores Delano ",
		"Susana Torio ",
		"Vicente Rorifico ",
		"Victor Tilla " };

int Utils::randomRange(int start, int end) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> distrib(start, end);
	return int(distrib(rng));
}