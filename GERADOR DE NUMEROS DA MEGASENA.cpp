#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

int main()
{
	//Configura a geração de numeros aleatórios;
	std::random_device rd{};
	std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	std::mt19937 mt{ss};
	std::uniform_int_distribution<int> dist{1, 60};
	
	auto gerador{[&mt, &dist](){return dist(mt);}};
	
	//Cria uma matriz que armazena os 6 numeros;
	std::array<int, 6> nMega;
	
	//Gera os 6 numeros aleatórios;
	std::generate(nMega.begin(), nMega.end(), gerador);
		
	//Verifica duplicidade dentro da matriz;
	Refazer:
	for(unsigned int i{0}; i < nMega.size()-1; ++i)
	{	
		for(unsigned int j{i+1}; j < nMega.size(); ++j)
		{
			//Atribui um novo número, caso repetido;
			if(nMega[i] == nMega[j])
				nMega[j] = gerador();
			
			//Verifica se não se repetiu novamente;
			if(nMega[i] == nMega[j])
				goto Refazer;
		}
	}
	
	//Organiza;
	std::sort(nMega.begin(), nMega.end());
	
	//Imprime na tela;
	for(auto const& i: nMega)
		std::cout << i << ' ';
	
	return 0;
}
