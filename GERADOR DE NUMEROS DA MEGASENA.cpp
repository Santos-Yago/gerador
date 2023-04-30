#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

int main()
{
	std::random_device rd{};
	std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	std::mt19937 mt{ss};
	std::uniform_int_distribution<int> dist{1, 60};
	
	auto gerador{[&mt, &dist](){return dist(mt);}};
	
Refazer:
	std::vector<int> mega(6);
	
	std::generate(begin(mega), end(mega), gerador);
	
	//Ordena.
	std::sort(mega.begin(), mega.end());
	
	//Verifique se há numeros repetidos...
	auto ver = std::unique(mega.begin(), mega.end());
	//...e os trata.
	mega.erase(ver, mega.end());
	
	//Se houver menos elementos que o pretendido, refaz.
	if(mega.size() < std::size_t(6))
	{
		goto Refazer;
	}
	
	for(auto i: mega)
		std::cout << i << ' ';
	
	
	return 0;
}