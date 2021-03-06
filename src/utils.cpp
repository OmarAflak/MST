#include "../include/utils.h"

int toInt(std::string str){
	std::stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

bool readGraph(const char* filename, Graph& graph){
	std::ifstream file(filename);
	if(file){
		std::string line;

		getline(file, line);
		graph.order = toInt(line);
		getline(file, line);
		graph.degree = toInt(line);

		graph.vertices.resize(0);

		for(int i=0 ; i<graph.degree ; i++){
			getline(file, line);
			std::stringstream ss(line);

			Vertex vertex;
			ss >> vertex.node1;
			ss >> vertex.node2;
			ss >> vertex.weight;
			graph.vertices.push_back(vertex);
		}

		return true;
	}
	return false;
}

bool saveGraph(const char* filename, const Graph& graph){
	std::ofstream file(filename);
	if(file){
		file << graph.order << std::endl;
		file << graph.degree << std::endl;

		for(int i=0 ; i<graph.degree ; i++){
			file << graph.vertices[i].node1 << " ";
			file << graph.vertices[i].node2 << " ";
			file << graph.vertices[i].weight << std::endl;
		}

		return true;
	}
	return false;
}
