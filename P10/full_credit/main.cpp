#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>  // std::sort

int main(int argc, char* argv[]) {
	std::vector<std::thread*> t;
	std::mutex m;
	int processor_count = std::thread::hardware_concurrency();
	
	
    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }

    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    // ----- All data loaded -----
    // std::cout << (puzzles.size()/processor_count)<< " " << processor_count << std::endl;
    // Capture the solutions in a vector 
        
    std::vector<Solution> solutions;
    
    int per = puzzles.size()/processor_count;

    int e = 1;

	for(int i = 1; i<=processor_count;i++)
	{
    // Loop through all of the loaded puzzles
		for(int j = (per*e-per); j < (per*e); j++ ) {
		    // Find each word in the current puzzle
		    for(auto word : puzzles[j])
		    {
		        // Instance a Solver, and use it to solve for the word
		        Solver solver{puzzles[j]};
		        m.lock(); 
		        std::thread y{[&]{ Solution s = solver.solve(word); solutions.push_back(s); }};
		    m.unlock();
		    y.join();
		    }
		}
		e++;
	}

	 /*for(Puzzle& puzzle : puzzles) {

		    // Find each word in the current puzzle
		    for(std::string word : puzzle) {
		    
		        // Instance a Solver, and use it to solve for the word
		        Solver solver{puzzle};
		        Solution s = solver.solve(word);
		        solutions.push_back(s);
		    }
		}*/
		
		     
    for (auto th : t) th->join();
    
    
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
    
